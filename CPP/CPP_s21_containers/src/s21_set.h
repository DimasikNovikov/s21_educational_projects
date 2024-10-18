#ifndef S21_CONTAINERS_S21_SET_H_
#define S21_CONTAINERS_S21_SET_H_

#include <utility>
#include <vector>

#include "s21_list.h"
#include "s21_vector.h"

namespace s21 {
template <typename Key>
class Set {
 public:
  // Member types
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;

 private:
  List<Key> cont_;

  // Extra functions
  void SortAndErase() {
    cont_.Sort();

    auto it = cont_.Begin();
    auto it_next = ++cont_.Begin();
    while (it_next != cont_.End()) {
      if (*it == *it_next) {
        auto it_temp = it_next++;
        cont_.Erase(it_temp);
      } else {
        it = it_next++;
      }
    }
  }

 public:
  using iterator = class SetIterator {
   public:
    typename List<Key>::iterator iter_list;

    SetIterator(typename List<Key>::iterator iter) : iter_list(iter) {}

    reference operator*() { return *iter_list; }

    SetIterator &operator++() {
      ++iter_list;
      return *this;
    }

    SetIterator operator++(int) {
      SetIterator temp(*this);
      ++iter_list;
      return temp;
    }

    SetIterator &operator--() {
      --iter_list;
      return *this;
    }

    SetIterator operator--(int) {
      SetIterator temp(*this);
      --iter_list;
      return temp;
    }

    bool operator==(const SetIterator &other) const {
      return iter_list == other.iter_list;
    }

    bool operator!=(const SetIterator &other) const {
      return iter_list != other.iter_list;
    }
  };

  using const_iterator = class SetConstIterator {};

  // Member finctions
  Set() : cont_() {}

  Set(std::initializer_list<value_type> const &items) : cont_(items) {
    SortAndErase();
  };

  Set(const Set &s) : cont_(s.cont_){};
  Set(Set &&s) : cont_(std::move(s.cont_)){};

  Set &operator=(const Set &s) {
    cont_ = s.cont_;
    return *this;
  };
  Set &operator=(Set &&s) {
    cont_ = std::move(s.cont_);
    return *this;
  };

  ~Set() {}

  // Capacity
  bool Empty() { return cont_.Empty(); }
  size_type Size() { return cont_.Size(); }
  size_type Max_size() { return cont_.Max_size(); }

  // Iterators
  iterator Begin() { return SetIterator(cont_.Begin()); }
  iterator End() { return SetIterator(cont_.End()); }

  // Modifiers
  void Clear() { cont_.Clear(); }
  void Swap(Set &other) { cont_.Swap(other.cont_); }
  void Merge(Set &other) { cont_.Merge(other.cont_); }
  void Erase(iterator pos) { cont_.Erase(pos.iter_list); }

  std::pair<iterator, bool> Insert(const value_type &value) {
    bool is_value = !Contains(value);
    cont_.Push_back(value);
    SortAndErase();
    iterator it = Find(value);

    return std::make_pair(it, is_value);
  }

  // Lookup
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

  // Part 3
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> Insert_many(Args &&...args) {
    std::vector<std::pair<iterator, bool>> result;

    (result.push_back(Insert(std::forward<Args>(args))), ...);

    return result;
  }

};  // class Set

}  // namespace s21

#endif  // S21_CONTAINERS_S21_SET_H_