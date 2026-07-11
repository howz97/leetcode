#include <cassert>
#include <unordered_map>

class LRUCache {
public:
  struct ListNode {
    ListNode(int key, int value) : key_(key), value_(value) {}
    void Dequeue() {
      prev_->next_ = next_;
      next_->prev_ = prev_;
      prev_ = nullptr;
      next_ = nullptr;
    }

    void EnqueueNext(ListNode *node) {
      node->next_ = next_;
      node->prev_ = this;
      next_->prev_ = node;
      next_ = node;
    }

    int key_;
    int value_;
    ListNode *prev_{nullptr};
    ListNode *next_{nullptr};
  };

  LRUCache(int capacity) : capacity_(capacity) {
    head_.prev_ = &head_;
    head_.next_ = &head_;
  }

  int get(int key) {
    auto it = index_.find(key);
    if (it == index_.end()) {
      return -1;
    }
    ListNode *node = it->second;
    node->Dequeue();
    head_.EnqueueNext(node);
    return node->value_;
  }

  void put(int key, int value) {
    if (auto it = index_.find(key); it != index_.end()) {
      ListNode *node = it->second;
      node->value_ = value;
      node->Dequeue();
      head_.EnqueueNext(node);
      return;
    }

    while (index_.size() >= capacity_) {
      ListNode *victim = head_.prev_;
      victim->Dequeue();
      auto it = index_.find(victim->key_);
      assert(it != index_.end());
      index_.erase(it);
      delete victim;
    }

    ListNode *node = new ListNode(key, value);
    head_.EnqueueNext(node);
    index_.emplace(key, node);
  }

private:
  const int capacity_;
  ListNode head_{0, 0};
  std::unordered_map<int, ListNode *> index_;
};

int main() { return 0; }