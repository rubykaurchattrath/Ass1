//
// Created by Ruby Kaur on 03/30/2023.

// Library class demonstrating partially filled arrays
// Can add/remove books from library
// findbooks in library


#include "library.h"
#include <iostream>
#include <string>

// constructor with default name
// Class::Constructor
Library::Library(const string &defaultName) {
  libraryName = defaultName;
  numberOfBooks = 0; 
}

// destructor
// nothing on heap
Library::~Library() {
  // destructor
}

// true if book found in library
// false if book is NOT found in library
bool Library::isInLibrary(const string &bookName) const {
  if (findBook(bookName) == -1){
    return false;
  } else {
    return true;
  }
}

// return the valid index if book is in library or -1 if book is not in library
// using numberOfBooks because array may be partially filled
int Library::findBook(const string& bookName) const { 
  bool isFound = false; 
  int result = -1;
  int searchIndex = 0;

  // If bag is empty, numberOfBooks is zero, so loop is skipped
  while (!isFound && (searchIndex < numberOfBooks)) {
    isFound = (listOfBooks[searchIndex] == bookName); 
    if (isFound) {
      result = searchIndex;
    } else {
      searchIndex++;
    }
  }
  return result;
}

// add a new book
// return true if successful, false if
// book already in library and/or if library is full
bool Library::addBook(const string &bookName) {
  if (!Library::isInLibrary(bookName) && (numberOfBooks < MAX)) {
    numberOfBooks++;
    listOfBooks[numberOfBooks] = bookName;
    return true;
  } else {
    return false;
  }
}

// remove a book
// return true if successfully removed
// false if book not in library
bool Library::removeBook(const string &bookName) {
  int locatedBook = findBook(bookName);
  if (locatedBook != -1) {
    numberOfBooks--;
    listOfBooks[locatedBook] = listOfBooks[numberOfBooks];
    return true;
  } else {
    return false;
  }
}

// list all books
void Library::listAllBooks() const {
  if (numberOfBooks == 0) {
    cout << "No books" << endl;
  } else {
    for (int i = numberOfBooks - 1; i >= 0; i--) {
    cout << listOfBooks[i] << endl;
    } 
  }
}

// display all books in library
ostream &operator<<(ostream &Out, const Library &Lib) {
  Lib.listAllBooks();
  return Out ;
}

