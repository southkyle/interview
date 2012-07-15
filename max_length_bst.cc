#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
int max(const T& a, const T& b, const T& c) {
  int max_num = a > b ? a : b;
  return max_num > c ? max_num : c;
}
struct BinaryNode {
  BinaryNode* left;
  BinaryNode* right;
  int data;
  int height;

  BinaryNode(int d, BinaryNode* l=NULL, BinaryNode* r=NULL)
      :left(l), right(r), data(d), height(-1)
  {}
};

int Height(BinaryNode* t) {
  if (t == NULL) {
    return -1;
  } else if (t->height == -1) {
    int left_height = Height(t->left);
    int right_height = Height(t->right);
    t->height = max(left_height, right_height) + 1;
    return t->height;
  } else {
    return t->height;
  }
}

int MaxLength(BinaryNode* t) {
  if (t == NULL) {
    return -1;
  }

  int left_length = MaxLength(t->left);
  int right_length = MaxLength(t->right);
  int this_length = Height(t->left) + Height(t->right) + 2;

  cout << "node " << t->data << " length " << max(left_length, right_length, this_length) << endl;
  return max(left_length, right_length, this_length);
}

int main(int argc, char *argv[]) {
  BinaryNode n1(1);
  BinaryNode n2(2);
  BinaryNode n3(3);
  BinaryNode n4(4);
  BinaryNode n5(5);
  BinaryNode n6(6);
  BinaryNode n7(7);
  BinaryNode n8(8);
  BinaryNode n9(9);
  BinaryNode n10(10);
  BinaryNode n11(11);
  BinaryNode n12(12);

  n1.left = &n2;
  n1.right = &n3;

  n2.left = &n4;
  n2.right = &n5;

  n4.left = &n6;
  n4.right = &n7;

  n5.left = &n8;
  n5.right = &n9;

  n6.right = &n10;

  n8.left = &n11;
  n11.right = &n12;

  Height(&n1);

  cout << MaxLength(&n1) << endl;
  return 0;
}
