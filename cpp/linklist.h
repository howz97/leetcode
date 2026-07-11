#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline ListNode *VecToList(const std::vector<int> &values) {
  if (values.empty()) {
    return nullptr;
  }
  ListNode *head = new ListNode(values[0]);
  ListNode *current = head;
  for (size_t i = 1; i < values.size(); ++i) {
    current->next = new ListNode(values[i]);
    current = current->next;
  }
  return head;
}

inline ListNode *ReverseList(ListNode *head) {
  if (head == nullptr) {
    return head;
  }
  ListNode *prev = nullptr;
  ListNode *cur = head;
  ListNode *next = cur->next;
  while (next != nullptr) {
    cur->next = prev;
    prev = cur;
    cur = next;
    next = next->next;
  }
  cur->next = prev;
  return cur;
}