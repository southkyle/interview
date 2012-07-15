#include <iostream>
#include <cstring>
using namespace std;

#define arraysize(a) (sizeof(a)/sizeof(a[0]))

const char* key_pad[] = {
  "", // 0
  "", // 1
  "ABC", // 2
  "DEF", // 3
  "GHI", // 4
  "JKL", // 5
  "MNO", // 6
  "PQRS", // 7
  "TUV", // 8
  "WXYZ" // 9
};

void AllWords(int numbers[], int n, int depth, char words[]) {
  if (depth == n) {
    words[n] = '\0';
    cout << words << endl;
    return;
  }

  int digit = numbers[depth];
  for (int i = 0; i < strlen(key_pad[digit]); i++) {
    words[depth] = key_pad[digit][i];
    AllWords(numbers, n, depth + 1, words);
  }
}
    
int main(int argc, char *argv[]) {
  int numbers[] = {5,4,6,4,6,4};
  char words[20];
  AllWords(numbers, arraysize(numbers), 0, words);
  cout << arraysize(numbers) << endl;
  return 0;
}
