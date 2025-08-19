#include <cassert>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *split(ListNode *head) {
  assert(head != nullptr);
  ListNode *fast = head;
  ListNode *slow = head;
  while (fast->next != nullptr && fast->next->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
  }
  ListNode *right_head = slow->next;
  slow->next = nullptr;
  return right_head;
}

ListNode *sortList(ListNode *head) {
  if (head == nullptr)
    return head;
  if (head->next == nullptr)
    return head;
  ListNode *head_right = split(head);
  ListNode *cur_left = sortList(head);
  ListNode *cur_right = sortList(head_right);

  ListNode dummy_head;
  ListNode *cur = &dummy_head;
  while (cur_left != nullptr && cur_right != nullptr) {
    if (cur_left->val < cur_right->val) {
      cur->next = cur_left;
      cur_left = cur_left->next;
    } else {
      cur->next = cur_right;
      cur_right = cur_right->next;
    }
    cur = cur->next;
  }
  if (cur_left != nullptr) {
    cur->next = cur_left;
  } else if (cur_right != nullptr) {
    cur->next = cur_right;
  }
  return dummy_head.next;
}