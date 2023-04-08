// Created by Yusuf Pisan on 3/26/18.
// Ruby Kaur, CSS 342 B Spring 2023

#ifndef ASS1_LIBRARY_H
#define ASS1_LIBRARY_H

#include <string>

// Only for class code, OK to use namespace
using namespace std;

// Library holds books - can add, remove and list books
class Library {
  // display all books in library
  friend ostream &operator<<(ostream &Out, const Library &Lib);

public:
  // constructor with default name
  explicit Library(const string &DefaultName);
  //no arg consructor
  Library();

  // destructor
  virtual ~Library();

  // add a new book
  // return true if successful, false if
  // book already in library and/or library is full
  bool addBook(const string &BookName);

  // remove a book
  // return true if successfully removed
  // false if book not in library
  bool removeBook(const string &BookName);

  // list all books
  void listAllBooks() const;

  // true if book found in library
  bool isInLibrary(const string &BookName) const;

  // get MAX
  int getMax() const;

private:
  static const int MAX = 100; //max number of books
  int numberOfBooks; 
  string listOfBooks[MAX]; //partially filled book array
  string libraryName;
  
  // return the valid index if book is in library or -1 if book is not in library 
  int findBook(const string& BookName) const; 
};

#endif  // ASS1_LIBRARY_H

