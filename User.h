#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
private:
    int userId;
    std::string name;
    std::vector<int> borrowedBooks;

public:
    User(int id, const std::string& name)
        : userId(id), name(name) {}

    int getId() const { return userId; }
    std::string getName() const { return name; }

    void borrowBook(int bookId) {
        borrowedBooks.push_back(bookId);
    }

    bool returnBook(int bookId) {
        for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
            if (*it == bookId) {
                borrowedBooks.erase(it);
                return true;
            }
        }
        return false;
    }

    bool hasBook(int bookId) const {
        for (int id : borrowedBooks) {
            if (id == bookId) return true;
        }
        return false;
    }
};

#endif
