#include <algorithm>
#include <vector>

void dfs(std::vector<int> &candidates, size_t idx, std::vector<int> &prefix,
         int target, std::vector<std::vector<int>> &results) {
  if (idx == candidates.size()) {
    return;
  }
  const int cand = candidates[idx];
  if (target < cand) {
    return;
  }
  size_t origin_size = prefix.size();
  while (target >= cand) {
    dfs(candidates, idx + 1, prefix, target, results);
    prefix.push_back(cand);
    target -= cand;
  }
  if (target == 0) {
    results.push_back(prefix);
  }
  prefix.resize(origin_size);
}

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                             int target) {
  std::sort(candidates.begin(), candidates.end());
  std::vector<std::vector<int>> results;
  std::vector<int> prefix;
  dfs(candidates, 0, prefix, target, results);
  return results;
}