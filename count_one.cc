#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdint.h>
using namespace std;

#define ASSERT_EQ(a, b)                                 \
  if ((a) != (b)) {                                     \
    cout << "FAIL " << #a << "!=" << #b << endl;        \
        exit(1);                                        \
  }  else {                                             \
    cout << "OK" << endl;;                              \
  }

int Count(uint32_t number) {
  int count = 0;
  while (number != 0) {
    if ((number & 1) != 0) {
      count++;
    }
    number >>= 1;
  }

  return count;
}

int Count2(uint32_t number) {
  int count = 0;
  while (number != 0) {
    count++;
    number = number & (number - 1);
  }
  return count;
}

int Count3(uint32_t number) {
  int counts[] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8};
  int count = 0;
  while (number != 0) {
    uint8_t n = number & 0xff;
    count += counts[n];
    number >>= 8;
  }
  return count;
}

int main() {
  for (uint32_t i = 0; i < 100; i++) {
    cout << i << " " << Count(i) << ":" << Count2(i) << endl;
    ASSERT_EQ(Count(i), Count2(i));
    ASSERT_EQ(Count(i), Count3(i));
  }

  Count3(2);
  return 0;
}
