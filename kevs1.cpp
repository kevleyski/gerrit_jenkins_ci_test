// Vector C++

#include <iostream>
#include <vector>

using namespace std;

int main_1() {
  cout << "basic" << endl;

  vector<int> array = {8, 2, 3, 1, 9};

//  for (int i = 0; i < array.size(); i++) {
//    cout << array[i] << endl;

// Using range instead

  for (int i : array) {
    cout << i << endl;
  }

  auto it = array.begin();

  for (; it < array.end(); it++) {
    cout << *it << endl;
  }
}
