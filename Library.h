#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"

using namespace std;

class Library
{
    private:
        vector<Book> books;
        
    public:
        Library(vector<Book> booksVec);
        ~Library();
        
        //Task 2
        void showLoanedOn(string givenDate);
        
        //Task 1
        void showAvailableBooks();
        
        //Task 3
        void saveInfoInFile (const string &fileName);

};

#endif // LIBRARY_H
