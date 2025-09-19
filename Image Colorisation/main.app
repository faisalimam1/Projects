import cv2 
import numpy as np
import matplotlib.pyplot as plt

# Load the pre-trained model and cluster centers
print("Loading model...")
prototxt = "colorization_deploy_v2.prototxt"
model = "colorization_release_v2.caffemodel"
points = "pts_in_hull.npy"

net = cv2.dnn.readNetFromCaffe(prototxt, model)
pts = np.load(points)

# Add cluster centers as a layer
pts = pts.transpose().reshape(2, 313, 1, 1)
net.getLayer(net.getLayerId('class8_ab')).blobs = [pts.astype('float32')]
net.getLayer(net.getLayerId('conv8_313_rh')).blobs = [np.full([1, 313], 2.606, dtype="float32")]

# Load the input image
print("Processing image...")
input_image = "input_image.jpg"
image = cv2.imread(input_image)
scaled = image.astype("float32") / 255.0
lab = cv2.cvtColor(scaled, cv2.COLOR_BGR2LAB)

# Resize the image to 224x224 (required by the model)
resized = cv2.resize(lab, (224, 224))
L = cv2.split(resized)[0]  # Extract L channel (grayscale)
L -= 50  # Normalize

# Predict the ab channels
net.setInput(cv2.dnn.blobFromImage(L))
ab = net.forward()[0, :, :, :].transpose((1, 2, 0))

# Resize the ab channels to match the original image size
ab = cv2.resize(ab, (image.shape[1], image.shape[0]))

# Combine the original L channel with the predicted ab channels
L = cv2.split(lab)[0]
colorized = np.concatenate((L[:, :, np.newaxis], ab), axis=2)

# Convert LAB image back to BGR
colorized = cv2.cvtColor(colorized, cv2.COLOR_LAB2BGR)
colorized = np.clip(colorized, 0, 1)

# Convert to 8-bit format and save the output
colorized = (255 * colorized).astype("uint8")
cv2.imwrite("output_image.jpg", colorized)

# Display the results
print("Displaying results...")
original = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
output = cv2.cvtColor(colorized, cv2.COLOR_BGR2RGB)

plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)
plt.imshow(original)
plt.title("Grayscale Image")
plt.axis("off")

plt.subplot(1, 2, 2)
plt.imshow(output)
plt.title("Colorized Image")
plt.axis("off")
plt.show()
 
