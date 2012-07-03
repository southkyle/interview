#include <iostream>
using namespace std;

struct Node {
  Node* next;
  int data;
};

typedef Node* List;

List Reverse(List l) {
  Node* pre = NULL;
  Node* current = l;
  while (current != NULL) {
    Node* tmp = current->next;
    current->next = pre;
    pre = current;
    current = tmp;
  }
  return pre;
}


struct DoubleLinkedNode {
  Node* pre;
  Node* next;
  int data;
};

typedef DoubleLinkedNode* DoubleLinkedList;

DoubleLinkedList Reverse(DoubleLinkedList list) {
  return NULL;
}

DoubleLinkedList BuildDoubleLinkedList() {
  return NULL;
}

void PrintDoubleLinkedList(DoubleLinkedList list) {
  
}

List BuildList() {
  Node* last = new Node;
  last->data = 10;
  last->next = NULL;
  for (int i = 9; i >= 0; i--) {
    Node* n = new Node;
    n->data = i;
    n->next = last;
    last = n;
  }
  return last;
}

void Print(List l) {
  cout << "List ";
  Node* n = l;
  while (n != NULL) {
    cout << n->data << " ";
    n = n->next;
  }
  cout << endl;
}
int main(int argc, char *argv[]) {
  List l = BuildList();
  Print(l);
  l = Reverse(l);
  Print(l);
  return 0;
}
