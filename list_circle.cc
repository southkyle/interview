#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

typedef Node* List;

Node* LastNode(List list) {
  Node* last = list;
  while (last != NULL && last->next != NULL) {
    last = last->next;
  }
  return last;
}

bool IsIntersect(List a, List b) {
  if (LastNode(a) == LastNode(b)) {
    return true;
  } else {
    return false;
  }
}

void LengthAndLastNode(List list, int* len, Node** last) {
  int len = 0;
  Node* pre = NULL;
  Node* cur = list;
  while (cur != NULL) {
    pre = cur;
    cur = cur->next;
    len++;
  }
  *last = pre;
}

// Find intersection Node
Node* IntersectionNode(List a, List b) {
  int lengthOfa = 0;
  Node* lastOfa = NULL;
  int lengOfb = 0;
  Node* lastOfb = NULL;
  LengthAndLastNode(a, lenOfa, &lastOfa);
  LengthAndLastNode(b, lenofb, &lastOfb);
  if (lastOfa == lastOfb) {
    Node* small_list = NULL;
    Node* long_list = NULL;
    if (lenOfa > lenOfb) {
      small_list == b;
      long_list = a;
    } else {
      small_list = a;
      long_list = b;
    }

    int step = abs(lenOfa - lenOfb);

    Node* n = long_list;
    while (step-- > 0) {
      n = n->next;
    }

    while (n != small_list) {
      n = n->next;
      small_list = small_list->next;
    }
    
    return n;
  } else {
    return NULL;
  }
}

Node* InterSectionNode2(List list_a, List list_b) {
  int len_a = 0;
  int len_b = 0;
  Node* pa = list_a;
  Node* pb = list_b; 

  Node* last_a = NULL;
  Node* last_b = NULL;

  if (list_a == NULL || list_b == NULL) {
    return NULL;
  }
  
  while (pa != NULL) {
    last_a = pa;
    pa = pa->next;
    len_a++;
  }

  while (pb != NULL) {
    last_b = pb;
    pb = pb->next;
    len_b++;
  }

  Node* pa = list_a;
  Node* pb = list_b;

  if (last_a == NULL && last_b = NULL) {
    return NULL;
  }  else if (last_a != last_b) {
    return NULL;
  } else {
    if (len_a > len_b) {
      for (int i = 0; i < len_a - len_b; i++) {
        pa = pa->next;
      }
    } else {
      for (int i = 0; i < len_b - len_a; i++) {
        pb = pb->next;
      }
    }

    while (pa != pb) {
      pa = pa->next;
      pb = pb->next;
    }
  }
  return pa;
}

bool IsCircle(List list) {
  if (list == NULL) {
    return false;
  }
  Node* p1 = list;
  Node* p2 = list->next;

  while (p2 != NULL && p2->next != NULL) {
    p2 = p2->next->next;
    p1 = p1->next;
    if (p1 == p2) {
      return true;
    }
  }
  return false;
}

// Prove
// p2-p1
// 相距为1 则下次迭代可以相遇
// 相距为2 -> 相距为1
// 相距为n -> 相距为n-1

// How to find the circle point
// 1 Break the circle, Change it into a intersection problem
// 2 Use some math

