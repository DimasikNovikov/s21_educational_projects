#ifndef S21_CONTAINERS_S21_MULTISET_H_
#define S21_CONTAINERS_S21_MULTISET_H_

#include <utility>
#include <vector>

#include "s21_list.h"
#include "s21_vector.h"

namespace s21 {
template <typename Key>
class Multiset {
 public:
  // Member types
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;

 private:
  List<Key> cont_;

 public:
  using iterator = class MultisetIterator {
   public:
    typename List<Key>::iterator iter_list;

    MultisetIterator(typename List<Key>::iterator iter) : iter_list(iter) {}

    reference operator*() { return *iter_list; }

    MultisetIterator &operator++() {
      ++iter_list;
      return *this;
    }

    MultisetIterator operator++(int) {
      MultisetIterator temp(*this);
      ++iter_list;
      return temp;
    }

    MultisetIterator &operator--() {
      --iter_list;
      return *this;
    }

    MultisetIterator operator--(int) {
      MultisetIterator temp(*this);
      --iter_list;
      return temp;
    }

    bool operator==(const MultisetIterator &other) const {
      return iter_list == other.iter_list;
    }

    bool operator!=(const MultisetIterator &other) const {
      return iter_list != other.iter_list;
    }
  };

  using const_iterator = class MultisetConstIterator {};

  // Member finctions
  Multiset() : cont_() {}

  Multiset(std::initializer_list<value_type> const &items) : cont_(items) {
    cont_.Sort();
  };

  Multiset(const Multiset &ms) : cont_(ms.cont_){};
  Multiset(Multiset &&ms) : cont_(std::move(ms.cont_)){};

  Multiset &operator=(const Multiset &ms) {
    cont_ = ms.cont_;
    return *this;
  };

  Multiset &operator=(Multiset &&ms) {
    cont_ = std::move(ms.cont_);
    return *this;
  };

  ~Multiset() {}

  // Capacity
  bool Empty() { return cont_.Empty(); }
  size_type Size() { return cont_.Size(); }
  size_type Max_size() { return cont_.Max_size(); }

  // Iterators
  iterator Begin() { return MultisetIterator(cont_.Begin()); }
  iterator End() { return MultisetIterator(cont_.End()); }

  // Modifiers
  void Clear() { cont_.Clear(); }
  void Swap(Multiset &other) { cont_.Swap(other.cont_); }
  void Merge(Multiset &other) { cont_.Merge(other.cont_); }
  void Erase(iterator pos) { cont_.Erase(pos.iter_list); }

  iterator Insert(const value_type &value) {
    cont_.Push_back(value);
    cont_.Sort();
    iterator it = Begin();
    while (*it != value) {
      ++it;
    }
    return it;
  }

  // Lookup
  size_type Count(const Key &key) {
    size_type result = 0;

    iterator it = Begin();
    while (it != End()) {
      if (*it == key) {
        result++;
      }
      ++it;
    }

    return result;
  }

  iterator Find(const Key &key) {
    iterator iter = Begin();
    while (iter != End() && *iter != key) {
      ++iter;
    }

    return iter;
  }

  bool Contains(const Key &key) {
    iterator iter = Begin();
    while (iter != End() && *iter != key) {
      ++iter;
    }

    bool result = false;
    if (iter != End()) {
      result = true;
    }

    return result;
  }

  iterator Lower_bound(const Key &key) {
    iterator iter = Begin();
    while (iter != End() && *iter < key) {
      ++iter;
    }

    return iter;
  }

  iterator Upper_bound(const Key &key) {
    iterator iter = Begin();
    while (iter != End() && *iter <= key) {
      ++iter;
    }

    return iter;
  }

  std::pair<iterator, iterator> Equal_range(const Key &key) {
    return std::make_pair(Lower_bound(key), Upper_bound(key));
  }

  // Part 3
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> Insert_many(Args &&...args) {
    std::vector<std::pair<iterator, bool>> result;

    auto InsertTemp = [&](auto arg) {
      result.push_back(std::make_pair(Insert(arg), true));
    };

    (InsertTemp(std::forward<Args>(args)), ...);

    return result;
  }

};  // class Multiset
}  // namespace s21

#endif  // S21_CONTAINERS_S21_MULTISET_H_