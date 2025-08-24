#include <iostream>
#include <string>
#include <vector>

int lengthLongestPath(std::string input) {
  std::vector<int> stack;
  int stack_top = 0;
  int name_len = 0;
  bool is_file = false;
  int max_len = 0;
  for (char c : input) {
    switch (c) {
    case '\n': {
      if (is_file) {
        int len = name_len;
        for (int j = 0; j < stack_top; j++) {
          len += stack[j] + 1;
        }
        max_len = std::max(max_len, len);
      } else {
        if (stack_top < stack.size()) {
          stack[stack_top] = name_len;
        } else {
          stack.push_back(name_len);
        }
      }
      stack_top = 0;
      name_len = 0;
      is_file = false;
      break;
    }
    case '\t':
      stack_top++;
      break;
    default:
      name_len++;
      if (c == '.') {
        is_file = true;
      }
      break;
    }
  }
  if (is_file) {
    int len = name_len;
    for (int j = 0; j < stack_top; j++) {
      len += stack[j] + 1;
    }
    max_len = std::max(max_len, len);
  }
  return max_len;
}

int main() {
  std::string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
  int result = lengthLongestPath(input);
  std::cout << "Length of longest path: " << result << std::endl;
  return 0;
}