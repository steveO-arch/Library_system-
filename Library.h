#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "User.h"
#include <vector>
#include <iostream>

class Library {
private:
    std::vector<Book> books;
    std::vector<User> users;

    Book* findBookById(int id) {
        for (auto& book : books)
            if (book.getId() == id) return &book;
        return nullptr;
    }

    User* findUserById(int id) {
        for (auto& user : users)
            if (user.getId() == id) return &user;
        return nullptr;
    }

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void removeBook(int id) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getId() == id) {
                books.erase(it);
                return;
            }
        }
    }

    void registerUser(const User& user) {
        users.push_back(user);
    }

    bool borrowBook(int userId, int bookId) {
        User* user = findUserById(userId);
        Book* book = findBookById(bookId);

        if (!user || !book) return false;
        if (!book->borrow()) return false;

        user->borrowBook(bookId);
        return true;
    }

    bool returnBook(int userId, int bookId) {
        User* user = findUserById(userId);
        Book* book = findBookById(bookId);

        if (!user || !book) return false;
        if (!user->hasBook(bookId)) return false;

        book->giveBack();
        return user->returnBook(bookId);
    }

    void searchByTitle(const std::string& keyword) const {
        for (const auto& book : books) {
            if (book.getTitle().find(keyword) != std::string::npos) {
                std::cout << book.getTitle() << " by " << book.getAuthor() << "\n";
            }
        }
    }
};

#endif
