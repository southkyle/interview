#include <iostream>
#include <boost/scoped_array.hpp>
#include "common.h"
using namespace std;

int Joseph2(int n, int m) {
  cout << "*********" << endl;
  cout << n << ", " << m << endl;
  boost::scoped_array<int> p;
  p.reset(new int[n]);
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  int left = n;
  int pos = 0;
  while (left > 0) {
    pos = (pos + m - 1) % left;
    if (left == 0) {
      return p[pos];
    }
    cout << p[pos] << endl;
    for (int i = pos; i < left - 1; i++) {
      p[i] = p[i+1];
    }
    left--;
  }
  
}

// 从 0 n-1 中挑出第m个
// 0 1 2 ... m-2 m .. n-1
// 0 n-1-m n-m 1-m+n ... n-2
// f(n, m) = (f(n-1, m) + m) % n

int Joseph1(int n, int m) {
  int f = 0; // n == 1 f==0
  for (int i = 2; i <=n; i++) {
    f = (f + m) % i;
  }
  return f;
}


int main(int argc, char *argv[]) {
  ASSERT_EQ(Joseph1(1, 2), 0);
  ASSERT_EQ(Joseph1(1, 3), 0);
  ASSERT_EQ(Joseph1(2, 1), 1);
  ASSERT_EQ(Joseph1(100, 1), 99);

  Joseph2(5, 2);
  Joseph2(5, 3);
  return 0;
}
