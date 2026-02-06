Library System
An Online Library Management System built with Object-Oriented Programming (C++).

This project demonstrates OOP concepts in a real-world scenario — managing books, users, and the borrowing/returning process. It enforces rules automatically to keep library data consistent.

Introduction
The system models a library by handling books and users.
Users can borrow and return books, while the library ensures consistency (no double borrowing, no invalid returns).

The main goal: show how encapsulation, abstraction, modularity, and composition can be applied in C++ to build clean, maintainable, and testable code.

System Design
The project is built around three core classes:

1. Book
Stores book details (ID, title, author)

Tracks whether it’s borrowed

Handles borrow/return operations itself

2. User
Stores user info (ID, name)

Keeps track of borrowed books

Manages its own borrowing records

3. Library
Holds collections of books and users

Registers users, adds/removes books

Coordinates borrowing/returning

Provides search functionality

Design choice:  
The library acts as a mediator, ensuring rules are followed (e.g., no borrowing the same book twice).

OOP Principles in Action
Encapsulation - private data, public methods

Abstraction - simple user-facing operations (borrow, return, search)

Modularity - each class has one clear job

Composition - Library contains Book and User objects

No inheritance - kept things simple

File Structure
Code
library_system/
│
├── Book.h        
├── User.h         
├── Library.h      
├── main.cpp        
└── test_library.cpp
Features
Add/remove books

Register users

Search books by title

Borrow/return books (with validation)

Prevent invalid operations like:

Borrowing non-existent books

Borrowing already borrowed books

Returning books not borrowed by the user

Test Suite
test_library.cpp covers both positive and negative scenarios:

Successful borrow/return

Valid user-book interactions

Borrowing non-existent books

Invalid user IDs

Returning books not borrowed

Borrowing the same book twice

Tests use assert to automatically check correctness.
If everything is working:  All tests passed successfully.
How to Run
Compile & Run Main Program
-- g++ main.cpp -o library
./library
Compile & Run Tests
--g++ test_library.cpp -o test_library
./test_library
