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
  // Was Libs in main.cpp the library name?????
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
  for (int i = 0; i < MAX; i++) {
    if (listOfBooks[i] == BookName) {
      return true;
    }
  }
}

// return the valid index if book is in library or -1 if book is not in library
// using numberOfBooks because array may be partially filled
int findBook(const string& name) const { 
  bool isFound = false; 
  int result = -1;
  int searchIndex = 0;

  // If bag is empty, numberOfBooks is zero, so loop is skipped
  while (!isFound && (searchIndex < numberOfBooks)) {
    // what is name though in this case?
    isFound = (listOfBooks[searchIndex] == name); 
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
bool Library::addBook(const string &BookName) {
  if (!Libs::isInLibrary(BookName) && (numberOfBooks < MAX-1)) {
    listOfBooks[numberOfBooks + 1] = BookName;
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
  // can I even use isEmpty??
  bool canRemoveBook = !isEmpty() && (locatedBook > -1);
  if (canRemoveBook) {
    numberOfBooks--;
    listOfBooks[locatedBook] = listOfBooks[numberOfBooks];
  }
  return canRemoveBook;;
}

// list all books
void Library::listAllBooks() const {
  for (int i = numberOfBooks - 1; i > -1; i--) {
    cout << listOfBooks[i];
  }
}

ostream &operator<<(ostream &Out, const Library &Lib) {
  return Out;
}