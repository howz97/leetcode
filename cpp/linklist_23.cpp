#include "linklist.h"
#include <queue>

ListNode *mergeKLists(std::vector<ListNode *> &lists) {
  auto cmp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
  std::priority_queue<ListNode *, std::vector<ListNode *>, decltype(cmp)> pq(
      cmp);
  for (ListNode *head : lists) {
    if (head != nullptr) {
      pq.push(head);
    }
  }
  ListNode dummy_head;
  ListNode *tail = &dummy_head;
  while (!pq.empty()) {
    auto min = pq.top();
    pq.pop();
    tail->next = min;
    tail = min;
    if (min->next != nullptr) {
      pq.push(min->next);
    }
  }
  return dummy_head.next;
}

int main() { return 0; }
