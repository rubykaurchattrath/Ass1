//
// Created by Ruby Kaur on 03/30/2023.
//
// Library class demonstrating partially filled arrays
// Can add/remove books from library
// findbooks in library


#include "library.h"
#include <iostream>

// constructor with default name
// Class::Constructor
Library::Library(const string &Name) {
  // Was Libs in main.cpp the library name
  Libs = Name;
}

// LEAVE AS IS  
// destructor
// nothing on heap
Library::~Library() {
  // destructor
}

// true if book found in library
bool Library::isInLibrary(const string &BookName) const {
  // Where is BookName found?
  for (int i = 0; i < MAX; i++) {
    if (listOfBooks[i] == BookName) {
      return true;
    }
  }
}

// return the valid index if book is in library or -1 if book is not in library
// using numberOfBooks because array may be partially filled
int findBook(const string& BookName) const { 
  // if there are no books in library, then return -1
  if (numberOfBooks == 0) {
    return -1;
  } else {
    // perform iterations until element is found in array
    // return index
    for (int i = 0; i < numberOfBooks; i++) {
      if (listOfBooks[i] == BookName; i++) {
        return i; 
      }
    }
    return -1; // why would i still need to return -1 though?
  }
}

// add a new book
// return true if successful, false if
// book already in library
bool Library::addBook(const string &BookName) {

}

// remove a book
// return true if successfully removed
// false if book not in library
bool Library::removeBook(const string &BookName) {
  return false;
}

// list all books
void Library::listAllBooks() const {
}

ostream &operator<<(ostream &Out, const Library &Lib) {
  return Out;
}