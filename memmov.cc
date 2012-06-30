#include <iostream>
#include <cassert>
using namespace std;

void* memmov(void* dst, void* src, size_t count) {
  void* ret = dst;
  if ((char*) src > (char*) dst) {
    while (count--) {
      *(char*)dst = *(char*)src;
      dst = (char*)dst + 1;
      src = (char*)src + 1;
    }
  }
  else {
    dst = (char*)dst + count - 1; // notice here
    src = (char*)src + count - 1; // notice here
    while (count--) {
      *(char*)dst = *(char*)src;
      dst = (char*)dst - 1;
      src = (char*)src - 1;
    }
  }

  return ret;
}

