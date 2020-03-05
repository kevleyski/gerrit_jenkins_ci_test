#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
  if (r >= l) {
    int mid = l + (r - l) / 2;

    if (arr[mid] == x)
      return mid;

    if (x > arr[mid])
      return binarySearch(arr, mid + 1, r, x);

    return binarySearch(arr, l, mid - 1, x);
  }

  return -1; // not in array
}

int main_7(void)
{
  int arr[] = { 1, 2, 3, 4, 10, 11, 14, 15, 20, 22, 40, 52, 66, 70, 73, 74, 75 };
  int n = sizeof(arr) / sizeof(arr[0]);
  int lookfor = 74;
  int result = binarySearch(arr, 0, n - 1, lookfor);
  printf("index=%d", result);
  return 0;
} 