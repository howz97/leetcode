#include "binary_tree.h"
#include <algorithm>

int dfs(TreeNode *root, int &max_diameter) {
  if (root == nullptr) {
    return -1;
  }
  int left_height = dfs(root->left, max_diameter);
  int right_height = dfs(root->right, max_diameter);
  int diameter = left_height + right_height + 2;
  max_diameter = std::max(max_diameter, diameter);
  return std::max(left_height, right_height) + 1;
}

int diameterOfBinaryTree(TreeNode *root) {
  int max_diameter = -1;
  dfs(root, max_diameter);
  return max_diameter;
}