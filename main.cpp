#include "Book.h"
#include "Library.h"
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const string DEFAULT_FILE_PATH = "D:/Workspaces/University/LibraryProject/books_info.txt";

//Function prototypes
char takeSelection();
void displayMenu();
void selectionHandler(char selection, Library lib);

int main(){

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
    Book book3("Something for Title", auths3, true, "20.12.2007");

    // Testing the overloaded operator - <<
    cout << book1 << endl;

    // Adding books to a vector
    vector<Book> books;
    books.push_back(book1);
    books.push_back(book2);
    books.push_back(book3);

    // Creating a library
    Library lib1(books);

    char selection{};

    //User-Menu that will loop until the user quits
    do{
        //Displaying the options
        displayMenu();

        //Taking the user's selection
        selection = takeSelection();

        //Launching the appropriate functions from the user's choice
        selectionHandler(selection, lib1);
    } while(selection != 'Q');
    
    return 0;
}

//Simply displaying the options to the user in the console
void displayMenu(){
    cout << "\nGet info on books loaned on a given date - D" << endl;
    cout << "Get info on available books sorted by authors - A" << endl;
    cout << "Save info about books that have more than one author on a file - F" << endl;
    cout << "Quit - Q" << endl;
    cout << "\nEnter your choice (D,A,F): ";
}

//Used to get the user's choice
char takeSelection(){
    char selection{};
    
    cin >> selection;

    //Used this to remove the newline char after reading selection from the buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    return (char)toupper(selection);
}

//Handles what to do with the selection
void selectionHandler(char selection, Library lib){
    if(selection == 'D'){
        string date;
        cout << "Enter a date in this format (dd.mm.yyyy): ";
        cin >> date;

        lib.showLoanedOn(date);
    }else if(selection == 'A'){
        lib.showAvailableBooks();
    }else if(selection == 'F'){
        string file;

        //Get file path from the user and save it into the string 'file'
        //A quick file_path to test the functionality - D:/Workspaces/University/LibraryProject/books_info_TEST.txt
        cout << "Please enter a file path (you can press ENTER and choose the DEFAULT): ";
        getline(cin, file);

        //Checks if a new path is set if not sets the DEFAULT
        if(file.empty()){
            file = DEFAULT_FILE_PATH;
        }

        lib.saveInfoInFile(file);
    }else if(selection == 'Q'){
        cout << "Goodbye!" << endl;
    }else{
        cout << "Incorrect choice please try again using D, A, F or Q." << endl;
    }
}