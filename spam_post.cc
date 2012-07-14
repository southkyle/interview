#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

#define ASSERT_EQ(a, b)                                 \
  if ((a) != (b)) {                                     \
    cout << "FAIL " << #a << "!=" << #b << endl;        \
        exit(1);                                        \
  }  else {                                             \
    cout << "OK" << endl;;                              \
  }

#define arraysize(a) (sizeof(a)/sizeof(a[0]))

int FindSpamPost(std::vector<int>& users) {
  int spam_user = -1;
  int count = 0;

  for (int i = 0; i < users.size(); i++) {
    if (count == 0) {
      spam_user = users[i];
      count = 1;
    } else if (users[i] == spam_user) {
      count++;
    } else {
      count--;
    }
  }
  return spam_user;
}

int main() {
  int users0[] = {1, 1, 1, 1, 2, 3};
  int users1[] = {1};
  int users2[] = {1, 1, 2};
  int users3[] = {2, 1, 2};

  std::vector<int> v0(users0, users0 + arraysize(users0));
  std::vector<int> v1(users1, users1 + arraysize(users1));
  std::vector<int> v2(users2, users2 + arraysize(users2));
  std::vector<int> v3(users3, users3 + arraysize(users3));
  
  ASSERT_EQ(FindSpamPost(v0), 1);
  ASSERT_EQ(FindSpamPost(v1), 1);
  ASSERT_EQ(FindSpamPost(v2), 1);
  ASSERT_EQ(FindSpamPost(v3), 2);
  
  return 0;
}
