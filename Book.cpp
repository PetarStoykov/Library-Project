#include "Book.h"

using namespace std;

//Constructor
Book::Book(string title, vector<string> auth, bool avail, string date) 
    : title{title}, authors{auth}, available{avail}, date{date} {};


Book::~Book()
{
}

//Get methods
string Book::getDate() const {
    return date;
}

string Book::getTitle() const {
    return title;
}

bool Book::getAvailable() const {
    return available;
}

vector<string> Book::getAuthors() const {
    return authors;
}

// overloading << operator
ostream &operator<<(ostream &os, const Book &book){
    os << boolalpha;
    os << "Title: " << book.title << endl;
    os << "Author(s): ";
    for(const auto &author : book.authors){
        os << author;
        os << ", "; 
    }
    os << endl;
    os << "Availability: " << book.available << endl;
    os << "Loan Date: " << book.date << endl;
    return os;
}

