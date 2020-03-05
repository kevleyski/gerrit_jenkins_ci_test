// Binary search pointers
// This is kevs code BTW

#include <stddef.h>
#include <stdio.h>

int bsearch(int* array, int* left, int* right, int lookfor) {
  int* pivot = left + ((right - left) >> 1);

  if ((right < left) || (left > right)) {
    return -1;  // not in array
  }

  if (lookfor == *pivot)
    return (pivot - array);
  else if (lookfor > *pivot)
    return bsearch(array, pivot + 1, right, lookfor);
  return bsearch(array, left, pivot - 1, lookfor);
}

int main_8(int arc, char* argv[]) {

  // search in
  int array[] = { 1, 2, 3, 4, 10, 22, 77, 922, 1024 };
  int lookfor = 1024;
  int len = sizeof(array) / sizeof(array[0]);
  int* array_sentinel = array + len - 1;
  int idx = bsearch((int*)array, (int*)array, array_sentinel, lookfor);

  printf("idx=%d\n", idx);
}
