#include <iostream>
#include <map>
#include <list>
#include <cassert>
// #include <unordered_map>
using namespace std;

template <class KeyType, class ValueType>
class LRUCache {
 public:
  LRUCache(size_t max_size) : max_size_(max_size) {
  }
  
  void Put(const KeyType& key, const ValueType& value) {
    cout << "Before put " << endl;
    Print(list_);
    typename MapIndex::iterator index_iter = index_.find(key);
    if (index_iter != index_.end()) {
      // Delete the old item
      Erase(index_iter->second);
    } else {
      ShrinkToSize(max_size_ - 1);
    }
    
    list_.push_front(value_type(key, value));
    index_.insert(std::make_pair(key, list_.begin()));
    cout << "After Put " << endl;
    Print(list_);
  }
  
  ValueType* Get(const KeyType& key) {
    typename MapIndex::iterator index_iter = index_.find(key);
    if (index_iter == index_.end()) {
      return NULL;
    }
    list_.splice(list_.begin(), list_, index_iter->second);
    index_[key] = list_.begin();
    //    Print(list_);
    return &(list_.begin()->second);
  }
  
 private:
  typedef std::pair<KeyType, ValueType> value_type;
  typedef std::list<value_type> PayLoadList;
  typedef std::map<KeyType, typename PayLoadList::iterator> MapIndex;
  PayLoadList list_;
  MapIndex index_;
  size_t max_size_;
  void Erase(typename PayLoadList::iterator iter) {
    index_.erase(iter->first);
    list_.erase(iter);
  }

  void Erase(typename PayLoadList::reverse_iterator iter) {
    Erase((++iter).base());
  }
  void ShrinkToSize(size_t new_size) {
    for (size_t i = list_.size(); i > new_size; i--) {
      Erase(list_.rbegin());
    }
  }
  void Print(const PayLoadList& l) {
    cout << "***" << endl;
    for (typename PayLoadList::const_iterator i = l.begin(); i != l.end(); ++i) {
      cout << i->first << " : " << i->second << endl;
    }
    cout << "***" << endl;
  }
};

int main(int argc, char *argv[]) {
  LRUCache<int, int> cache(3);
  int* v;
  cache.Put(1, 1);
  v =  cache.Get(1);
  assert(v != NULL);
  assert( *v == 1);
  
  cache.Put(2, 2);
  v = cache.Get(2);
  assert(v != NULL);
  cout << *v << endl;
  assert(*v == 2);

  // v = cache.Get(3);
  // assert( v == NULL);
  return 0;
}
