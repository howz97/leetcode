#include "linklist.h"

ListNode *middleNode(ListNode *head) {
  ListNode *slow = head;
  ListNode *fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next;
    if (fast->next != nullptr)
      fast = fast->next;
    else
      break;
  }
  return slow;
}

int main() { return 0; }
