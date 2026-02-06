#include "Library.h"
#include <cassert>
#include <iostream>

int main() {
    Library lib;

    lib.addBook(Book(1, "1984", "George Orwell"));
    lib.addBook(Book(2, "Dune", "Frank Herbert"));

    lib.registerUser(User(1, "Steve"));

    // Positive cases
    assert(lib.borrowBook(1, 1) == true);
    assert(lib.returnBook(1, 1) == true);

    // Negative cases
    assert(lib.borrowBook(1, 99) == false); // book doesn't exist
    assert(lib.borrowBook(99, 1) == false); // user doesn't exist
    assert(lib.returnBook(1, 2) == false);  // returning unborrowed book

    // Borrow twice
    assert(lib.borrowBook(1, 2) == true);
    assert(lib.borrowBook(1, 2) == false);

    std::cout << "All tests passed successfully.\n";
    return 0;
}
