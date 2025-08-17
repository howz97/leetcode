struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head) {
  ListNode dummy_head(0, head);
  ListNode *prev = &dummy_head;
  while (true) {
    if (prev->next == nullptr) {
      return dummy_head.next;
    }
    if (prev->next->next == nullptr) {
      return dummy_head.next;
    }
    while (prev->next->val != prev->next->next->val) {
      prev = prev->next;
      if (prev->next->next == nullptr) {
        return dummy_head.next;
      }
    }
    ListNode *del_end = prev->next->next;
    while (del_end->next != nullptr && del_end->val == del_end->next->val) {
      del_end = del_end->next;
    }
    prev->next = del_end->next;
  }
}