#include "linklist.h"
#include <iostream>

ListNode *oddEvenList(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  ListNode *even_head = head->next;

  bool right_is_even = true;
  ListNode *left = head;
  ListNode *right = even_head;
  while (right->next != nullptr) {
    left->next = right->next;
    left = right;
    right = right->next;
    right_is_even = !right_is_even;
  }

  if (right_is_even) {
    left->next = even_head;
  } else {
    left->next = nullptr;
    right->next = even_head;
  }
  return head;
}

int main() {
  ListNode nodes[5];
  for (int i = 0; i < 5; i++) {
    nodes[i].val = i + 1;
    if (i < 4) {
      nodes[i].next = &nodes[i + 1];
    }
  }

  ListNode *head = &nodes[0];
  ListNode *cur = oddEvenList(head);
  while (cur != nullptr) {
    std::cout << cur->val;
    cur = cur->next;
  }
}