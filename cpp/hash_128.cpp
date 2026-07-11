#include <unordered_set>
#include <vector>

int longestConsecutive(std::vector<int> &nums) {
  std::unordered_set<int> nums_set;
  nums_set.reserve(nums.size());
  for (const int &n : nums) {
    nums_set.insert(n);
  }

  // Iterate nums_set should be more friendly to CPU cache.
  int longest = 0;
  for (const int &n : nums_set) {
    if (!nums_set.contains(n - 1)) {
      int m = n + 1;
      while (nums_set.contains(m)) {
        m++;
      }
      longest = std::max(longest, m - n);
    }
  }
  return longest;
}