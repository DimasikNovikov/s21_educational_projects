#ifndef S21_CONTAINERS_S21_STACK_H_
#define S21_CONTAINERS_S21_STACK_H_

#include "s21_vector.h"

namespace s21 {
template <typename T, class Container = s21::Vector<T>>
class Stack {
 private:
  Container cont_;

 public:
  // Member types
  using value_type = T;
  using reference = T&;
  using const_reference = T const&;
  using size_type = size_t;

  // Member functions
  Stack() : cont_(){};
  Stack(std::initializer_list<value_type> const& items) : cont_(items){};
  Stack(Stack const& s) : cont_(s.cont_){};
  Stack(Stack&& s) : cont_(std::move(s.cont_)){};
  ~Stack(){};

  Stack& operator=(Stack const& s) {
    cont_ = s.cont_;
    return *this;
  }

  Stack& operator=(Stack&& s) {
    cont_ = std::move(s.cont_);
    return *this;
  }

  // Element access
  const_reference Top() { return cont_.Back(); }

  // Capacity
  bool Empty() { return cont_.Empty(); }
  size_type Size() { return cont_.Size(); }

  // Modifiers
  void Push(const_reference value) { cont_.Push_back(value); }
  void Pop() { cont_.Pop_back(); }
  void Swap(Stack& other) { cont_.Swap(other.cont_); }

  // Part 3.
  template <typename... Args>
  void Insert_many_back(Args&&... args) {
    cont_.Insert_many_back(args...);
  }
};  //  class Stack

}  // namespace s21

#endif  // S21_CONTAINERS_S21_STACK_H_