# Custom Virtual File System (VFS) with In-Memory Caching

## 📌 Project Overview

This project implements a simple custom Virtual File System (VFS) in C.  
It supports basic file operations like **create**, **read**, **write**, and **delete**.  
It uses a fixed-size memory buffer to simulate file storage, and includes in-memory caching for fast access.

---

## 🎯 Features

- Create virtual files
- Write and read from virtual files
- Delete files
- Simulated storage with metadata management
- In-memory caching for fast access
- Command-line interface

---

## 🛠️ Tech Stack

- Language: **C**
- Platform: **Linux (Ubuntu)** inside **VMware**
- Editor: Gedit / VS Code (inside VM)
- Compiler: `gcc`

---

## 📁 Project Structure

custom_vfs/
├── src/ # C source files
│ └── main.c
├── include/ # Header files
│ └── vfs.h
├── data/ # VFS memory file (to simulate persistent storage)
├── README.md # Project documentation


---

## 🚀 How to Compile and Run

1. Open terminal in the project root folder
2. Run:
   ```bash
   gcc src/main.c -o vfs
   ./vfs
   
👨‍💻 Author
Faisal Imam,
Computer Science Engineer
