#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"

class Library
{
    private:
        std::vector<Book> books;
        
    public:
        Library(std::vector<Book> booksVec);
        ~Library();
        
        //Task 2
        void showLoanedOn(std::string givenDate);
        
        //Task 1
        void showAvailableBooks();
        
        //Task 3
        void saveInfoInFile (const std::string &fileName);

};

#endif // LIBRARY_H
