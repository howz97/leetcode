#include <string>

int digit(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return -1;
}

int calculate(std::string s) {
  int result = 0;
  int prev_parsed = 0;

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
      result += prev_parsed;
      prev_parsed = -val;
    } else if (op == '*') {
      prev_parsed *= val;
    } else if (op == '/') {
      prev_parsed /= val;
    } else {
      result += prev_parsed;
      prev_parsed = val;
    }

    op = c;
    val = 0;
  }
  if (op == '-') {
    result += prev_parsed;
    prev_parsed = -val;
  } else if (op == '*') {
    prev_parsed *= val;
  } else if (op == '/') {
    prev_parsed /= val;
  } else {
    result += prev_parsed;
    prev_parsed = val;
  }
  result += prev_parsed;

  return result;
}