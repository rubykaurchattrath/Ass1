#include "library.h"
#include <cassert>
#include <iostream>

using namespace std;

void test1() {
  Library Libs("Test1"); 
  Libs.addBook("Don Quixote");
  Libs.addBook("In Search of Lost Time");
  Libs.addBook("Ulysses");
  Libs.addBook("The Odyssey");
  Libs.listAllBooks();
  // should generate already in library message and return true
  bool Result = Libs.isInLibrary("The Odyssey");
  assert(Result);

  // cannot add book twice, result should be false
  Result = Libs.addBook("The Odyssey");
  assert(!Result);

  // test remove, result should be true
  Result = Libs.removeBook("The Odyssey");
  assert(Result);

  // not in library, result should be false
  Result = Libs.isInLibrary("The Odyssey");
  assert(!Result);

  // cannot remove twice, result should be false
  Result = Libs.removeBook("The Odyssey");
  assert(!Result);
}

void test2() {
  Library Libs("Test2"); 

  // test adding Max number of books
  for (int i = 0; i < Libs.getMax(); i++) {
    string bookName = "Book " + to_string(i);
    bool Result = Libs.addBook(bookName);
    assert(Result);
    assert(Libs.isInLibrary(bookName));
  }

  // test adding book to full library, should return false
  bool Result = Libs.addBook("Extra Book");
  assert(!Result);
  
  // testing operator method
  cout << Libs << endl;
}

void test3() {
  // test no arg constructor
  Library Libs;

  // test if empty library returns "No Books"
  Libs.listAllBooks();

  Libs.addBook("ABC");
  Libs.addBook("DEF");
  Libs.listAllBooks();
  // should generate already in library message and return true
  bool Result = Libs.isInLibrary("ABC");
  assert(Result);

  // cannot add book twice, result should be false
  Result = Libs.addBook("ABC");
  assert(!Result);

  // test remove, result should be true
  Result = Libs.removeBook("ABC");
  assert(Result);

  // not in library, result should be false
  Result = Libs.isInLibrary("ABC");
  assert(!Result);

  // cannot remove twice, result should be false
  Result = Libs.removeBook("ABC");
  assert(!Result);
}

void testAll() {
  test1();
  test2();
  test3();
  cout << "Successfully completed all tests." << endl;
}

int main() {
  testAll();
  return 0;
}
