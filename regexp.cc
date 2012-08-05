#include "common.h"
#include <stack>

bool Match1(const char* text, const char* reg) {
  if (*reg == '\0') return true;
  else if (*reg == '*') {
    for (int i = 0; text[i] != '\0'; i++) {
      if (Match1(text + i, reg + 1)) {
        return true;
      }
    }
  } else if (*text == *reg) {
    return Match1(text + 1, reg + 1);
  }
  return false;
}

struct MatchPos {
  const char* text;
  const char* reg;
};

bool Match2(const char* text, const char* reg) {

  std::stack<MatchPos> s;
  do {
    if (*reg == '\0') {
      return true;
    } else if (*reg == '*'){
      MatchPos pos;
      pos.text = text;
      pos.reg = reg + 1;
      s.push(pos);
      reg++;
    } else if(*reg == *text) {
      reg++;
      text++;
    } else if(!s.empty()) {
      MatchPos pos = s.top();
      s.pop();
      reg = pos.reg;
      text = pos.text;
      if (pos.text != '\0' || pos.text + 1 != '\0') {
        pos.text++;
        s.push(pos);
      }
    } else {
      return false;
    }    
  } while (true);
  return false;
}

using namespace std;
int main(int argc, char *argv[]) {
  ASSERT_FALSE(Match1("abbbcd", "a*bc*z"));
  ASSERT_TRUE(Match1("abbbcdz", "a*bc*z"));
  ASSERT_TRUE(Match1("ab", "*ab"));
  ASSERT_TRUE(Match1("dab", "*ab"));
  ASSERT_TRUE(Match1("efghaab", "*ab"));
  ASSERT_TRUE(Match1("aab", "*ab"));
  ASSERT_TRUE(Match1("abc", "*ab"));

  ASSERT_FALSE(Match2("abbbcd", "a*bc*z"));
  ASSERT_TRUE(Match2("abbbcdz", "a*bc*z"));
  ASSERT_TRUE(Match2("ab", "*ab"));
  ASSERT_TRUE(Match2("dab", "*ab"));
  ASSERT_TRUE(Match2("efghaab", "*ab"));
  ASSERT_TRUE(Match2("aab", "*ab"));
  ASSERT_TRUE(Match2("abc", "*ab"));
  return 0;
}

