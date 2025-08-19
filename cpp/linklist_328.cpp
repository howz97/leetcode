#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *oddEvenList(ListNode *head) {
  if (head == nullptr || head->next == nullptr)
    return head;
  ListNode *odd_tail = head;
  ListNode *even_head = head->next;
  ListNode *even_tail = head->next;

  bool odd_cur = true;
  ListNode *cur = head->next->next;
  while (cur != nullptr) {
    if (odd_cur) {
      odd_tail->next = cur;
      odd_tail = cur;
    } else {
      even_tail->next = cur;
      even_tail = cur;
    }
    odd_cur = !odd_cur;
    cur = cur->next;
  }
  odd_tail->next = even_head;
  even_tail->next = nullptr;
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