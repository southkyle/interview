// 有一只可怜的猴子被锁在电脑前面录入数字，
// 键盘是九键（0-9），猴子有2根手指，我们要录入一串数字，问如何设计一个策略，让猴子手指移动的距离最短？

// 0 1 2
// 3 4 5
// 6 7 8

// F(left, right , [ai, ai+1, ..., an-1])
// = min(F(ai, right, [ai+1, ..., an-1]) + distance(ai, left),
//       F(left, ai,  [ai+1,..., an-1]) + distance(ai, right))

#include <algorithm>
#include <iostream>
using namespace std;

int MinDistance(int number[], int n) {
  int dp[9][9][n+1];
  for (int left_hand = 0; left_hand < 9; left_hand++) {
    for (int right_hand = 0; right_hand < 9; right_hand++) {
      dp[left_hand][right_hand][n] = 0;
    }
  }
  
  for (int i = n - 1; i >= 0; i--) {
    for (int left_hand = 0; left_hand < 9; left_hand++) {
      for (int right_hand = 0; right_hand < 9; right_hand++) {
        int lmove = dp[number[i]][right_hand]] + Distance(number[i], left_hand);
        int rmove = dp[left_hand][number[i]] + Distance(number[i], right_hand);
        dp[left_hand][right_hand][i] = min(lmove, rmove);
      }
    }
  }

return min(dp[:,:,0])

}
