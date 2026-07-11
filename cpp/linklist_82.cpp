#include "linklist.h"
#include <iostream>

ListNode *deduplicate(ListNode *head) {
  ListNode dummy_head(0, head);
  ListNode *prev = &dummy_head;
  while (true) {
    ListNode *current = prev->next;
    if (current == nullptr) {
      return dummy_head.next;
    }

    ListNode *next = current->next;
    bool has_dup = false;
    while (next != nullptr && next->val == current->val) {
      has_dup = true;
      next = next->next;
    }
    if (has_dup) {
      prev->next = next;
    } else {
      prev = prev->next;
    }
    if (next == nullptr) {
      return dummy_head.next;
    }
  }
}

void testCase(const std::vector<int> &input) {
  ListNode *head = VecToList(input);
  head = deduplicate(head);
  while (head != nullptr) {
    std::cout << head->val << " ";
    head = head->next;
  }
  std::cout << std::endl;
}

int main() {
  testCase({1, 1, 2, 3, 3, 4, 6, 8, 8, 8, 9});
  testCase({1, 2, 3, 3, 4, 6, 8, 8, 8, 9, 9});
  testCase({1, 2, 3, 3, 4, 8, 8, 8, 9});
  testCase({1, 1, 2, 2, 3, 3, 3});
  testCase({1, 2, 3});
  return 0;
}
