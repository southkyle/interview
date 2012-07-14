#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct BinaryTreeNode {
  BinaryTreeNode* left;
  BinaryTreeNode* right;
  int data;

  BinaryTreeNode(BinaryTreeNode* l, BinaryTreeNode* r, int d)
      :left(l), right(r), data(d){}
};

void PrintByLevel(BinaryTreeNode* node) {
  if (node == NULL) {
    return;
  }

  vector<BinaryTreeNode*> queue;
  queue.push_back(node);
  int current = 0;
  while (queue.size() != current) {
    int size = queue.size();
    for (;current < size; current++) {
      BinaryTreeNode* curr = queue[current];
      cout << curr->data << " ";
      if (curr->left != NULL) {
        queue.push_back(curr->left);
      }
      if (curr->right != NULL) {
        queue.push_back(curr->right);
      }
    }
    cout << endl;
  }
}

void PrintByLevel2(BinaryTreeNode* node) {
  if (node == NULL) {
    return;
  }

  queue<BinaryTreeNode*> q;
  q.push(node);
  int size = 1;
  int next_size = 0;
  while (q.size() != 0) {
    
    
    for (; size != 0; size--) {
      BinaryTreeNode* curr = q.front();
      q.pop();
      cout << curr->data << " ";
      if (curr->left != NULL) {
        q.push(curr->left);
        next_size++;
      }
      if (curr->right != NULL) {
        q.push(curr->right);
        next_size++;
      }
    }
    cout << endl;
    size = next_size;
    next_size = 0;
  }
}



int main(int argc, char *argv[]) {
  vector<BinaryTreeNode*> tree;
  for (int i = 1; i < 100; i++) {
    tree.push_back(new BinaryTreeNode(NULL, NULL, i));
  }
  for (int i = 0; i < tree.size(); i++) {
    int left = 2*i + 1;
    int right = 2*i +2;
    if (left < tree.size()) {
      tree[i]->left = tree[left];
    }

    if (right < tree.size()) {
      tree[i]->right = tree[right];
    }
  }

  PrintByLevel(tree[0]);

  PrintByLevel2(tree[0]);
  return 0;
}
