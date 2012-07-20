// This algorithm is very difficult.
// It's really hard to write a corret algorithm
#include <iostream>
#include <cassert>
using namespace std;

// use uninvarint expression
// array[left] < x
// array[right] >= x
int LowerBound1(int array[], int n, int x) {
  int left = -1;
  int right = n;
  while (left + 1 != right) {
    int m = (left + right) / 2;
    if (array[m] < x) {
      // array[left] < x
      left = m;
    } else {
      // array[right] >= x
      right = m;
    }
  }
  return right;
}

// 下面的做法等价于方法1
// 下卖弄的left相当于算法1中的left+1
// 循环不变式 解空间时[0-n] --> [left -> right]
int LowerBound2(int array[], int n, int x) {
  int left = 0;
  int right = n;
  while (left < right) {
    int m = (left + right) / 2;
    if (array[m] < x) {
      // 第一个可以插入的位置
      // a[left - 1] < v
      // a[left-right] >= v
      left = m + 1;
    } else {
      // a[right] >= v
      right = m;
    }
  }
  assert(left == right);
  return array[right];
}

int UpperBound1(int array[], int n, int x) {
  int left = -1;
  int right = n;
  // a[left] <= x
  // a[right] > x
  while (left + 1 ！= right) {
    int m = (left + right) / 2;
    if (array[m] < x) {
      right = m;
    } else {
      left = m;
    }
  }
  return right;
}

int UpperBound(int array[], int n, int x) {
  int left = 0;
  int right = n;
  while (left < right) {
    int m = (left + right) / 2;
    if (array[m] < x) {
      right = m;
    } else {
      left = m + 1;
    }
  }
  return right;
}

int main(int argc, char *argv[]) {
  
  return 0;
}
