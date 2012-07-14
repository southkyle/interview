#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdint.h>
#include <cmath>
using namespace std;

#define ASSERT_EQ(a, b)                                 \
  if ((a) != (b)) {                                     \
    cout << "FAIL " << #a << "!=" << #b << endl;        \
        exit(1);                                        \
  }  else {                                             \
    cout << "OK" << endl;;                              \
  }

const double kEPS = 1e-6;
const int kCardsNumber = 4;
const int result_value = 24;
double number[kCardsNumber];
string result[kCardsNumber];

bool PointsGame(int n) {
  if (n == 1) {
    if (fabs(number[0] - result_value) < kEPS) {
      cout << result[0] << endl;
      return true;
    } else {
      return false;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      double a, b;
      string expa, expb;

      a = number[i];
      b = number[j];
      number[j] = number[n-1];

      expa = result[i];
      expb = result[j];
      result[j] = result[n-1];

      result[i] = '(' + expa + '+' + expb + ')';
      number[i] = a+b;
      if (PointsGame(n - 1)) {
        return true;
      }

      result[i] = '(' + expa + '-' + expb + ')';
      number[i] = a - b;
      if (PointsGame(n - 1)) {
        return true;
      }

      result[i] = '(' + expb + '-' + expb + ')';
      number[i] = b - a;
      if (PointsGame(n - 1)) {
        return true;
      }
      
      result[i] = '(' + expa + '*' + expb + ')';
      number[i] = a * b;
      if (PointsGame(n - 1)) {
        return true;
      }

      if (fabs(a) > kEPS) {
        result[i] = '(' + expb + '/' + expa + ')';
        number[i] = b / a;
        if (PointsGame(n - 1)) {
          return true;
        }
      }

      if (fabs(b) > kEPS) {
        result[i] = '(' + expa + '/' + expb + ')';
        number[i] = a / b;
        if (PointsGame(n - 1)) {
          return true;
        }
      }

      number[i] = a;
      number[j] = b;
      result[i] = expa;
      result[j] = expb;
    }
  }

  return false;
}

int main() {

  for (int i = 0; i < kCardsNumber; i++) {
    int x;
    char buffer[20];
    cin >> x;
    number[i] = x;
    sprintf(buffer, "%d", x);
    result[i] = buffer;
  }

  if (PointsGame(kCardsNumber)) {
    cout << "Sucess" << endl;
  } else {
    cout << "Fail" << endl;
  }
  return 0;
}

