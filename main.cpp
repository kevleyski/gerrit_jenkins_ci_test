#include <iostream>

using namespace std;

class Foo {

 protected:
  int a;
  int b;

 public:
  Foo() {
    a = 1;
    b = 2;
  }

  virtual ~Foo() {
    a = 0;
  }

  int sum() {
    return a + b;
  }
};

int main() {
  Foo* foo = new Foo();

  cout << "Hello, World!" << foo->sum();

  delete foo;
}


