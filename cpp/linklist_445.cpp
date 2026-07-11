#include "linklist.h"

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  l1 = ReverseList(l1);
  l2 = ReverseList(l2);
  ListNode dummy_head;
  ListNode *cur = &dummy_head;
  bool carry = false;
  while (l1 != nullptr || l2 != nullptr || carry) {
    int val = 0;
    if (l1 != nullptr) {
      val += l1->val;
      l1 = l1->next;
    }
    if (l2 != nullptr) {
      val += l2->val;
      l2 = l2->next;
    }
    if (carry) {
      carry = false;
      val++;
    }
    if (val >= 10) {
      val -= 10;
      carry = true;
    }
    cur->next = new ListNode(val);
    cur = cur->next;
  }
  return ReverseList(dummy_head.next);
}

int main() { return 0; }
