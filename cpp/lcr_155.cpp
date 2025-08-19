// Definition for a Node.
#include <utility>
class Node {
public:
  int val;
  Node *left;
  Node *right;

  Node() {}

  Node(int _val) {
    val = _val;
    left = nullptr;
    right = nullptr;
  }

  Node(int _val, Node *_left, Node *_right) {
    val = _val;
    left = _left;
    right = _right;
  }
};

std::pair<Node *, Node *> dfs(Node *node) {
  Node *min, *max;

  if (node->left == nullptr) {
    min = node;
  } else {
    auto [l_min, l_max] = dfs(node->left);
    l_max->right = node;
    node->left = l_max;
    min = l_min;
  }

  if (node->right == nullptr) {
    max = node;
  } else {
    auto [r_min, r_max] = dfs(node->right);
    r_min->left = node;
    node->right = r_min;
    max = r_max;
  }

  return {min, max};
}

Node *treeToDoublyList(Node *root) {
  if (root == nullptr)
    return nullptr;
  auto [head, tail] = dfs(root);
  head->left = tail;
  tail->right = head;
  return head;
}