#include <iostream>
#include <vector>

int lengthOfLIS(std::vector<int> &nums) {
  std::vector<int> dp(nums.size(), 1);
  for (int i = 0; i < nums.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (nums[i] > nums[j]) {
        dp[i] = std::max(dp[i], dp[j] + 1);
      }
    }
  }
  int max_len = 0;
  for (int n : dp) {
    max_len = std::max(max_len, n);
  }
  return max_len;
}

int main() {
  std::vector<int> nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};
  std::cout << lengthOfLIS(nums) << std::endl;
  return 0;
}