#include "Library.h"
#include <fstream>
#include <algorithm>

using namespace std;

//Constructor
Library::Library(vector<Book> booksVec) : books{booksVec} {};

Library::~Library()
{
}

//Gives info about all the books that were loaned on the givenDate
void Library::showLoanedOn(string givenDate){
    cout << "Books loaned on: " << givenDate << " : " << endl;
    for(auto book : books){
        if(givenDate == book.getDate()){
            cout << book.getTitle() << endl;
        }
    }
    cout << endl;
}

//A function that compares alphabetically the primary authors of two given books.
bool compareByPrimaryAuthor(const Book &book1, const Book &book2){
    return book1.getAuthors().at(0) < book2.getAuthors().at(0);
}

//Gives info about all available books sorted by the authors' names.
void Library::showAvailableBooks(){
    vector<Book> filteredBooks;
    for(const auto &book : books){
        if(book.getAvailable()){
            filteredBooks.push_back(book);
        }
    }
    sort(filteredBooks.begin(), filteredBooks.end(), compareByPrimaryAuthor);
    
    cout << "Information on available books (sorted by author):" << endl;

    for(const auto &book : filteredBooks){
        cout << book << endl;
    };
}

//Saves info about books that have more than one author into a file.    
void Library::saveInfoInFile(const string &fileName){
    
    ofstream outputFile;
    outputFile.open(fileName);
    
    if(!outputFile.is_open()){
        cerr << "Error opening file or creating file: " << fileName << endl;
        return;
    }
    
    outputFile << "Information for books with more than one author:\n" << endl;
    
    for(const auto &book : books){
        if(book.getAuthors().size() > 1){
            outputFile << book << endl;
        }
    }
    
    outputFile.close();
}


