#ifndef _COMMON_H_
#define _COMMON_H_
#include <iostream>
#include <cstring>
#include <stdint.h>
#include <sys/time.h>

#define arraysize(array) (sizeof(array) / sizeof(array[0]))

#define ASSERT_EQ(a, b)                                         \
  if ((a) == (b)) {                                             \
    std::cout << "==OK==" << std::endl;                         \
    std::cout << #a << " == " << #b << std::endl << std::endl;  \
  } else {                                                      \
    std::cout << "==FAIL==" << std::endl;                       \
    std::cout << #a << "==" << #b << std::endl << std::endl;    \
  } 

#define ASSERT_NE(a, b)                                         \
    if ((a) != (b)) {                                           \
      std::cout << "==OK==" << std::endl;                       \
      std::cout << #a << "!=" << #b << std::endl << std::endl;  \
    } else {                                                    \
      std::cout << "==FAIL==" << std::endl;                     \
      std::cout << #a << "!=" << #b << std::endl << std::endl;  \
    }

#define ASSERT_STREQ(a, b)                              \
  if (strcmp(a, b) == 0) {				\
    cout << "OK " << #a << "==" << #b << endl;          \
  } else {                                              \
    cout << "FAIL " << #a << "!=" << #b << endl;	\
  }

#define ASSERT_STRNE(a, b)                              \
  if (strcmp(a, b) == 0) {				\
    cout << "FAIL " << #a << "==" << #b << endl;          \
  } else {                                              \
    cout << "OK " << #a << "!=" << #b << endl;	\
  }

class Ticks {
public:
  Ticks() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    start_ticks_ = tv.tv_sec * 1000000 + tv.tv_usec;
  }
  ~Ticks() {
    using namespace std;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    uint64_t end_ticks = tv.tv_sec * 1000000 + tv.tv_usec;
    cout << end_ticks - start_ticks_ << endl;
  }
private:
  uint64_t start_ticks_;
};
#endif /* _COMMON_H_ */
