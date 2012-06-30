#include <iostream>
using namespace std;


#define arraysize(array) (sizeof(array) / sizeof(array[0]))

#define ASSERT_EQ(a, b) \
  if ((a) == (b)) {\
  cout << "OK " << #a << "==" << #b << endl;\
  } else {\
    cout << "FAIL " << #a << "!=" << #b << endl;	\
  }

int main(int argc, char *argv[]) {
  ASSERT_EQ(2, 3);
  ASSERT_EQ(2+3, 5);
  ASSERT_EQ(2+5, 8);
  return 0;
}

