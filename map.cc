#include <iostream>
#include <map>
using namespace std;

int main() {
  map<char, int> mymap;
  map<char, int>::iterator it;

  mymap['a'] = 50;
  mymap['b'] = 100;
  mymap['c'] = 150;
  mymap['d'] = 200;

  it = mymap.find('b');

  cout << it->first << ", " << it->second << endl;

  it = mymap.find('f');
  cout << it->first << ", " << it->second << endl;

  for (it = mymap.begin(); it != mymap.end(); it++) {
    cout << it->first << "=>" << it->second << endl;
  }
  return 0;
}
