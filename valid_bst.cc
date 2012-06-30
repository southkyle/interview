#include <iostream>
#include <vector>
#include <climits>
#include <cassert>
using namespace std;

struct TreeNode {
  TreeNode* left;
  TreeNode* right;
  int data;
  TreeNode(int d): left(NULL), right(NULL), data(d) {
  }
};

// Method1 InOrder tree dump to an array
// Check if the array is orderd.
// time  O(n)
// space O(n)

// Method2 InOrder search, check while searching

// Method3


void InOrder(TreeNode* t, vector<int>* array) {
  if (t != NULL) {
    InOrder(t->left, array);
    array->push_back(t->data);
    InOrder(t->right, array);
  }
}

bool ValidBinarySearchTree1(TreeNode* t) {
  std::vector<int> array;
  InOrder(t, &array);
  // check if the array is ordered
  for (int i = 0; i < array.size() - 2; i++) {
    if (array[i] > array[i+1]) {
      return false;
    }
  }
  return true;
}



bool InOrder2(TreeNode* t, TreeNode** pre_node) {
  if (t != NULL) {
    if(!InOrder2(t->left, pre_node)) {
      return false;
    }

    // Check current data
    if (*pre_node != NULL) {
      if (t->data < (*pre_node)->data) {
	return false;
      }
    }

    // Update pre_node
    *pre_node = t;

    if(!InOrder2(t->right, pre_node)) {
      return false;
    }
  }

  return true;
}

bool ValidBinarySearchTree2(TreeNode* t) {
  TreeNode* pre_node = NULL;
  return InOrder2(t, &pre_node);
}

bool InOrder3(TreeNode* t, int min_num, int max_num) {
  if (t != NULL) {
    if (t->data < min_num || t->data > max_num) {
      return false;
    }
    return InOrder3(t->left, min_num, t->data) &&
           InOrder3(t->right, t->data, max_num);
  }
  return true;
}

bool ValidBinarySearchTree3(TreeNode* t) {
  return InOrder3(t, INT_MIN, INT_MAX);
}

//      30
//  25      50
// 23 29   40  80
//1 24

int main(int argc, char *argv[]) {
  TreeNode* n30 = new TreeNode(30);
  TreeNode* n25 = new TreeNode(25);
  TreeNode* n50 = new TreeNode(50);
  TreeNode* n23 = new TreeNode(23);
  TreeNode* n29 = new TreeNode(29);
  TreeNode* n40 = new TreeNode(40);
  TreeNode* n80 = new TreeNode(80);
  TreeNode* n1 = new TreeNode(1);
  TreeNode* n24 = new TreeNode(24);

  n30->left = n25;
  n30->right = n50;

  n25->left = n23;
  n25->right = n29;

  n50->left = n40;
  n50->right = n80;

  n23->left = n1;
  n23->right = n24;

  bool b1 = ValidBinarySearchTree1(n30);
  bool b2 = ValidBinarySearchTree2(n30);
  bool b3 = ValidBinarySearchTree3(n30);

  assert(b1);
  assert(b2);
  assert(b3);
  return 0;
}
