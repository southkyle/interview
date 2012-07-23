#ifndef _COMMON_H_
#define _COMMON_H_
#include <iostream>
#include <cstring>

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

#endif /* _COMMON_H_ */
