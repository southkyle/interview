#include <iostream>

class StringPiece {
  char* data;
  size_t len;
};

class LRUCache {
 public:
  void Get(const StringPiece& key, StringPiece* value);
  void Set(const StringPiece& key, const StringPiece& value);
  void Add(const StringPiece& key, const StringPiece& value);
 private:
  
};


typedef int Key;
typedef int Value;

struct Node {
  Node():pre(NULL), next(NULL) {}
  Key key;
  Value value;
  Node* pre;
  Node* next;
  
};

void Remove(Node* n) {
  n->pre->next = n->next;
  n->next->pre = n->pre;
}

void Add(Node* head, Node* n) {
  n->next = head;
  n->pre = NULL;
  head->pre = n;
}

class LRUCache {
 public:
  bool Get(const Key& key, Value* value);
  void Set(const Key& key, const Value& value);
 private:
  Node head;
  hashmap<Key, Node*> map_;
};



bool LRUCache::Get(const Key& key, Value* value) {
  if (map_.find(key)) {
    Remove(n);
    Add(&head, n);
  } else {
    return false;
  }
}

void LRUCache::Set(const Key& key, const Value& value) {
  Value v;
  bool found = this->Get(key, &v);
  if (found) {
    Remove(n);
    Add(&head, n);
  } else {
    Node* n = new Node(key, value);
    Add(&head, n);
    map_.set(key, n);
  }
}

