#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

// 100层楼，2个鸡蛋，怎么扔才能确定鸡蛋碎的楼层？

// 法1： 二分法：首先在50层仍鸡蛋，如果没碎，就在25层扔，如果碎了,
//   就从1层开始扔
//   显然，这不是个好办法

//   从这个方法中我们学到的是不要每次都层第一层开始
//   每次扔可以N层，这样可以加快速度，比如每10层一扔，第一次在10层扔，
//   第二次在20层扔，这样就可以加快速度

//   第一次在10层，如果碎了就需要从第一层开始一层层的扔共需要10次
//     第二次在19层扔，如果碎了那么就从11->18层 （1 + 9)  = 10次

//     x + x-1 + x-2 + ... + 1 = (x+1)x/2  >= 100 获得x>=13.65
//     x为14

// N 层楼，m个鸡蛋
// f(N, M) = min(max(f(r-1, m-1), f(n-r, m))) + 1
// r-1>=1
// n-r>=1
// 2 <= r <= n-1

// 如果鸡蛋的数目和楼层数一样，就可以用二分法了

const int kMaxFloor = 1000;
const int kMaxEggs = 100;
int dp[kMaxFloor][kMaxEggs];



int MinFloor(int n, int m) {
  if (n <= 2) {
    return n;
  } else if (m == 1) {
    return n;
  }
  
  if (dp[n][m] != -1) {
    return dp[n][m];
  }


  int min_num = numeric_limits<int>::max();
  for (int r = 2; r<= n - 1; r++) {
    int f = max(MinFloor(r-1, m-1), MinFloor(n-r, m)) + 1;
    if (f < min_num) {
      min_num = f;
    }
  }
  dp[n][m] = min_num;
  cout << "<n, m> = <" << n << "," << m << "> " << min_num << endl;
  return dp[n][m];
}
  
int main(int argc, char *argv[]) {
  for (int i = 0; i < kMaxFloor; i++) {
    for (int j = 0; j < kMaxEggs; j++) {
      dp[i][j] = -1;
    }
  }

  cout << MinFloor(100, 2) << endl;
  cout << MinFloor(100, 100) << endl;
  return 0;
}
