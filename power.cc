#include <iostream>
#include <cmath>
using namespace std;


#define arraysize(array) (sizeof(array) / sizeof(array[0]))

#define ASSERT_EQ(a, b) \
  if ((a) == (b)) {\
  cout << "OK " << #a << "==" << #b << endl;\
  } else {\
    cout << "FAIL " << #a << "!=" << #b << endl;	\
  }

// 看似容易其实很难
// 最简单的时间复杂度为O(n)
// O(logn)
// double Pow(double x, int y); y 可以为为负 0 正
// x / 2 --> x >>= 1
// x % 2 --> x & 1
// 如何保证y为最小的负数时不越界: 若y为负 -y可能越界，如何保证不越界
// | 指数 | 二进制 | 值              |
// |------+--------+-----------------|
// | x^11 |   1011 | x^8 * x^2 * x^1 |
// | x^10 |   1010 | x^8 * x^2       |
// | x^9  |   1001 | x^8 * x^1       |
// | x^8  |   1000 | x^8             |
// | x^7  |   0111 | x^4 * x^2 * x^1 |
// | x^6  |   0011 | x^4 * x^2       |
// | x^5  |   0101 | x^4 * x^1       |
// | x^4  |   0100 | x^4             |
// | x^3  |   0011 | x^2 * x^1       |
// | x^2  |   0010 | x^2             |
// | x^1  |   0001 | x^1             |

// |      |   |         z | x          |
// |------+---+-----------+------------|
// | x    | 0 |       1:1 | x:x^2      |
// | x^2  | 0 |       1:1 | x^2:x^4    |
// | x^4  | 0 |       1:1 | x^4:x^8    |
// | x^8  | 1 |     1:x^8 | x^8:x^16   |
// | x^16 | 1 |  x^8:x^24 | x^16:x^32  |
// | x^32 | 0 | x^24:x^24 | x^32:x^64  |
// | x^64 | 1 | x^24:x^88 | x^64:x^128 |
// x^88 = x^(64 + 16 + 8)
//      = x^(2^6 + 2^4 + 2^3)



int Power(int a, int power) {
  if (a == 0) return 0;
  else if (power < 0) return 1.0 / Power(a, -power); // 会越界
  else if (power == 0) return 1;
  else if (power == 1) return a;
  else if (power % 2 == 0) {
    return Power(a*a, power/2);
  } else {
    return Power(a*a, power/2) * a;
  }
}

int Power1(int a, int power) {
  if (a == 0) return 0;
  else if (power < 0) return 1.0 / Power(a, -power); // 会越界
  else if (power == 0) return 1;
  else if (power == 1) return a;
  else if (power % 2 == 0) {
    int t = Power(a, power/2);
    return t * t;
  } else {
    int t = Power(a, power/2);
    return t * t * a;
  }
}


int Power2(int a, int n) {
  int z = 1;
  unsigned int N = n;
  for (; N > 0; a *= a) {
    if ((N&1) != 0) {
      z *= a;
    }
    N /= 2;
  }
  return n<0 ? 1.0/z : z;
}

int main(int argc, char *argv[]) {
  ASSERT_EQ(Power(2, 0), 1);
  ASSERT_EQ(Power(0, 0), 0);
  ASSERT_EQ(Power(0, 5), 0);
  ASSERT_EQ(Power(2, 10), 1024);
  ASSERT_EQ(Power(2, 9), 512);
  
  ASSERT_EQ(Power1(2, 0), 1);
  ASSERT_EQ(Power1(0, 0), 0);
  ASSERT_EQ(Power1(0, 5), 0);
  ASSERT_EQ(Power1(2, 10), 1024);
  ASSERT_EQ(Power1(2, 9), 512);

  cout << pow(0, 0) << endl;

  ASSERT_EQ(Power2(2, 0), 1);
  ASSERT_EQ(Power2(0, 0), 0);

  for (int i = 0; i < 10; i++) {
    ASSERT_EQ(Power2(2, i), pow(2, i));
  }
  return 0;
}
