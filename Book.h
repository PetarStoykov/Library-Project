#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <vector>
#include <string>

class Book
{
    //Operator << overloading
    friend std::ostream &operator<<(std::ostream &os, const Book &book);
    
private:
    std::string title;
    std::vector<std::string> authors;
    bool available;
    std::string date;
public:
    Book(std::string title, std::vector<std::string> auth, bool avail, std::string date);
    ~Book();
    
    //Get methods
    std::string getDate() const;
    std::string getTitle() const;
    bool getAvailable() const;
    std::vector<std::string> getAuthors() const;

};

#endif // BOOK_H
