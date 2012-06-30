#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


// 有n个台阶，可以每次可以走一步，也可以走2步，问总共有多少种不同的走法
// 加法法则
// 4个台阶时，分为两种情况第一步走一步F(3) + 第一步走两步F(2)
// F(4) = F(3) + F(2)
// F(n) = F(n-1) + F(n-2)

int Fib1(int n) {
  if (n <= 1) return 1;
  return Fib1(n-1) + Fib1(n-2);
}

int Fib2(int n) {
  std::vector<int> fibs(n + 1);
  fibs[0] = 1;
  fibs[1] = 1;
  for (int i = 2; i <= n; i++) {
    fibs[i] = fibs[i-1] + fibs[i-2];
  }
  return fibs[n];
}

int Fib3(int n) {
  if (n <= 1) return 1;
  int f1 = 1;
  int f2 = 1;
  int f;
  for (int i = 2; i <= n; i++) {
    f = f1 + f2;
    f2 = f1;
    f1 = f;
  }
  return f;
}


int main() {
  assert(Fib1(1) == 1);
  assert(Fib1(2) == 2);
  assert(Fib1(3) == 3);
  assert(Fib1(10) == Fib2(10));
  assert(Fib1(10) == Fib3(10));
  return 0;
}
