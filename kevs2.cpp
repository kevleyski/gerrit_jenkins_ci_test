#include <iostream>
#include <list>

using namespace std;

int main_2() {
  list<int> foo = { 6,2, 35, 43, 9 };

  list<int>::iterator it;

  for (it = foo.begin(); it != foo.end(); it++) {
    cout << *it << endl;
  }

  // sort
  foo.sort();

  for (it = foo.begin(); it != foo.end(); it++) {
    cout << *it << endl;
  }


}
