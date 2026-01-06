# Simple Password Manager (C++)

Console-based password manager written in C++.

This application allows users to store, check, and retrieve website passwords using the local file system.

## Features
- Add website name and password
- Hidden password input (masked with `*`)
- Check if website credentials already exist
- Retrieve saved passwords by website name
- Data stored using folders and text files
- Menu-based console interface

## Technologies Used
- C++
- `<filesystem>` for folder and file management
- `<fstream>` for reading and writing password files
- `<conio.h>` for masked password input
- Control structures (loops, functions, conditionals)

## How It Works
1. User chooses an option from the menu:
   - Check if a website password exists
   - Add a new website and password
2. Each website is stored in its own folder
3. Passwords are saved in text files
4. When searching, the program scans all saved files
5. Password input is hidden for security

## Folder Structure Example
