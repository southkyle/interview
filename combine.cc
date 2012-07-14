#include <iostream>
#include <vector>
using namespace std;

void Combine(int v[], int n, int m, int m2, int a[]) {
  if (m == 0) {
    for (int i = m2; i >= 1; i--) {
      cout << a[i] << " ";
    }
    cout << endl;
    return;
  }

  for (int i = n-1; i >= m-1; i--) {
    a[m] = v[i];
    Combine(v, i, m - 1, m2, a);
  }
}

void Combine2(const std::vector<int>& v, int n, int m, int orignal_m,
              std::vector<int>* tmp,
              std::vector<std::vector<int> >* result) {
  if (m == 0) {
    for (int i = orignal_m - 1; i>=0; i--) {
      result->push_back(*tmp);
      return;
    }
  }
  for (int i = n - 1; i >= m-1; i--) {
    (*tmp)[m-1] = v[i];
    Combine2(v, i, m-1, orignal_m, tmp, result);
  }
}

int main(int argc, char *argv[]) {
  int v[] = {1, 2, 3, 4, 5};
  int a[10];
  Combine(v, 5, 2, 2, a);

  vector<int> in(v, v+5);
  vector<int> tmp(2);
  vector<vector<int> > result;
  Combine2(in, in.size(), 2, 2, &tmp, &result);
  cout << "result size " << result.size() << endl;
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
