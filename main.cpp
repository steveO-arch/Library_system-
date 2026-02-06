#include "Library.h"
#include <iostream>

int main() {
    Library library;
    int choice;

    while (true) {
        std::cout << "\n===== Library Management System =====\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Register User\n";
        std::cout << "3. Borrow Book\n";
        std::cout << "4. Return Book\n";
        std::cout << "5. Search Book by Title\n";
        std::cout << "6. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            int id;
            std::string title, author;

            std::cin.ignore();
            std::cout << "Book ID: ";
            std::cin >> id;
            std::cin.ignore();

            std::cout << "Title: ";
            getline(std::cin, title);

            std::cout << "Author: ";
            getline(std::cin, author);

            library.addBook(Book(id, title, author));
            std::cout << "Book added successfully.\n";
        }

        else if (choice == 2) {
            int id;
            std::string name;

            std::cout << "User ID: ";
            std::cin >> id;
            std::cin.ignore();

            std::cout << "Name: ";
            getline(std::cin, name);

            library.registerUser(User(id, name));
            std::cout << "User registered successfully.\n";
        }

        else if (choice == 3) {
            int userId, bookId;
            std::cout << "User ID: ";
            std::cin >> userId;
            std::cout << "Book ID: ";
            std::cin >> bookId;

            if (library.borrowBook(userId, bookId))
                std::cout << "Book borrowed successfully.\n";
            else
                std::cout << "Borrowing failed.\n";
        }

        else if (choice == 4) {
            int userId, bookId;
            std::cout << "User ID: ";
            std::cin >> userId;
            std::cout << "Book ID: ";
            std::cin >> bookId;

            if (library.returnBook(userId, bookId))
                std::cout << "Book returned successfully.\n";
            else
                std::cout << "Return failed.\n";
        }

        else if (choice == 5) {
            std::string keyword;
            std::cin.ignore();
            std::cout << "Enter title keyword: ";
            getline(std::cin, keyword);

            library.searchByTitle(keyword);
        }

        else if (choice == 6) {
            std::cout << "Goodbye.\n";
            break;
        }

        else {
            std::cout << "Invalid option.\n";
        }
    }

    return 0;
}
