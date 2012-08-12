#include <iostream>
using namespace std;

struct Empty {};

struct Int {int a;};

struct EmptyVirtual {
  virtual void Foo();
};

struct EmptyVV {
  virtual void Foo();
  virtual void Bar();
};
  
int main(int argc, char *argv[]) {
  cout << "Empty struct " << sizeof(Empty) << endl;
  cout << "Int struct " << sizeof(Int) << endl;
  cout << "EmptyVirtual " << sizeof(EmptyVirtual) << endl;
  cout << "EmptyVV " << sizeof(EmptyVV) << endl;
  return 0;
}
