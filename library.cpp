//
// Created by Ruby Kaur on 03/30/2023.

// Library class demonstrating partially filled arrays
// Can add/remove books from library
// findbooks in library


#include "library.h"
#include <iostream>
#include <string>

// constructor with default Name
// Class::Constructor
Library::Library(const string &DefaultName) {
  libraryName = DefaultName;
  numberOfBooks = 0; 
}

// no arg constructor, if library name is blank
Library::Library() {
  libraryName = "";
  numberOfBooks = 0;
}

// get MAX
  int Library::getMax() const {
    return MAX;
  }

// destructor
// nothing on heap
Library::~Library() {
  // destructor
}

// true if book found in library, false if not
bool Library::isInLibrary(const string &BookName) const {
  if (findBook(BookName) == -1){
    return false;
  } else {
    return true;
  }
}

// return the valid index if book is in library or -1 if book is not in library
// using numberOfBooks because array may be partially filled
int Library::findBook(const string& BookName) const { 
  for (int i = (numberOfBooks - 1); i > -1; i--) {
    if (listOfBooks[i] == BookName) {
      return i;
    }
  }
  return -1;
}

// add a new book
// return true if successful, false if
// book already in library and/or if library is full
bool Library::addBook(const string &BookName) {
  if ((isInLibrary(BookName) == false) && (numberOfBooks < MAX)) {
    listOfBooks[numberOfBooks] = BookName;
    numberOfBooks++;
    return true;
  } else {
    return false;
  }
}

// remove a book
// return true if successfully removed
// false if book not in library
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

// list all books
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

// display all books in library
ostream &operator<<(ostream &Out, const Library &Lib) {
  Lib.listAllBooks();
  return Out;
}
