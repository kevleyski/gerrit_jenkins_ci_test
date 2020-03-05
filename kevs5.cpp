#include <iostream>
#include <stddef.h> // cstddef.h?

using namespace std;

// GCC only - __attribute__ ((packed))
struct kevs {
  const char* foo;
  int bar;
  const char* foz;
  unsigned int bit1 : 1;
  unsigned int bit2 : 1;
  unsigned int bit3 : 1;
  unsigned int bit4 : 1;
  int baz;
  int boz;
};

struct kevs instance {
  .bar = 42,
  .baz = INT_MAX,
  .foo = "hi",
};

int main_5() {
  printf("%s %i\n", instance.foo, instance.bar);
  cout << "foo=" << offsetof(kevs, foo) << endl;
  cout << "bar=" << offsetof(kevs, bar) << endl;
  cout << "foz=" << offsetof(kevs, foz) << endl;
  cout << "baz=" << offsetof(kevs, baz) << endl;
  cout << "boz=" << offsetof(kevs, boz) << endl;
  cout << "boz=" << offsetof(kevs, boz) << endl;
}

