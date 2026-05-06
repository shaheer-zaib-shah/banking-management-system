# banking-management-system
This is a console-based Banking Management System developed during my first semester of Computer Science. The project serves as a practical implementation of fundamental programming concepts, focusing on procedural programming, file handling, and control structures in C++.

The application simulates a real-world banking experience, allowing users to create accounts, manage balances, and perform various financial transactions through a secure login portal.

Key Features
Account Management: Users can create new accounts or log into existing ones.
Persistent Storage: Uses File I/O (fstream) to store user credentials and transaction history in Login.txt.
Financial Operations: * Deposit and Withdraw (with tax logic).
Standard and "Special" transactions.
Utility bill payments and University fee submission.
Benevolence Fund: Features for Zakat deduction and Charity.
Security Simulations: Includes a basic "Privacy & Policy" portal and simulated payment verification delays using <chrono> and <thread>.
User Interface: Utilizes ANSI escape codes for a colored and intuitive terminal-based UI.

Technical Implementation
Language: C++

Key Libraries: * <fstream> for persistent data storage.
<windows.h> and <thread> for system-level interactions and delays.
<iostream> and <string> for input/output handling.

Concepts Used: Functions, Pass-by-Reference, File Handling, Conditional Logic, and Input Validation.
