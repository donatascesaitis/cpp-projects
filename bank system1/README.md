# ATM / Bank System (C++)

Console-based ATM simulation written in C++.

This project simulates a simple bank ATM system with card authentication, password verification, and basic banking operations.

## Features
- Card number verification
- Hidden password input (masked with `*`)
- Limited login attempts (card blocking after 3 tries)
- Check account balance
- Deposit money
- Withdraw money
- Balance stored using file I/O

## Technologies Used
- C++
- `<fstream>` for saving balance to file
- `<conio.h>` for hidden password input
- Basic control flow (loops, switch-case)

## How It Works
1. User enters a card number
2. System checks if the card exists
3. User enters password (hidden input)
4. After successful login, user can:
   - Check balance
   - Deposit money
   - Withdraw money
   - Exit the system
5. Balance is saved in a text file (`balance.txt`)

## Notes
- This project is for learning purposes
- Data is stored locally in files (no encryption)
- Designed as a beginner-level C++ console application

## Author
Created while learning C++ fundamentals
