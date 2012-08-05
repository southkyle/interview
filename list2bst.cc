#include "common.h"
using namespace std;

struct BinaryNode {
  BinaryNode* left;
  BinaryNode* right;
  int data;
  BinaryNode() : left(NULL), right(NULL), data(-1) {
    
  }
};

BinaryNode* CreateBst(int array[], int left, int right) {
  if (left > right) return NULL;
  int m = (left + right) / 2;

  BinaryNode* x = new BinaryNode;
  x->data = array[m];

  x->left = CreateBst(array, left, m - 1);
  x->right = CreateBst(array, m + 1, right);
  return x;
}

void PrintTree(BinaryNode* n) {
  if (n != NULL) {
    PrintTree(n->left);
    cout << n->data << ", ";
    PrintTree(n->right);
  }
}

int main(int argc, char *argv[]) {
  const int kMax = 10;
  int array[kMax];

  for (int i = 0; i < kMax; i++) {
    array[i] = i;
  }
  
  BinaryNode* n = CreateBst(array, 0, kMax - 1);

  PrintTree(n);
  cout << endl;
  return 0;
}
