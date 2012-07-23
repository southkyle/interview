#ifndef _COMMON_H_
#define _COMMON_H_
#include <iostream>

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
#endif /* _COMMON_H_ */
