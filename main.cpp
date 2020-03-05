// Various C++ STL worked examples

#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Foo {

 protected:
  int a;
  int b;

 public:
  Foo() {
    a = 1;
    b = 3;
  }

  virtual ~Foo() {
    a = 0;
  }

  int sum() {
    return a + b;
  }
};

#define SIZE 50000

int kevs_hash(int key) {
  int r = key % SIZE;
  return r < 0 ? r + SIZE : r;
}

void insert(int *keys, int *values, int key, int value) {
  int index = kevs_hash(key);
  while (values[index]) {
    index = (index + 1) % SIZE;
  }
  keys[index] = key;
  values[index] = value;
}

int search(int *keys, int *values, int key) {
  int index = kevs_hash(key);
  while (values[index]) {
    if (keys[index] == key) {
      return values[index];
    }
    index = (index + 1) % SIZE;
  }
  return 0;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  *returnSize = 2;
  int keys[SIZE];
  int values[SIZE] = {0};
  for (int i = 0; i < numsSize; i++) {
    int complements = target - nums[i];
    int value = search(keys, values, complements);
    if (value) {
      int *indices = (int *) malloc(sizeof(int) * 2);
      indices[0] = value - 1;
      indices[1] = i;
      return indices;
    }
    insert(keys, values, nums[i], i + 1);
  }
  return NULL;
}

// These will be used later
struct Person {
  string name;
  int age;
} p1, p2, p3;

struct is_older {
  bool operator()(struct Person p1, struct Person p2) {
    return p1.age > p2.age;
  }
};

bool compare_names(struct Person p1, struct Person p2) {
  return p1.name < p2.name;
}

bool way_to_sort(int i, int j) {

  return i > j;

}

class vectorClass {

  // arr is the integer pointer
  // which stores the address of our vector
  int *arr;

  // capacity is the total storage
  // capacity of the vector
  int capacity;

  // current is the number of elements
  // currently present in the vector
  int current;

 public:
  // Default constructor to initialise
  // an initial capacity of 1 element and
  // allocating storage using dynamic allocation
  vectorClass() {
    arr = new int[1];
    capacity = 1;
    current = 0;
  }

  // Function to add an element at the last
  void push(int data) {

    // if the number of elements is equal to the capacity,
    // that means we don't have space
    // to accommodate more elements.
    // We need to double the capacity
    if (current == capacity) {
      int *temp = new int[2 * capacity];

      // copying old array elements to new array
      for (int i = 0; i < capacity; i++) {
        temp[i] = arr[i];
      }

      // deleting previous array
      delete[] arr;
      capacity *= 2;
      arr = temp;
    }

    // Inserting data
    arr[current] = data;
    current++;
  }

  // function to add element at any index
  void push(int data, int index) {

    // if index is equal to capacity then this
    // function is same as push defined above
    if (index == capacity)
      push(data);
    else
      arr[index] = data;
  }

  // function to extract element at any index
  int get(int index) {

    // if index is within the range
    if (index < current)
      return arr[index];
  }

  // function to delete last element
  void pop() {
    current--;
  }

  // function to get size of the vector
  int size() {
    return current;
  }

  // function to get capacity of the vector
  int getcapacity() {
    return capacity;
  }

