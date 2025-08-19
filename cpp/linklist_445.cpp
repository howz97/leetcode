struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  l1 = reverseList(l1);
  l2 = reverseList(l2);
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
  return reverseList(dummy_head.next);
}