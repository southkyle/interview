#include <algorithm>
#include <iostream>

using namespace std;


#define arraysize(a) (sizeof(a)/sizeof(a[0]))

int main() {

  int v[] = {5, 3, 1, 2, 6};

  int* p = find(v, v+arraysize(v), 6);
  cout << *p << endl;

  p = find(v, v+arraysize(v), 100);
  if (p == v+arraysize(v)) {
    cout << "not found" << endl;
  }
  
  return 0;
}
