#include <vector>

void dfs(std::vector<std::vector<char>> &grid, int r, int c) {
  grid[r][c] = '#';
  if (r > 0 && grid[r - 1][c] == '1') {
    dfs(grid, r - 1, c);
  }
  if (r + 1 < grid.size() && grid[r + 1][c] == '1') {
    dfs(grid, r + 1, c);
  }
  if (c > 0 && grid[r][c - 1] == '1') {
    dfs(grid, r, c - 1);
  }
  if (c + 1 < grid[0].size() && grid[r][c + 1] == '1') {
    dfs(grid, r, c + 1);
  }
}

int numIslands(std::vector<std::vector<char>> &grid) {
  size_t rows = grid.size();
  if (rows == 0) {
    return 0;
  }
  size_t cols = grid[0].size();
  if (cols == 0) {
    return 0;
  }
  size_t cnt = 0;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (grid[r][c] == '1') {
        dfs(grid, r, c);
        cnt++;
      }
    }
  }
  return cnt;
}