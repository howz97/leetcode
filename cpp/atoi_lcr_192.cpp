#include <cstdint>
#include <iostream>
#include <string>

int myAtoi(std::string str) {
  size_t i = 0;
  for (; i < str.size(); i++) {
    if (str[i] == ' ') {
      continue;
    }
    break;
  }

  bool negative = false;
  char c = str[i];
  if (c == '+') {
    i++;
  } else if (c == '-') {
    negative = true;
    i++;
  }

  int64_t result = 0;
  for (; i < str.size(); i++) {
    c = str[i];
    if (c >= '0' && c <= '9') {
      result *= 10;
      result += (c - '0');
      if (result > INT32_MAX) {
        break;
      }
    } else {
      break;
    }
  }
  if (negative) {
    result = -result;
  }
  result = std::max(result, int64_t(INT32_MIN));
  result = std::min(result, int64_t(INT32_MAX));
  return result;
}

int main() {
  std::cout << myAtoi("  -123") << std::endl;
  std::cout << myAtoi("+123  ") << std::endl;
  std::cout << myAtoi(" 0777  ") << std::endl;
  std::cout << myAtoi("9 +") << std::endl;
}