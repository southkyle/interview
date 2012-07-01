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



// Stack return the minimum element.
// Easy.
// Keep two stack.

class Stack {
public:
  void Push(int x) {
    s1.push(x);
    if (x < s2.top()) {
      s2.push(x);
    }
  }

  int Pop() {
    int x = s1.top();
    s1.pop();
    if (x == s2.top()) {
      s2.pop();
    }
    return x;
  }

  int MinNum() {
    return s2.top();
  }
private:
  std::stack<int> s1;
  std::stack<int> s2;
};

// What about space complexity is O(1)
// if the numbers push to the stack are > 0

// |  5 |   |    |
// | 14 |   |    |
// | 13 |   |    |
// | 12 |   |    |
// |  6 |   |    |
// |  8 |   |  5 |
// | 12 |   |  6 |
// | 11 |   |  8 |
// | 10 |   | 10 |
// |----+---+----|

// |  5 |   | -1 |  min_element = 5
// | 14 |   | 14 |  
// | 13 |   | 13 |
// | 12 |   | 12 |
// |  6 |   | -2 |
// |  8 |   | -2 |
// | 12 |   | 12 |
// | 11 |   | 11 |
// | 10 |   | 10 |  
// |----+---+----|


// min_element is 5, if we pop -1, we find that -1 is less than zero.
// Then it must be a minimus number. The next min_element is 5 - (-1)  = 6

// def Push(self, x):
//    if x < self.min_element:
//      x -= self.min_element
//      self.min_element = x
   
//    self.stack.push(x)

// def Pop(self):
//    if self.stack.top() < 0:
//       self.min_element = self.min_element - self.stack.top()

//    self.stack.pop()

// def Top(self):
//    if self.stack.top() < 0:
//       return self.min_element
//    else:
//       return self.stack.top()

// Suppose previous minimum number is a
// Now the minumu number is b so b < a
// b - a < 0
// 2b - a < b
// So we put (2b - a) at the top of the stack.

// Implement a stack that pops out the most frequently added item.
// Stack supports 3 functions - push, pop,and top.
// Give complexity of each functions in your implementation.

hash_map<int, list<int> > all_data;
struct Node {
  int count;   
  int sequence;
  int number;
 
  
  int Compare(const Node& n) {
    if (count < n.count) {
      return -1;
    } else if (count > n.count) {
      return 1;
    } else if (number == n.number) {
      return 0;
    } else if (sequence < n.sequence) {
      return -1;
    } else {
      return 1;
    }
  }
};

set<Node> nodes;

void Push(int x) {
  if (all_data.find(x)) {
    Node n;
    n.count = all_data[x].size();
    n.number = x;
    nodes.remove(n);
    n.count++;
    n.sequence = GetSequence();
    nodes.add(n);
    all_data[x].push_back(x);
  } else {
    Node n;
    n.count = 1;
    n.number = x;
    n.sequence = GetSequence();
    nodes.add(n);
    all_data[x].push_back(x);
  }
}

void Pop(int* x) {
  n = nodes.remove_last();
  n.count -= 1;
  nodes.add(n);
  all_data[n.number].pop();
}

// O(logn)
// All just compute the most frequent number

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
