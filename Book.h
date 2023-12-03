#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book
{
    //Operator << overloading
    friend ostream &operator<<(ostream &os, const Book &book);
    
private:
    string title;
    vector<string> authors;
    bool available;
    string date;
public:
    Book(string title, vector<string> auth, bool avail, string date);
    ~Book();
    
    //Get methods
    string getDate() const;
    string getTitle() const;
    bool getAvailable() const;
    vector<string> getAuthors() const;

};

#endif // BOOK_H
