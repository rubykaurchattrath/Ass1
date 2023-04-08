// @file library.cpp
// @purpose: Library class demonstrating partially filled arrays
// Can add/remove books from library
// findbooks in library
// @author: Ruby Kaur
/// CSS 342 Spring 2023

#include "library.h"
#include <iostream>
#include <string>

// Purpose: constructor of Library class with default Name
// Pre-conditions: DefaultName is a string.
// Post-conditions: Library object is created with given DefaultName, 
// and numberOfBooks is initialized to 0.
Library::Library(const string &DefaultName) {
  libraryName = DefaultName;
  numberOfBooks = 0; 
}

// Purpose: Constructs an instance of the 
// Library class with an empty name.
// Pre-conditions: None.
// Post-conditions: The Library object is created with an empty name 
// and numberOfBooks is initialized to 0.
Library::Library() {
  libraryName = "";
  numberOfBooks = 0;
}

// Purpose: Retrieves the max numberOfBooks that can be stored in the library.
// Pre-conditions: None.
// Post-conditions: Returns an integer representing 
// the max NumberOfBooks that can be stored in the library.
int Library::getMax() const {
    return MAX;
}

// destructor
// nothing on heap
Library::~Library() {
  // destructor
}

// Purpose: Determines if a given book is in the library.
// Pre-conditions: BookName is a string.
// Post-conditions: Returns true if the book is in the library
// false otherwise
bool Library::isInLibrary(const string &BookName) const {
  if (findBook(BookName) == -1){
    return false;
  } else {
    return true;
  }
}

// Purpose: Finds the index of a given book in listOfBooks.
// Pre-conditions: BookName is a string.
// Post-conditions: Returns the index of the book in listOfBooks
// or -1 if the book is not in the library.
int Library::findBook(const string& BookName) const { 
  for (int i = (numberOfBooks - 1); i > -1; i--) {
    if (listOfBooks[i] == BookName) {
      return i;
    }
  }
  return -1;
}

// Purpose: Adds a book to the library.
// Pre-conditions: BookName is a string.
// Post-conditions: If the book is not already in the library 
// and the library is not full, 
// the book is added to the library and true is returned. 
// else false is returned
bool Library::addBook(const string &BookName) {
  if ((isInLibrary(BookName) == false) && (numberOfBooks < MAX)) {
    listOfBooks[numberOfBooks] = BookName;
    numberOfBooks++;
    return true;
  } else {
    return false;
  }
}

// Purpose: Removes a book from the library.
// Pre-conditions: BookName is a string.
// Post-conditions: If the book is in the library, 
// it is removed and true is returned. 
// Otherwise, false is returned.
bool Library::removeBook(const string &BookName) {
  int locatedBook = findBook(BookName);
  if (locatedBook != -1) {
    numberOfBooks--;
    listOfBooks[locatedBook] = listOfBooks[numberOfBooks];
    return true;
  } else {
    return false;
  }
}

// Purpose: Lists all the books in the library.
// Pre-conditions: None.
// Post-conditions: Outputs all the books in the library.
void Library::listAllBooks() const {
  if (numberOfBooks == 0) {
    cout << "No books in the " << libraryName << " library." << endl;
  } else {
     cout << "The books available in the " << libraryName << " library are:" << endl;
    for (int i = numberOfBooks - 1; i >= 0; i--) {
    cout << listOfBooks[i] << endl;
    } 
  }
}

// Purpose: Overloads the << operator for the Library class.
// Pre-conditions: Out is an output stream, 
// and Lib is a reference to a Library object.
// Post-conditions: Outputs all the books in the library 
// using the listAllBooks method, 
// and returns the output stream.
ostream &operator<<(ostream &Out, const Library &Lib) {
  Lib.listAllBooks();
  return Out;
}
