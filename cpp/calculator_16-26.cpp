#include <string>
#include <vector>

int digit(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return -1;
}

int calculate(std::string s) {
  std::vector<int> parsed;
  char op = '+';
  int val = 0;
  for (char c : s) {
    if (c == ' ') {
      continue;
    }
    if (int n = digit(c); n >= 0) {
      val = (val * 10) + n;
      continue;
    }

    if (op == '-') {
      val = -val;
    } else if (op == '*') {
      val = parsed.back() * val;
      parsed.pop_back();
    } else if (op == '/') {
      val = parsed.back() / val;
      parsed.pop_back();
    }
    parsed.push_back(val);

    op = c;
    val = 0;
  }
  if (op == '-') {
    val = -val;
  } else if (op == '*') {
    val = parsed.back() * val;
    parsed.pop_back();
  } else if (op == '/') {
    val = parsed.back() / val;
    parsed.pop_back();
  }
  parsed.push_back(val);

  int result = 0;
  for (int n : parsed) {
    result += n;
  }
  return result;
}