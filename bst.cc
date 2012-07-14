#include <iostream>
using namespace std;

struct BinaryNode {
  int data;
  BinaryNode* left;
  BinaryNode* right;


  BinaryNode(int x, BinaryNode* l, BinaryNode* r)
      : data(x), left(l), right(r)
  {}
};

BinaryNode* Insert(BinaryNode* t, int x) {
  if (t == NULL) {
    t = BinaryNode(x, NULL, NULL);
  } else if (x < t->data) {
    t->left = Insert(t->left, x);
  } else if (t->data < x) {
    t->right = Insert(t->right, x);
  } else {
    
  }
  return t;
}


BinaryNode* Remove(BinaryNode* t, int x) {
  if (t == NULL) {
    return NULL;
  }
  if (t->data < x) {
    t->right = Remove(t->right, x);
  } else if (x < t->data) {
    t->left = Remove(t->left, x);
  } else {
    if (t->left != NULL && t->right != NULL) {
      t->data = FindMin(t->right)->data;
      t->right = Remove(t->right, x);
    } else {
      BinaryNode* child = t->left != NULL ? t->left : t->right;
      delete t;
      t = child;
    }
  }

  return t;
}

int main(int argc, char *argv[]) {
  
  return 0;
}

