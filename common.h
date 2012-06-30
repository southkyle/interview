#ifndef _COMMON_H_
#define _COMMON_H_

#define arraysize(array) (sizeof(array) / sizeof(array[0]))

#define ASSERT_EQ(a, b) \
  if ((a) == (b)) {\
  cout << "OK " << #a << " equal to " << #b << endl;\
  } else {\
  cout << "FAIL" << #a << " not equal to " << #b << endl;\
  }

#endif /* _COMMON_H_ */
