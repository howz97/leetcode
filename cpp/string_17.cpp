#include <string>
#include <vector>

const std::vector<std::string> buttons = {"",    "",    "abc",  "def", "ghi",
                                          "jkl", "mno", "pqrs", "tuv", "wxyz"};

void dfs(std::string &prefix, std::string &digits, size_t depth,
         std::vector<std::string> &result) {
  if (depth == digits.size()) {
    result.push_back(prefix);
    return;
  }
  for (char c : buttons[digits[depth] - '0']) {
    prefix.push_back(c);
    dfs(prefix, digits, depth + 1, result);
    prefix.pop_back();
  }
}

std::vector<std::string> letterCombinations(std::string digits) {
  std::vector<std::string> result;
  if (!digits.empty()) {
    std::string prefix;
    dfs(prefix, digits, 0, result);
  }
  return result;
}