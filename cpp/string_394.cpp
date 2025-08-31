#include <cassert>
#include <string>

int toDigit(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return -1;
}

std::string decode(std::string_view s) {
  std::string result;
  size_t repeat = 0;
  for (int i = 0; i < s.size(); i++) {
    int n = toDigit(s[i]);
    if (n >= 0) {
      repeat = (repeat * 10) + n;
      continue;
    }
    if (repeat == 0) {
      result.push_back(s[i]);
      continue;
    }
    assert(s[i] == '[');
    size_t sub_begin = i + 1;
    size_t left_brace = 1;
    while (left_brace > 0) {
      i++;
      if (s[i] == '[') {
        left_brace++;
      } else if (s[i] == ']') {
        left_brace--;
      }
    }
    assert(s[i] == ']');
    std::string sub_str = decode(s.substr(sub_begin, i - sub_begin));
    for (size_t j = 0; j < repeat; j++) {
      result.append(sub_str);
    }
    repeat = 0;
  }
  return result;
}

std::string decodeString(std::string s) { return decode(s); }