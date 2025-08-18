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