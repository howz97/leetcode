#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

std::vector<int> intersection(std::vector<std::vector<int>> sets) {
  int max = -1;
  for (int i = 0; i < sets.size(); i++) {
    if (sets[i].empty()) {
      return {};
    }
    max = std::max(max, sets[i][0]);
  }

  std::vector<size_t> cursors;
  cursors.resize(sets.size(), 0);
  std::vector<int> result;
  while (true) {
    for (int i = 0; i < sets.size(); i++) {
      auto &set = sets[i];
      while (set[cursors[i]] < max) {
        cursors[i]++;
        if (cursors[i] >= set.size()) {
          return result;
        }
      }
      if (set[cursors[i]] > max) {
        max = set[cursors[i]];
        i = -1;
      }
    }
    result.push_back(sets[0][cursors[0]]);
    for (int i = 0; i < cursors.size(); i++) {
      cursors[i]++;
      if (cursors[i] >= sets[i].size()) {
        return result;
      }
      max = std::max(max, sets[i][cursors[i]]);
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