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
  RubysLibrary = Name;
}

// LEAVE AS IS  
// destructor
// nothing on heap
Library::~Library() {
  // destructor
}

// true if book found in library
bool Library::isInLibrary(const string &BookName) const {
  return true;
}

// add a new book
// return true if successful, false if
// book already in library
// incredment the loop up???
bool Library::addBook(const string &BookName) {
  return false;
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