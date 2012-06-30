#include <iostream>
#include <vector>
using namespace std;
// 有n个数，他们的范围是[0, n^2-1]，如何排序最快

// 将这些数看成是n进制，个位是 x % n 十位: x/n
// 进行两遍计数排序

int units_key(int number, int base) {
  return number % base;
}

int tens_key(int number, int base) {
  return number / base;
}

typedef int (*GetKey)(int, int);

void CountSort(int array[], int n, GetKey key_fun) {
  std::vector<vector<int> > counts(n, vector<int>(0,0));
  for (int i = 0; i < n; i++) {
    int key = key_fun(array[i], n);
    counts[key].push_back(array[i]);
  }

  int pos = 0;
  for (int i = 0; i < counts.size(); i++) {
    for (int j = 0; j < counts[i].size(); j++) {
      array[pos] = counts[i][j];
      pos++;
    }
  }
}

void Sort(int array[], int n) {
  CountSort(array, n, units_key);
  CountSort(array, n, tens_key);
}


int main() {
  int array[] = {3, 0, 7, 11};
  Sort(array, 4);
  for (int i = 0; i < 4; ++i) {
    cout << array[i] << endl;
  }

}
