#include <iostream>
#include <map>

using namespace std;

int main() {
  map<int, string> kevs;
  kevs.insert(pair<int, string>(5, "erk"));
  kevs.insert(pair<int, string>(20, "flip"));

  auto it = kevs.begin();
  for (; it != kevs.end(); it++) {
    cout << it->first << endl;
  }
}
