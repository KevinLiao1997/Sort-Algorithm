// insert_sort.cpp
// Time complexity ranges from O(n) to O(n*n)

#include <iostream>
using namespace std;

void display(int* arr) {
  for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void insert_sort_slow(int* arr, int from, int to) {
  /* The outer loop runs over all the elements except the first one, because the
   * single-element prefix A[0:1] is trivially sorted, so the invariant that the
   * first i+1 entries are sorted is true from the start. */
  /* The inner loop moves element A[i] to its correct place so that after the
   * loop, the first i+2 elements are sorted.*/
  for (int i = from + 1; i <= to; i++) {
    for (int j = i; j > from; j--) {
      if (arr[j] < arr[j - 1]) {
        int temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
      }
    }
  }
}

void insert_sort_fast(int* arr, int from, int to) {
  /* The new inner loop shifts elements to the right to clear a spot for x =
   * A[i].*/
  int i, j;
  for (i = from + 1; i <= to; i++) {
    int x = arr[i];
    for (j = i - 1; j >= from && arr[j] > x; j--) {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = x;
  }
}

int main(int argc, char const* argv[]) {
  int a[10] = {1, 4, 5, 2, 9, 7, 8, 0, 3, 6};
  int b[10] = {1, 4, 5, 2, 9, 7, 8, 0, 3, 6};
  insert_sort_slow(a, 0, 9);
  cout << "version slow:";
  display(a);
  insert_sort_fast(b, 0, 9);
  cout << "version fast:";
  display(b);
  return 0;
}
