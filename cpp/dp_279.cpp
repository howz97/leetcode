#include <vector>
int numSquares(int n) {
  std::vector<int> result(n + 1);
  for (int i = 0; i <= n; i++) {
    result[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    int min_result = result[i];
    for (int j = 1; j * j <= i; j++) {
      min_result = std::min(min_result, result[i - j * j] + 1);
    }
    result[i] = min_result;
  }
  return result[n];
}