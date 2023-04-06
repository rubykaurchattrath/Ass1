#include "library.h"

#include <cassert>
#include <iostream>


using namespace std;

void test1() {
  Library Libs("UWB"); 
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
/*
void test2() {

}

void test3() {

}

void test4() {

}
*/
void testAll() {
  test1();
  //test2();
  //test3();
  //test4();
  cout << "Successfully completed all tests." << endl;
}

int main() {
  testAll();
  return 0;
}