  // function to print array elements
  void print() {
    for (int i = 0; i < current; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

// Driver code
int main_vector() {
  vectorClass v;
  v.push(10);
  v.push(20);
  v.push(30);
  v.push(40);
  v.push(50);

  cout << "Vector size : "
       << v.size() << endl;
  cout << "Vector capacity : "
       << v.getcapacity() << endl;

  cout << "Vector elements : ";
  v.print();

  v.push(100, 1);

  cout << "\nAfter updating 1st index"
       << endl;

  cout << "Vector elements : ";
  v.print();

  cout << "Element at 1st index : "
       << v.get(1) << endl;

  v.pop();

  cout << "\nAfter deleting last element"
       << endl;

  cout << "Vector size : "
       << v.size() << endl;
  cout << "Vector capacity : "
       << v.getcapacity() << endl;

  cout << "Vector elements : ";
  v.print();

  return 0;
}


// KJSL Worked example
// (1 ^ 2 ^ 3 ^ 5 ^ 6) ^ (1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6) = 4 (4 was missing)
//
// XOR range (1..6)
// 1  0001
// ^2 0010 = 0011 = 3
// ^3        0011 = 0000 (0)
// ^4               0100 = 0100 (4)
// ^5                      0101 = 0001 (1)
// ^6                             0110 = 0111 (7)

// XOR input array
// 1  0001
// ^2 0010 = 0011 = 3
// ^3        0011 = 0000 (0)
// (skipped) ^4
// ^5               0101 = 0101 (5)
// ^6                      0110 = 0011 (3)

// Then XOR two results 0011
//                      0111 = 0100 = 4 (qed)

int getMissingNo(int a[], int n) {
  // For xor of all the elements in array
  int x1 = a[0];

  // For xor of all the elements from 1 to n+1
  int x2 = 1;

  for (int i = 1; i < n; i++)
    x1 = x1 ^ a[i];

  for (int i = 2; i <= n + 1; i++)
    x2 = x2 ^ i;

  return (x1 ^ x2);
}

// Driver Code
int main_missing() {
  int arr[] = {1, 2, 4, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  int miss = getMissingNo(arr, n);
  cout << miss;
}

/* Standard Binary Search function*/
int binarySearch2(int arr[], int low,
                 int high, int key) {
  if (high < low)
    return -1;

  int mid = (low + high) / 2; /*low + (high - low)/2;*/
  if (key == arr[mid])
    return mid;

  if (key > arr[mid])
    return binarySearch2(arr, (mid + 1), high, key);

  // else
  return binarySearch2(arr, low, (mid - 1), key);
}

void set_bit(int &num, int pos) {
  // First step is shift '1', second
  // step is bitwise OR
  num |= (1 << pos);
}

void clear_bit(int &num, int pos) {
  // Second step is to bitwise and this number with given number
  num &= (~(1 << pos));
}

void toggle_bit(int &num, int pos) {
  num ^= (1 << pos);
}

bool bit_at_position(int num, int pos) {
  bool bit = num & (1 << pos);
  return bit;
}

int main2() {

  Foo *foo = new Foo();

  int nums[] = {2, 3, 9, 10};
  int retSize = 2;
  int *ret = twoSum(nums, sizeof(nums), 12, &retSize);
  if (ret) {
    cout << "twoSum=" << ret[0] << "&" << ret[1];
    free(ret);
  }

  cout << "Hello, World! twoSum=" << foo->sum();

  delete foo;


  /*
  ========
   STACK
  ========
  */

  stack<string> distros; //Create a stack of strings.

  distros.push("Ubuntu");  //Pushing elements into the stack.
  distros.push("Mint");
  distros.emplace("Erk");

  cout << "Number of distros in the stack are " << distros.size() << endl;
  cout << "Distro on the top is " << distros.top() << endl;

  distros.pop();
  cout << "The top of the stack is now " << distros.top() << endl;

  stack<string> flip; //Create a stack of strings.
  flip.push("Flop");  //Pushing elements into the stack.

  distros.swap(flip);

  cout << "The top of the distros stack is now " << distros.top() << endl;
  cout << "The top of the flip stack is now " << distros.top() << endl;

  distros.empty();
  flip.empty();

  /*
  ========
   VECTOR
  ========
  */

  vector<int> numbers;

  if (numbers.empty()) { //check if the vector is empty?
    cout << "The vector is empty :(" << endl;
  }

  for (int i = 0; i < 100; i += 10) { //Add some values to the vector
    numbers.push_back(i);
  }

  cout << "Size of the vector is " << numbers.size() << endl;

  // iterating over the vector, declaring the iterator
  vector<int>::iterator it;

  cout << "The vector contains: ";
  for (it = numbers.begin(); it != numbers.end(); it++) {
    cout << "  " << *it;
  }

  // getting value at particular position
  int position = 5;
  cout << "\nVector at position " << position << " contains " << numbers.at(position) << endl;

  // deleting an element at position
  numbers.erase(numbers.begin() + position);
  cout << "Vector at position " << position << " contains " << numbers.at(position) << endl;

  // deleting a range of elements, first two elements
  // NOTE: You may expect elements at 0, 1 and 2 to be deleted
  // but index 2 is not inclusive.
  numbers.erase(numbers.begin(), numbers.begin() + 2);
  cout << "The vector contains: ";
  for (it = numbers.begin(); it != numbers.end(); it++) {
    cout << "  " << *it;
  }

  cout << endl << "Max size" << numbers.max_size() << endl;

  // Clearing the vector
  numbers.clear();
  if (numbers.empty()) {
    cout << "\nThe vector is now empty again :(";
  }


  /*
  =========
   HASHMAP
  =========
  */

  // Declaration <key type, value type>
  map<string, string> companies;

  companies["Google"] = "Larry Page";
  companies["Facebook"] = "Mark Zuckerberg";

  // insertion can also be done as
  companies.insert(pair<string, string>("Xarvis Tech", "xarvis"));
  // or
  companies.insert(map<string, string>::value_type("Quora", "Adam D'Angelo"));
  // or even
  companies.insert(make_pair(string("Uber"), string("Travis Kalanick")));

  // Iterating the map
  map<string, string>::iterator itz;
  cout << "\n\nCompanies and founders" << endl;
  for (itz = companies.begin(); itz != companies.end(); itz++) {
    cout << "Company: " << (*itz).first << "\t Founder: " << itz->second << endl;
  }

  itz = companies.find("Google");
  cout << itz->second;

  /* Check if key exists!

  if ( m.find("f") == m.end() ) {
        // not found
  } else {
       // found
  }
  */


  /*
  ==============
  LINKED LISTS
  ==============
  */
  list<int> mylist;
  list<int>::iterator it1, it2, itx;

  // set some values:
  for (int i = 1; i < 10; ++i) mylist.push_back(10 * i);

  // 10 20 30 40 50 60 70 80 90
  it1 = it2 = mylist.begin(); // ^^
  advance(it2, 6);            // ^                 ^
  ++it1;                      //    ^              ^

  it1 = mylist.erase(it1);   // 10 30 40 50 60 70 80 90
  //    ^           ^

  it2 = mylist.erase(it2);   // 10 30 40 50 60 80 90
  //    ^           ^

  ++it1;                      //       ^        ^
  --it2;                      //       ^     ^

  mylist.erase(it1, it2);     // 10 30 60 80 90

  cout << "\nmylist contains:";
  for (itx = mylist.begin(); itx != mylist.end(); ++itx)
    cout << ' ' << *itx;
  cout << endl;

  // NOTE: it1 still points to 40, and 60 is not deleted
  cout << endl << *it1 << "\t" << *it2 << endl;

  // This will print an unexpected value
  it1++;
//  cout << *it1;

  cout << "\nmylist now contains:";
  for (it1 = mylist.begin(); it1 != mylist.end(); ++it1)
    cout << ' ' << *it1;
  cout << endl;

  cout << "\nKJSL: mylist in reverse:";
  list<int>::reverse_iterator kev1;
  for (kev1 = mylist.rbegin(); kev1 != mylist.rend(); ++kev1)
    cout << ' ' << *kev1;
  cout << endl;

  /*
  =======
  HEAPS
  =======
  */

  // Creates a max heap
  priority_queue<int> pq;

  // To create a min heap instead, just uncomment the below line
  // priority_queue <int, vector<int>, greater<int> > pq;

  pq.push(5);
  pq.push(1);
  pq.push(10);
  pq.push(30);
  pq.push(20);

  // Extracting items from the heap
  while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }


  // creating heap from user defined objects
  // Let's initialize the properties of `Person` object first
  p1.name = "Linus Torvalds";
  p1.age = 47;

  p2.name = "Elon Musk";
  p2.age = 46;

  p3.name = "Me!";
  p3.age = 19;

  // Initialize a min heap
  // Note: We defined a comparator is_older in the beginning to
  // compare the ages of two person.
  priority_queue<struct Person, vector<struct Person>, is_older> mh;
  mh.push(p1);
  mh.push(p2);
  mh.push(p3);

  // Extracting items from the heap
  while (!mh.empty()) {
    struct Person p = mh.top();
    cout << p.name << " ";
    mh.pop();
  }

  /*
  =========
  SORTING
  =========
  */

  // The following list type initialization is only supported after C++11
  //vector<int> int_vec = {56, 32, -43, 23, 12, 93, 132, -154};

  // If the above style of initialization doesn't work, use the following one
  static int arr[] = {56, 32, -43, 23, 12, 93, 132, -154};
  int arr_len = sizeof(arr) / sizeof(arr[0]);
  vector<int> int_vec(arr, arr + arr_len);

  cout << endl;
  // Default: sort ascending
  // sort(int_vec.begin(), int_vec.end());
  // To sort in descending order:
  // Do not include the () when you call wayToSort
  // It must be passed as a function pointer or function object
  sort(int_vec.begin(), int_vec.end(), way_to_sort);
  for (vector<int>::iterator i = int_vec.begin(); i != int_vec.end(); i++)
    cout << *i << " ";
  cout << endl;

  // sorting the array
  sort(arr, arr + arr_len);
  for (int i = 0; i < arr_len; i++) {
    cout << arr[i] << " ";
  }

  // Sorting user-defined objects
  static struct Person persons[] = {p1, p2, p3};
  sort(persons, persons + 3, compare_names);

  // This will printout the names in alphabetical order
  for (int i = 0; i < 3; i++) {
    cout << persons[i].name << " ";
  }

  main_vector();

  main_missing();

  return 0;
}
