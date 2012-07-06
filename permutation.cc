#include <iostream>
using namespace std;

template <class T>
void Swap(T* a, T* b) {
  T t = *a;
  *a = *b;
  *b = t;
}

void Permutation(int array[], int begin, int last) {
  if (begin == last) {
    for (int i = 0; i < last; i++) {
      cout << array[i] << " ";
    }
    cout << endl;
  }
  
  for (int i = begin; i < last; i++) {
    Swap(&array[i], &array[begin]);
    Permutation(array, begin + 1, last);
  }
}

#define arraysize(a) (sizeof(a) / sizeof(a[0]))

int main(int argc, char *argv[]) {
  int array[] = {1, 2, 3, 4, 5};
  Permutation(array, 0, arraysize(array));
  return 0;
}
