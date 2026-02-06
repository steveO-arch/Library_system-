# Library_system
library system

Online Library Management System

Using Object-Oriented Programming (C++)

1. Introduction

This project implements an Online Library Management System using Object-Oriented Programming (OOP) principles in C++. The system models a real-world library by managing books and users, allowing users to borrow and return books while maintaining the integrity of library data.

The goal of the project is to demonstrate practical understanding of OOP concepts such as encapsulation, abstraction, and modular design, while producing readable, maintainable, and testable code.

2. System Design and OOP Principles
2.1 Class Overview

The system is composed of three main classes:

1. Book

Represents a single book in the library.

Responsibilities

Store book details (ID, title, author)

Track whether the book is currently borrowed

Allow borrowing and returning operations

Why this design?
A book should manage its own state. External classes should not directly modify whether a book is borrowed.

2. User

Represents a library user.

Responsibilities

Store user information (ID and name)

Track books borrowed by the user

Allow borrowing and returning of books by ID

Why this design?
Users should be responsible for their own borrowing records. This avoids tight coupling with the library’s internal data structures.

3. Library

Acts as the central controller of the system.

Responsibilities

Store collections of books and users

Register users and add/remove books

Coordinate borrowing and returning actions

Provide book search functionality

Why this design?
The library acts as a mediator between users and books, ensuring rules are enforced consistently (e.g., a book cannot be borrowed twice).

2.2 OOP Principles Applied

Encapsulation
All class data members are private and accessed only through public methods.

Abstraction
Users of the system interact with high-level operations (borrow, return, search) without knowing internal storage details.

Modularity
Each class has a single, well-defined responsibility.

Composition
The Library class contains collections of Book and User objects.

Inheritance was intentionally not used, as it would not add meaningful value for this problem.

3. File Structure
library_system/
│
├── Book.h        
├── User.h         
├── Library.h      
├── main.cpp        
└── test_library.cpp

4. Functionalities Implemented

Add and remove books from the library

Register users

Search for books by title

Borrow books (with validation)

Return books (with validation)

Prevent invalid operations such as:

Borrowing a non-existent book

Borrowing an already borrowed book

Returning a book not borrowed by the user

5. Test Suite Description

A dedicated test file (test_library.cpp) is provided to validate system behavior.

Test Coverage

Positive Scenarios

Successful book borrowing

Successful book returning

Valid user and book interactions

Negative Scenarios

Borrowing a non-existent book

Borrowing with an invalid user ID

Returning a book that was not borrowed

Attempting to borrow the same book twice

Assertions (assert) are used to automatically verify correctness.

6. Compilation and Execution Instructions
6.1 Compile and Run the Main Program
g++ main.cpp -o library
./library


This runs a simple demonstration of the system’s functionality.

6.2 Compile and Run the Test Suite
g++ test_library.cpp -o test_library
./test_library


If all tests pass, the program will output:

All tests passed successfully.


Any failure will terminate the program, indicating an error in logic.
