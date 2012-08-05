#include "common.h"
using namespace std;

struct BinaryNode {
  BinaryNode* left;
  BinaryNode* right;
  int data;
  BinaryNode() : left(NULL), right(NULL), data(-1) {
  }
};

BinaryNode* pre;
BinaryNode* head;

BinaryNode* BinaryTreeToLinkedList(BinaryNode* r) {
  if (r == NULL) return NULL;
  
  BinaryTreeToLinkedList(r->left);

  r->left = pre;

  if (pre != NULL) {
    pre->right = r;
  }

  if (pre == NULL) {
    head = r;
  }
  
  pre = r;
  BinaryTreeToLinkedList(r->right);
}

void PrintTree(BinaryNode* r) {
  if (r != NULL) {
    PrintTree(r->left);
    cout << r->data << ", ";
    PrintTree(r->right);
  }
}
void PrintList(BinaryNode* list) {
  while (list != NULL) {
    cout << list->data << ", ";
    list = list->right;
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  const int kMax = 10;
  BinaryNode treenodes[kMax];
  for (int i = 0; i < kMax; i++) {
    treenodes[i].data = i;
    if (2*i + 1 < kMax)
      treenodes[i].left = &treenodes[2*i + 1];
    if (2*i + 2 < kMax)
      treenodes[i].right = &treenodes[2* i + 2];
  }

  PrintTree(&treenodes[0]);
  cout << endl;
  pre = NULL;
  BinaryTreeToLinkedList(&treenodes[0]);
  PrintList(head);
  PrintList(&treenodes[6]);
  return 0;
}
