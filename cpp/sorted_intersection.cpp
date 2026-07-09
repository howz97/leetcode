#include <algorithm>
#include <climits>
#include <iostream>
#include <span>
#include <vector>

std::vector<int> intersection(std::vector<std::vector<int>> sets) {
  std::vector<std::span<int>> span_sets;
  span_sets.reserve(sets.size());
  int max = INT_MIN;
  for (int i = 0; i < sets.size(); i++) {
    std::vector<int> &set = sets[i];
    if (set.empty()) {
      return {};
    }
    max = std::max(max, set[0]);
    span_sets.push_back(set);
  }

  std::vector<int> result;
  while (true) {
    for (int i = 0; i < span_sets.size(); i++) {
      auto &set = span_sets[i];
      while (set[0] < max) {
        set = set.subspan(1);
        if (set.empty()) {
          return result;
        }
      }
      if (set[0] > max) {
        max = set[0];
        i = -1;
      }
    }
    result.push_back(span_sets[0][0]);
    for (int i = 0; i < span_sets.size(); i++) {
      auto &set = span_sets[i];
      set = set.subspan(1);
      if (set.empty()) {
        return result;
      }
      max = std::max(max, set[0]);
    }
  }
}

int main() {
  auto result = intersection({{1, 3, 5, 7, 9, 10, 11, 15, 16},
                              {1, 4, 5, 8, 10, 11, 15, 16},
                              {1, 2, 5, 6, 9, 10, 11, 16, 17}});
  for (auto e : result) {
    std::cout << e << ' ';
  }
  std::cout << std::endl;
}