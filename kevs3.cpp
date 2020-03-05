// Hash map C++

#include <iostream>
#include <map>

using namespace std;

int main_3() {
  map<int, string> kevs;
  kevs.insert(pair<int, string>(5, "erk"));
  kevs.insert(pair<int, string>(20, "flip"));
  kevs.insert(pair<int, string>(2, "two"));
  kevs.insert(pair<int, string>(1, "one"));

  auto it = kevs.begin();
  for (; it != kevs.end(); it++) {
    cout << it->first << " - " << it->second << endl;
  }

  cout << kevs[20] << endl;

  cout << kevs[2] << endl;
}
