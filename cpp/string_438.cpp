#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> findAnagrams(std::string s, std::string p) {
  if (s.size() < p.size()) {
    return {};
  }
  std::vector<int> results;
  constexpr uint8_t total_letters = 'z' - 'a' + 1;
  uint16_t p_cnt[total_letters];
  uint16_t s_cnt[total_letters];
  std::memset(p_cnt, 0, sizeof(p_cnt));
  std::memset(s_cnt, 0, sizeof(s_cnt));
  size_t i = 0;
  for (; i < p.size(); i++) {
    p_cnt[p[i] - 'a']++;
    s_cnt[s[i] - 'a']++;
  }

  bool match = std::memcmp(p_cnt, s_cnt, sizeof(p_cnt)) == 0;
  if (match) {
    results.push_back(0);
  }
  for (; i < s.size(); i++) {
    if (match) {
      if (s[i] == s[i - p.size()]) {
        results.push_back(i - p.size() + 1);
      } else {
        match = false;
        s_cnt[s[i] - 'a']++;
        s_cnt[s[i - p.size()] - 'a']--;
      }
    } else {
      s_cnt[s[i] - 'a']++;
      s_cnt[s[i - p.size()] - 'a']--;
      match = std::memcmp(p_cnt, s_cnt, sizeof(p_cnt)) == 0;
      if (match) {
        results.push_back(i - p.size() + 1);
      }
    }
  }

  return results;
}

int main() {
  auto result = findAnagrams("cbaebabacd", "abc");
  for (auto i : result) {
    std::cout << i << ',';
  }
  std::cout << std::endl;
}