#include <iostream>
#include <cassert>
#include <cstring>

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

void* memcpy2(void* dst, void* src, size_t count) {
  assert(dst != NULL);
  void* ret = dst;
  while(count--) {
    *(char*)dst = *(char*)src;
    dst = (char*)dst + 1;
    src = (char*)src + 1;
  }
  return ret;
}

int main() {
  char from[1024] = {"Apple is big"};
  char dest[1024];
  memcpy(dest, from, sizeof(dest));
  assert(strcmp(dest, from) == 0);
  cout << dest << endl;
  return 0;
}
