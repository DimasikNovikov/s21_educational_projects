#ifndef S21_CONTAINERS_S21_QUEUE_H_
#define S21_CONTAINERS_S21_QUEUE_H_

#include "s21_list.h"

namespace s21 {
template <typename T, typename Container = s21::List<T>>
class Queue {
 public:
  // Member types
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

 private:
  Container cont_;

 public:
  // Member functions
  Queue() : cont_(){};
  Queue(std::initializer_list<value_type> const& items) : cont_(items){};
  Queue(Queue const& q) : cont_(q.cont_){};
  Queue(Queue&& q) : cont_(std::move(q.cont_)){};
  ~Queue() {}

  Queue& operator=(Queue const& q) {
    cont_ = q.cont_;
    return *this;
  }

  Queue& operator=(Queue&& q) {
    cont_ = std::move(q.cont_);
    return *this;
  }

  // Element access
  const_reference Front() { return cont_.Front(); }
  const_reference Back() { return cont_.Back(); }

  // Capacity
  bool Empty() { return cont_.Empty(); }
  size_type Size() { return cont_.Size(); }

  // Modifier
  void Push(const_reference value) { cont_.Push_back(value); }
  void Pop() { cont_.Pop_front(); }
  void Swap(Queue& other) { cont_.Swap(other.cont_); }

  template <typename... Args>
  void Insert_many_back(Args&&... args) {
    cont_.Insert_many_back(args...);
  }

};  // class Queue

}  // namespace s21

#endif  // S21_CONTAINERS_S21_QUEUE_H_
