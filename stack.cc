#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

// 如何实现一个stack，这个其实是很难的？
// 如何进行错误处理
// Top() 应该如何设计
// bool Top(int* x);
// int Top(); 设置一个变量，表示错误

// int Top() {
//   if (Empty()) {
//     SetErrno(Empty);
//     return 0;
//   }

//   return TopElement;
// }
// Client Code
// x = s.Top();
// if s.GetLastError != Status::OK() {
//    ErrorHandler();
// }
// Other Process

// Status Top(int* x) {
//   if (Empty()) {
//     return Status::Empty();
//   }
//   *x = TopElement;
//   return Status::OK();
// }
//
// status = s.Top(&x);
// if status.ok() :
//     process;
// 
// int Top() {
//   if (Empty()) {
//     throw StackEmpty;
//   }
//   return TopElement;
// }
//
// try:
//   x = s.Top();
// catch StackException:
//   print error

class Queue {
public:
  void Push(int x) {
    s1.push(x);
  }

  int Pop() {
    if (s1.empty() && s2.empty()) {
      cout << "Error" << endl;
      return -1;
    }

    if (s2.empty()) {
      while (!s1.empty()) {
	int x = s1.top();
	s2.push(x);
	s1.pop();
      }
    }
    
    int x = s2.top();
    s2.pop();
    return x;
  }
private:
  std::stack<int> s1;
  std::stack<int> s2;
};


int main(int argc, char *argv[]) {
  Queue s;
  s.Push(1);
  s.Push(2);
  s.Push(3);

  int x = s.Pop();
  assert(x == 1);
  s.Push(4);
  x = s.Pop();
  assert(x == 2);
  x = s.Pop();
  assert(x == 3);
  x = s.Pop();
  assert(x == 4);
  return 0;
}
