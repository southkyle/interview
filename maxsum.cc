#include "common.h"
#include <limits>
#include <algorithm>
#include <numeric>
using namespace std;

int MaxSum1(int array[], int n) {
  int max_sum = 0;
  int this_sum = 0;
  for (int i = 0; i < n; i++) {
    this_sum += array[i];
    if (this_sum < 0) {
      max_sum = 0;
    } else if (this_sum > max_sum) {
      max_sum = this_sum;
    }
  }
  if (max_sum <= 0) {
    int max = numeric_limits<int>::min();
    for (int i = 0; i < n; i++) {
      if (array[i] > max) {
        max = array[i];
      }
    }
    return max;
  } else {
    return max_sum;
  }
}

int MinSum1(int array[], int n) {
  int min_sum = array[0];
  int this_sum = 0;
  for (int i = 1; i < n; i++) {
    if (this_sum > 0) {
      this_sum = array[i];
    } else {
      this_sum += array[i];
    }
    if (this_sum < min_sum) {
      min_sum = this_sum;
    }
  }
  return min_sum;
}

int maxRotatedSum(int array[], int n) {
  int max_sum = MaxSum1(array, n);
  int min_sum = MinSum1(array, n);
  int total_sum = accumulate(array, array+n, 0);
  return max(max_sum, total_sum - min_sum);
}

// This algorithm is wrong
// 6 -1 -6 8 2
// max_sum = 10
// max_left_sum = 9 [6 -1 -6 8 2]
// max_right_sum = 10 [8 2]
// But left_pos > right_pos
// so m2 = sum(array) = 9
// max is max(10, 9) = 10
// But obviouly the answer is 16
// The right way to do this is find the min sub array
// another method A A
// so find max sub array  len(array) < n

int MaxSumRotate(int array[], int n) {
  int max_sum = MaxSum1(array, n);
  int max_left_sum = 0;
  int left_sum = 0;
  int left_pos = -1;
  for (int i = 0; i < n; i++) {
    left_sum += array[i];
    if (left_sum > max_left_sum) {
      max_left_sum = left_sum;
      left_pos = i;
    }
  }

  int max_right_sum = 0;
  int right_sum = 0;
  int right_pos = -1;
  for (int i = n - 1; i >= 0; i--) {
    right_sum += array[i];
    if (right_sum > max_right_sum) {
      max_right_sum = right_sum;
      right_pos = i;
    }
  }

  if (left_pos < right_pos) {
    if (max_left_sum + max_right_sum > max_sum) {
      max_sum = max_left_sum + max_right_sum;
    }
  }

  return max_sum;
}


// 2D(max submatrix) very simple
// 2D rotated submatrix
// (I don't konw)2D left-right rotated top-down rotated matrix
// Haha I find it on the internet
// 1.b 轮胎装的最大子矩阵和其实就是把平面上下相连和左右相连。不管先连那边都一样的，一样是O(n^3)。
// 有两种方法：先把轮胎剪开成平面（随便找一条横边和一条竖边即可），然后原问题等价于把4个这样的平面拼在一起找不超过一个平面大小的最大子矩阵。先用O(n^2)空间转换为1维的问题，枚举上下边界，用一维的方法用单调队列求解。第二种方法比较蛋疼：把轮胎剪开一边形成一个环（横的竖的出来结果都一样），假设结果不会越过剪的那条边，于是又是转化为一维的循环数组了。。如果结果越边，还是枚举上下边界转为一维数组的最小子段和。好麻烦，还是第一种方法好。1.b 轮胎装的最大子矩阵和其实就是把平面上下相连和左右相连。不管先连那边都一样的，一样是O(n^3)。有两种方法：先把轮胎剪开成平面（随便找一条横边和一条竖边即可），然后原问题等价于把4个这样的平面拼在一起找不超过一个平面大小的最大子矩阵。先用O(n^2)空间转换为1维的问题，枚举上下边界，用一维的方法用单调队列求解。第二种方法比较蛋疼：把轮胎剪开一边形成一个环（横的竖的出来结果都一样），假设结果不会越过剪的那条边，于是又是转化为一维的循环数组了。。如果结果越边，还是枚举上下边界转为一维数组的最小子段和。好麻烦，还是第一种方法好。1.b 轮胎装的最大子矩阵和其实就是把平面上下相连和左右相连。不管先连那边都一样的，一样是O(n^3)。有两种方法：先把轮胎剪开成平面（随便找一条横边和一条竖边即可），然后原问题等价于把4个这样的平面拼在一起找


// max(abs(sum(ai,...,aj)))
// 有一个整数数列，其中有负数、正数， 其中连续的几个数求和，求和的绝对值最大的数
// 字串

// 求数组中两两元素只差绝对值最小值
// 设这个整数数组是a1,a2,...,an
// 构造数组B=(b1,b2,...,bn-1) 
// b1 = a1-a2, 
// b2 = a2-a3, 
// b3 = a3-a4, 
// ... 
// bn-1 = an-1 - an 

// 那么原数组中，任意两整数之差ai-aj（1 <=i,j <=n）可以表示成 
// B中第i个到第j-1个元素的连续求和 

// 例如b2+b3+b4 = (a2-a3) + (a3-a4) + (a4-a5) = a2-a5 

// O(n)构造出B序列后 

// 用类似“最大子段和”算法求“最小绝对值子段和”
// First quicksort nlogn

// “最小绝对值子段和” There are no good method
// Maybe this can work
// 1 Find the max subarray
// 2 Find the min subarray
// 3 return the max of two
// I can't prove the alogrithm

int main(int argc, char *argv[]) {
  
  return 0;
}
