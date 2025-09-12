#include <vector>

int maxProfit(std::vector<int> &prices) {
  if (prices.size() <= 1) {
    return 0;
  }
  int max_profix = 0;
  int min_buy = prices[0];
  for (int i = 1; i < prices.size(); i++) {
    max_profix = std::max(max_profix, prices[i] - min_buy);
    min_buy = std::min(min_buy, prices[i]);
  }
  return max_profix;
}