#include <iostream>
using namespace std;

class BigInt {
 public:
  BigInt(): size(1) {
    digit[0] = 0;
  }
  BigInt(int x);
  BigInt(const char* s);
  BigInt(const std::string& s);
  BigInt(const BigInt& rhs);
  std::string ToString() const;
  BigInt& operator = (const BigInt& b);
  BigInt& operator = (const char* s);
  BigInt& operator = (const std::string& s);
  BigInt operator + (const BigInt& b) const;
  BigInt& operator += (const BigInt& b);
  BigInt operator - (const BigInt& b) const;
  BigInt& operator -= (const BigInt& b);
  BigInt operator * (const BigInt& b) const;
  BigInt& operator *= (const BigInt& b);
  BigInt operator / (const BigInt& b) const;
  BigInt& operator /= (const BigInt& b);
  bool operator == (const BigInt& b) const;
  bool operator != (const BigInt& b) const;
  bool operator < (const BigInt& b) const;
  bool operator <= (const BigInt& b) const;
  bool operator > (const BigInt& b) const;
  bool operator >= (const BigInt& b) const;
 private:
  const static int kMaxDigit = 1000;;
  int size;
  int digit[kMaxDigit];
};

// BigInt BigInt::operator + (const BigInt& b) {
//   BigInt sum;
//   sum.digit[0] = 0;
//   for (int i = 0; i < min(size, b.size); i++) {
//     int r = digit[i] + b.digit[i] + sum.digit[i];
//     sum[i] = r % 10;
//     sum[i+1] = r / 10;
//   }

//   while (i < size) {
//     int r = digit[i] + sum[i];
//     sum[i] = r % 10;
//     sum[i+1] = r / 10;
//     i++;
//   }

//   while (i < b.size) {
//     int r = digit[i] + b.sum[i];
//     sum[i] = r % 10;
//     sum[i+1] = r / 10;
//     i++;
//   }
//   while (sum[i] == 0) {
//     i--;
//   }
//   sum.size = i+1;
//   return sum;
// }

// BigInt BigInt::operator + (const BigInt& b) {
//   BigInt sum;
//   int carry = 0;
//   for (int i = 0; i < min(size, b.size); i++) {
//     int r = digit[i] + b.digit[i] + carry;
//     sum[i] = r % 10;
//     carry = r / 10;
//   }

//   while (i < size) {
//     int r = digit[i] + carry;
//     sum[i] = r % 10;
//     carry = r / 10;
//     i++;
//   }
//   while (i < b.size) {
//     int r = b.digit[i] + carry;
//     sum[i] = r % 10;
//     carry = r / 10;
//     i++;
//   }
//   if (carry != 0) {
//     sum.digit[i] = carry;
//     i++;
//   }
//   sum.size = i;
//   return sum;
// }

// BigInt BigInt::operator + (const BigInt& b) {
//   BigInt sum;
//   int carry = 0;
//   for (int i = 0; i < max(size, b.size); i++) {
//     int r = 0;
//     if (i < size)  r += digit[i];
//     if (i < b.size) r += b.digit[i];
//     r += carry;
//     sum.digit[i] = r % 10;
//     carry = r / 10;
//   }

//   if (carry != 0) {
//     sum.digit[i] = carry;
//     i++;
//   }

//   sum.size = i;
//   return sum;
// }

// BigInt BigInt::operator * (const BigInt& b) {
//   BigInt product;
//   Init(&product);
//   for (int i = 0; i < b.size; i++) {
//     for (int j = 0; j < size; j++) {
//       int r = b.digit[i] * digit[j];
//       product[i + j] += r;
//       Reduce(&product, i+j);
//     }
//   }
//   return product;
// }

// void Reduce(BigInt* num, int index) {
//   while (num->digit[index] > 10) {
//     int r = num->digit[index];
//     num->digit[index] = r % 10;
//     num->digit[index+1] += r / 10;
//     index++;
//   }
//   if (num->digit[index] != 0) {
//     num->size = index;
//   } else {
//     num->size = index - 1;
//   }
// }

// void Init(BigInt* num) {
//   num->size = 0;
//   memeset(num->digit, 0, sizeof(num->digit));
// }


// BigInt BigInt::operator * (const BigInt& b) {
//   BigInt prod;
//   for (int i = 0; i < b.size + size; i++) {
//     prod.digit[i] = 0;
//   }

//   for (int i = 0; i < size; i++) {
//     for (int j = 0; j < b.size; j++) {
//       int r = digit[i] * b.digit[j] + prod.digit[i+j];
//       prod.digit[i+j] = r % 10;
//       prod.digit[i+j+1] += r / 10;
//     }
//   }
//   prod.size = size + b.size;
//   while (prod.size > 1 && prod.digit[prod.size - 1] > 0) {
//     prod.size--;
//   }
//   return prod;
// }


// BigInt BigInt::operator / (const BigInt& b) {

// }
