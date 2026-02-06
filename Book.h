#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    bool isBorrowed;

public:
    Book(int id, const std::string& title, const std::string& author)
        : id(id), title(title), author(author), isBorrowed(false) {}

    int getId() const { return id; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    bool borrowed() const { return isBorrowed; }

    bool borrow() {
        if (isBorrowed) return false;
        isBorrowed = true;
        return true;
    }

    bool giveBack() {
        if (!isBorrowed) return false;
        isBorrowed = false;
        return true;
    }
};

#endif
