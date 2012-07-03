#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

void test_vector() {
  std::vector<int> nums(10);
  cout << "nums.size() " << nums.size() << endl;
  nums.push_back(10);
  cout << "nums.size() " << nums.size() << endl;
  copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  vector<vector<int> > two_dimmention(100, vector<int>(50, 0));
  
}

void test_string() {
  
}

int main(int argc, char *argv[]) {
  test_vector();
  return 0;
}
