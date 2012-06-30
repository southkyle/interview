#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdint>
using namespace std;
// my version
void* memcpy(void* dst, void* src, size_t n) {
  char* begin = (char*) src;
  char* dest = (char*) dst;
  while (n--) {
    *dest++ = *begin++;
  }
  return dst;
}

// standard version
// Mention that you can use allignment to speed up may be good
void* memcpy2(void* dst, const void* src, size_t count) {
  assert(dst != NULL);
  void* ret = dst;
  while(count--) {
    *(char*)dst = *(char*)src;
    dst = (char*)dst + 1;
    src = (char*)src + 1;
  }
  return ret;
}

// Speed up
void* memcpy3(void* dst, const void* src, size_t count) {
  assert(dst != NULL);
  int32_t* int_dst = (int32_t*)dst;
  int32_t* int_src = (int32_t*)src;
  // 如果是对其的那么可以快速处理
  if (int_dst is align && int_src is align) {
    while (count >= 4) {
      *int_dst++ = *int_src++;
      count -= 4;
    }
  }
  char* ptr_dst = (char*)int_dst;
  char* ptr_src = (char*)ptr_src;
  while (count != 0) {
    *pstr_dst++ = ptr_src++;
  }
  return dst;
}
int main() {
  char from[1024] = {"Apple is big"};
  char dest[1024];
  memcpy(dest, from, sizeof(dest));
  assert(strcmp(dest, from) == 0);
  cout << dest << endl;
  return 0;
}
