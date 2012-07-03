#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;


// state machine


// |-------------+------------------------+------------+----------------|
// | state       | space                  | not space  | end            |
// |-------------+------------------------+------------+----------------|
// | space state | space state            | word state | end            |
// | word state  | Reverse -> space state | word state | Reverse -> end |
// | end state   | x                      | x          | x              |

char* ReverseWords(char* text) {
  enum State {kSpaceState, kWordState, kEndState};
  State state = kSpaceState;
  int len = strlen(text);
  int word_start = 0;
  for (int i = 0; i <= len; i++) {
    switch (state) {
      case kSpaceState:
        if (text[i] == ' ') {
          // do nothing
        } else if (text[i] == '\0') {
          return text;
        } else {
          state = kWordState;
          word_start = i;
        }
        break;
      case kWordState:
        if (text[i] == ' ') {
          std::reverse(&text[word_start], &text[i]);
          state = kSpaceState;
        } else if (text[i] == '\0') {
          std::reverse(&text[word_start], &text[i]);
          return text;
        } else {
          // do nothing
        }
        break;
    }
  }
  return text;
}

char* ReverseWords2(char* text) {
  int i = 0;
  int j = 0;
  while (true) {
    while (text[i] != '\0' && isspace(text[i])) {i++;}
    if (text[i] == '\0') break;
    for (j = i+1; text[j] != '\0' && !isspace(text[j]); j++) {}
    std::reverse(&text[i], &text[j]);
    if (text[j] == '\0') break;
    i = j+1;
  }
  return text;
}

int main(int argc, char *argv[]) {
  char text1[] = {"I love apple"};
  char text2[] = {"who are you"};

  assert(strcmp(ReverseWords(text1), "I evol elppa") == 0);
  assert(strcmp(ReverseWords(text2), "ohw era uoy") == 0);

  assert(strcmp(ReverseWords2(text1), "I love apple") == 0);
  assert(strcmp(ReverseWords2(text2), "who are you") == 0);
  cout << text1 << endl;
  cout << text2 << endl;
  return 0;
}

