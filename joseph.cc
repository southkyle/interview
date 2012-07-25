#include <iostream>
#include <boost/scoped_array.hpp>
#include "common.h"
using namespace std;

int Joseph2(int n, int m) {
  cout << "****Joseph2*****" << endl;
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
    //    cout << p[pos] << endl;
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

struct Node {
  int left;
  int right;
  int mid;
  int count;
};

const static int kMaxN = 1000;
Node seg_tree[3 * kMaxN];

void make(int l, int r, int num) {
  seg_tree[num].left = l;
  seg_tree[num].right = r;
  seg_tree[num].mid = (l+r) / 2;
  seg_tree[num].count = r - l + 1;
  if (l != r)
  {
    make(l, seg_tree[num].mid, num * 2);
    make(seg_tree[num].mid + 1, r, num * 2 + 1);    
  }
}

int search(int k, int num) {
  if (seg_tree[num].left == seg_tree[num].right) {
    seg_tree[num].count--;
    return seg_tree[num].left;
  }
  int t = seg_tree[2*num].count;
  if (k <= t) {
    seg_tree[num].count--;
    return search(k, 2*num);
  } else {
    seg_tree[num].count--;
    return search(k-t, 2*num + 1);
  }
}

void Joseph3(int n, int m) {
  cout << "Joseph3" << endl;
  make(0, n-1, 1);
  int cur_pos = 0;
  for (; n > 0; n--) {
    cur_pos = (cur_pos + m - 1) % n;
    int step_out = search(cur_pos + 1, 1);
    //    cout << step_out << endl;
  }

}

int main(int argc, char *argv[]) {
  ASSERT_EQ(Joseph1(1, 2), 0);
  ASSERT_EQ(Joseph1(1, 3), 0);
  ASSERT_EQ(Joseph1(2, 1), 1);
  ASSERT_EQ(Joseph1(100, 1), 99);

  Joseph2(5, 2);
  {
    Ticks t1;
    Joseph2(1000, 5);    
  }

  {
    Joseph3(1000, 5);
    Ticks t2;
  }

  return 0;
}
