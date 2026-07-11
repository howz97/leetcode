#include <cassert>
#include <cstddef>
#include <unordered_map>

class LFUCache {
public:
  LFUCache(int capacity) : capacity_(capacity) {}

  struct Bucket;

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
    Bucket *bucket_{nullptr};
    ListNode *prev_{nullptr};
    ListNode *next_{nullptr};
  };

  class Bucket {
  public:
    Bucket(size_t freq_cnt) : freq_cnt_(freq_cnt) {
      head_.next_ = &head_;
      head_.prev_ = &head_;
    }
    size_t FreqCnt() const { return freq_cnt_; }
    bool Empty() const { return head_.next_ == &head_; }
    void Add(ListNode *node) {
      head_.EnqueueNext(node);
      node->bucket_ = this;
    }
    int Evict() {
      ListNode *victim = head_.prev_;
      int key = victim->key_;
      victim->Dequeue();
      delete victim;
      return key;
    }

  private:
    const size_t freq_cnt_;
    ListNode head_{0, 0};
  };

  int get(int key) {
    auto it = node_index_.find(key);
    if (it == node_index_.end()) {
      return -1;
    }

    ListNode *node = it->second;
    Bucket *old_bucket = node->bucket_;
    size_t freq_cnt = old_bucket->FreqCnt();
    node->Dequeue();
    if (old_bucket->Empty()) {
      DelBucket(old_bucket);
    }

    Bucket *new_bucket = GetBucket(freq_cnt + 1, true);
    new_bucket->Add(node);
    return node->value_;
  }

  void put(int key, int value) {
    if (auto it = node_index_.find(key); it != node_index_.end()) {
      ListNode *node = it->second;
      node->value_ = value;

      Bucket *old_bucket = node->bucket_;
      size_t freq_cnt = old_bucket->FreqCnt();
      node->Dequeue();
      if (old_bucket->Empty()) {
        DelBucket(old_bucket);
      }

      Bucket *new_bucket = GetBucket(freq_cnt + 1, true);
      new_bucket->Add(node);
      return;
    }

    while (node_index_.size() >= capacity_) {
      Evict();
    }

    ListNode *node = new ListNode(key, value);
    Bucket *bucket = GetBucket(1, true);
    bucket->Add(node);
    node_index_.emplace(key, node);
  }

private:
  void DelBucket(Bucket *bucket) {
    size_t freq_cnt = bucket->FreqCnt();
    buckets_.erase(freq_cnt);

    if (bucket == min_bucket_) {
      min_bucket_ = nullptr;
      if (buckets_.empty()) {
        return;
      }
      while (min_bucket_ == nullptr) {
        freq_cnt++;
        min_bucket_ = GetBucket(freq_cnt, false);
      }
    }
  }

  Bucket *GetBucket(size_t freq_cnt, bool create) {
    if (auto it = buckets_.find(freq_cnt); it != buckets_.end()) {
      return &it->second;
    }
    if (!create) {
      return nullptr;
    }
    assert(min_bucket_ || buckets_.empty());
    auto [it, _] = buckets_.emplace(freq_cnt, freq_cnt);
    Bucket *bucket = &it->second;
    if (min_bucket_ == nullptr) {
      min_bucket_ = bucket;
    } else if (freq_cnt < min_bucket_->FreqCnt()) {
      min_bucket_ = bucket;
    }
    return bucket;
  }

  void Evict() {
    int key = min_bucket_->Evict();
    node_index_.erase(key);
    if (min_bucket_->Empty()) {
      DelBucket(min_bucket_);
    }
  }

  const size_t capacity_;
  Bucket *min_bucket_{nullptr};
  std::unordered_map<size_t, Bucket> buckets_;
  std::unordered_map<int, ListNode *> node_index_;
};

int main() { return 0; }