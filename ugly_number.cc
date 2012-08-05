#include "common.h"
using namespace std;

// Method1 use priority queue

// Method2
// 相当于有3个队列； 每次得到一个数就需要往3个队列中
// 各插一次，而且这个队列是完全一样的因此可以使用一个
// 队列 3个指针
const int MAX_POS = 1500;

int Min(int a, int b, int c) {
  int min;
  min = a < b ? a : b;
  min = min < c ? min : c;
  return min;
}

int main() {
  int ugly[MAX_POS];
  ugly[0] = 1;
  int p2, p3, p5;
  p2 = p3 = p5 = 0;
  for (int i = 1; i < MAX_POS; i++) {
    int value2 = ugly[p2] * 2;
    int value3 = ugly[p3] * 3;
    int value5 = ugly[p5] * 5;

    ugly[i] = Min(value2, value3, value5);
    if (ugly[i] == value2) p2++;
    if (ugly[i] == value3) p3++;
    if (ugly[i] == value5) p5++;
  }

  for (int i = 0; i < 20; i++) {
    cout << ugly[i] << " ";
  }
  cout << endl;
  return 0;
}
