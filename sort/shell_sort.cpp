// shell_sort.cpp
// Starting with far apart elements can move some out-of-place elements into
// position faster than a simple nearest neighbor exchange.
// The running time of Shellsort is heavily dependent on the gap sequence it
// uses.

#include <iostream>
using namespace std;

int gaps[8] = {701, 301, 132, 57, 23, 10, 4, 1};

void display(int* arr) {
  for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void shell_sort(int* arr, int from, int to) {
  for (int g = 0; g < 8; g++) {
    int gap = gaps[g];
    int i, j;
    for (i = gap; i <= to; i++) {
      int x = arr[i];
      // insert sort for diffenert gap
      for (j = i; j >= gap && arr[j - gap] > x && j >= from; j -= gap) {
        arr[j] = arr[j - gap];
      }
      arr[j] = x;
    }
    cout << "after" << gap << "-sorting ";
    display(arr);
  }
}

int main(int argc, char const* argv[]) {
  int a[10] = {1, 4, 5, 2, 9, 7, 8, 0, 3, 6};
  display(a);
  shell_sort(a, 5, 9);
  return 0;
}
