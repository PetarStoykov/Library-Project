#include "Book.h"
#include "Library.h"

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    // To show true and false instead of 1 and 0
    cout << boolalpha;

    // Adding authors
    vector<string> auths1;
    auths1.push_back("Robert Greene");
    auths1.push_back("Test");
    vector<string> auths2;
    auths2.push_back("Alex Willman");
    vector<string> auths3;
    auths3.push_back("Victor Ugo");
    auths3.push_back("Peter Griffin");

    // Creating books
    Book book1("Titanic", auths1, true, "02.01.2002");
    Book book2("Ice Age", auths2, true, "02.01.2002");
    Book book3("Something for Title", auths3, true, "20.12.2000");

    // Testing the overloaded operator - <<
    cout << book1 << endl;

    // Adding books to a vector
    vector<Book> books;
    books.push_back(book1);
    books.push_back(book2);
    books.push_back(book3);

    // Creating a library
    Library lib1(1, books);

    // Demo for 2nd task to show the titles of books loaned on a certain date:
    lib1.showLoanedOn("02.01.2002");

    // Demo for 1nd task to show info about available books sorted by authors:
    lib1.showAvailableBooks();

    // Demo for 3rd task to save books with more than one author information into a file:
    // string file = "D:/Workspaces/University/LibraryProject/books_info.txt";
    // lib1.saveInfoInFile(file);

    return 0;
}