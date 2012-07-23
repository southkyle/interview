#include <iostream>
#include <cmath>
#include <algorithm>
#include "common.h"
using namespace std;

// Notice that num can be -10, -20
char* itoa(int num, char* str) {
  const char* digits = "0123456789";
  unsigned int value = num > 0 ? num : -num;
  char* begin = str;
  // why use do while?
  // because we should handle the special case 0
  do {
    int d = value % 10;
    *str++ = digits[d];
    value /= 10;
  } while (value != 0);

  if (num < 0) {
    *str++ = '-';
  }
  *str = '\0';   // Notice this
  std::reverse(begin, str);
  return begin;
}

char* itoa1(int num, char* str, int base) {
  const char* digits = "0123456789abcdefghijklmnopqrstuvwxyz";
  unsigned int value = num > 0 ? num : -num;
  char* begin = str;
  do {
    int d = value % base;
    *str++ = digits[d];
    value /= base;
  } while (value != 0);

  if (num < 0) {
    *str++ = '-';
  }
  *str = '\0'; // Notice this
  std::reverse(begin, str);
  return begin;
}

string itoa2(int num, int base) {
  const char* digits = "0123456789abcdefghijklmnopqrstuvwxyz";
  const int kMaxDigits = 35;
  unsigned int value = num > 0 ? num : -num;
  string str;
  str.reserve(kMaxDigits);
  do {
    int d = value % base;
    str.push_back(digits[d]);
    value /= base;
  } while (value != 0);

  if (num < 0) {
    str.push_back('-');
  }

  std::reverse(str.begin(), str.end());
  return str;
}

int main() {
  ASSERT_EQ(1, 1);
  ASSERT_STREQ("bc", "bc");

  char str[32];
  cout << itoa(100, str) << endl;
  cout << itoa(-100, str) << endl;
  cout << itoa(0, str) << endl;

  cout << itoa1(100, str, 16) << endl;
  cout << itoa1(16, str, 16) << endl;

  cout << "**************itoa2******************" << endl;
  cout << itoa2(-100, 10) << endl;
  cout << itoa2(0, 10) << endl;
  
  return 0;
}
