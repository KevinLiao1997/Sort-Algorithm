// merge_sort.cpp
// I don't know if this is a kind of merge sort, but it's really fast.
// Details can be viewd on my github homepage.

#include <iostream>
using namespace std;

void display(int* arr) {
  for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void merge_sort(int* arr, int from, int to) {
  int slow = from;
  int fast = slow + 1;
  while (fast != to + 1) {
    if (arr[fast] > arr[slow]) {
      slow++;
      fast++;
    } else {
      int pre = from;
      while (arr[pre] <= arr[fast]) pre++;
      int temp = arr[fast];
      arr[fast] = arr[pre];
      arr[pre] = temp;
    }
    fast = slow + 1;
  }
}

int main(int argc, char const* argv[]) {
  int a[10] = {1, 4, 5, 2, 9, 7, 8, 0, 3, 6};
  display(a);
  merge_sort(a, 0, 9);
  display(a);
  return 0;
}
