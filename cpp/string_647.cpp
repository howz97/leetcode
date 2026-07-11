#include <string>

size_t countFromCenter(const std::string &s, int i, int j) {
  size_t cnt = 0;
  while (i >= 0 && j < s.size() && s[i] == s[j]) {
    cnt++;
    i--;
    j++;
  }
  return cnt;
}

int countSubstrings(std::string s) {
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    cnt += countFromCenter(s, i, i);
  }
  for (int i = 0; i < s.size() - 1; i++) {
    cnt += countFromCenter(s, i, i + 1);
  }
  return cnt;
}