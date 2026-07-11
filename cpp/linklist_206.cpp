#include "linklist.h"

ListNode *reverseList(ListNode *head) {
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

int main() { return 0; }
