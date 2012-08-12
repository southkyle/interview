#include <set>
#include <algorithm>
#include <limits>
#include <string>
#include <ext/hash_set>
#include "common.h"
using namespace std;
using namespace __gnu_cxx;

namespace __gnu_cxx {
template<>
struct hash<string> {
  size_t operator()(const string& s) const {
    return __stl_hash_string(s.c_str());
  }
};
}
void lookup(const hash_set<string>& set, const std::string& word) {
  hash_set<string> it = set.find(word);
  if (it != set.end()) {
    cout << word << " in set" << endl;
  } else {
    cout << word << " not in set" << endl;
  }
}
void test_hashset() {
  hash_set<string> set;
  set.insert("kiwi");
  set.insert("liming");
  set.insert("wangqiang");
  set.insert("apple");
  set.insert("mongo");
  set.insert("banana");

  lookup(set, "apple");
  lookup(set, "liming");
  lookup(set, "wandong");
}

void test_limits() {
  cout << "unsigned char" << int(numeric_limits<unsigned char>::min() )<<  " " << endl;
  cout << int(numeric_limits<unsigned char>::max()) << endl;

  cout << "int " << numeric_limits<int>::min() << " "
       << numeric_limits<int>::max() << endl;
}

void test_set() {
  int i;
  int ia[] = {0, 1, 2, 3, 4, 5};
  set<int> iset(ia, ia + arraysize(ia));

  cout << "size=" << iset.size() << endl;
  cout << "3 count=" << iset.count(3) << endl;
  iset.insert(3);
  cout << "3 count=" << iset.count(3) << endl;
  iset.insert(5);
  cout << "5 count=" << iset.count(5) << endl;
  iset.erase(1);
  cout << "size=" << iset.size() << endl;
  cout << "1 count=" << iset.count(1) << endl;

  set<int>::iterator ite1 = iset.begin();
  set<int>::iterator ite2 = iset.end();
  for (; ite1 != ite2; ++ite1) {
    cout << *ite1 << " ";
  }
  cout << endl;

  ite1 = find(iset.begin(), iset.end(), 3);
  if (ite1 != iset.end()) {
    cout << "3 found " << endl;
  }

}

int main(int argc, char *argv[]) {
  test_set();
  test_limits();
  return 0;
}

