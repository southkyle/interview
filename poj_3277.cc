#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int maxn = 100010;

using namespace std;

int t;
long long sum;
struct node {
  int left;
  int right;
  int mid;
  int h;
};

node tree[3 * maxn];

struct no {
  int a;
  int b;
  int hi;
} s[maxn];

long long hash[maxn];

struct point {
  int li, num;
  bool operator < (const struct point& other) const {
    return li < other.li;
  }
} line[maxn];

void make(int l, int r, int num) {
  tree[num].left = l;
  tree[num].right = r;
  tree[num].mid = (l+r)/2;
  tree[num].h = 0;
  if (l+1 != r) {
    make(l, tree[num].mid, 2*num);
    make(tree[num].mid, r, 2*num + 1);
  }
}

void insert(int l, int r, int h, int num) {
  if (tree[num].left == l && tree[num].right == r) {
    if (tree[num].h < h) {
      tree[num].h = h;
      return 0;
    }
  } else if (tree[num].left < tree[num].right) {
    if (r <= tree[num].mid)
      insert(l, r, h, 2*num);
    else if (l >= tree[num].mid)
      insert(l, r, h, 2*num + 1);
    else {
      insert(l, tree[num].mid, h, 2*num);
      insert(tree[num].mid, r, h, 2*num + 1);
    }
  }
}

long long cal(int h, int num) {
  if (h > tree[num].h) {
    tree[num].h = h;
  }
  if (tree[num].left + 1 == tree[num].right)
    return (long long) (tree[num].h * (hash[tree[num].right] - hash[tree[num].left]));
  return cal(tree[num].h, 2*num) + cal(tree[num].h, 2*num + 1);
}

int main() {
  int i;
  while (scanf("%d", &t) != EOF) {
    for (int i=0; i<t; i++) {
      int sa, sb, sh;
      scanf("%d%d%d", &sa, &sb, &sh);
      if (sa > sb)
        swap(sa, sb);
      s[i].a = sa;
      s[i].b = sb;
      s[i].h = sh;
      line[2*i].li = s[i].a;
      line[2*i].num = -(i+1);
      line[2*i + 1].li = s[i].b;
      line[2*i + 1].num = i+1;
    }
    sort(line, line + t*2);
    int tp = 1, temp = line[0].li;
    for (int i = 0; i < 2 * t; i++) {
      if (line[i].li != temp) {
        tp++;
        temp = line[i].li;
      }

      if (line[i].num < 0) {
        hash[tp] = s[-line[i].num - 1].a;
        s[-line[i].num - 1].a = tp;
      }
      else {
        hash[tp] = s[line[i].num - 1].b;
        s[line[i].num - 1].b = tp
      }
    }
    make(1, tp, 1);
    for (i = 0; i < t; i++) {
      insert(s[i].a, s[i].b, s[i].hi, 1);
    }
    sum=cal(0, 1);
    printf("%lld\n", sum);
  }
  return 0;
}
