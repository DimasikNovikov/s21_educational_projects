#ifndef S21_CONTAINERS_S21_LIST_H_
#define S21_CONTAINERS_S21_LIST_H_

#include <iostream>

namespace s21 {
template <typename T>
class List {
 public:
  // member types
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 private:
  struct Node {
    value_type data;
    Node *next = nullptr;
    Node *prev = nullptr;

    Node(value_type d) : data{d} {}
  };

  Node *head_ = nullptr;
  Node *tail_ = nullptr;
  size_type size_ = 0;

 public:
  using iterator = class ListIterator {
   public:
    Node *node_ptr_;

    ListIterator(Node *iter) : node_ptr_{iter} {}

    reference operator*() { return node_ptr_->data; }
    value_type *operator->() { return &node_ptr_->data; }

    ListIterator &operator++() {
      node_ptr_ = node_ptr_->next;
      return *this;
    }

    ListIterator operator++(int) {
      ListIterator temp(*this);
      node_ptr_ = node_ptr_->next;
      return temp;
    }

    ListIterator &operator--() {
      node_ptr_ = node_ptr_->prev;
      return *this;
    }

    ListIterator operator--(int) {
      ListIterator temp(*this);
      node_ptr_ = node_ptr_->prev;
      return temp;
    }

    bool operator==(const ListIterator &other) const {
      return node_ptr_ == other.node_ptr_;
    }

    bool operator!=(const ListIterator &other) const {
      return node_ptr_ != other.node_ptr_;
    }
  };

  using const_iterator = class ListConstIterator {
   public:
    Node *node_ptr_;

    ListConstIterator(Node *iter) : node_ptr_{iter} {}

    const_reference operator*() const { return node_ptr_->data; }
    const value_type *operator->() const { return &node_ptr_->data; }

    ListConstIterator &operator++() {
      node_ptr_ = node_ptr_->next;
      return *this;
    }

    ListConstIterator operator++(int) {
      ListConstIterator temp(*this);
      node_ptr_ = node_ptr_->next;
      return temp;
    }

    ListConstIterator &operator--() {
      node_ptr_ = node_ptr_->prev;
      return *this;
    }

    ListConstIterator operator--(int) {
      ListIterator temp(*this);
      node_ptr_ = node_ptr_->prev;
      return temp;
    }

    bool operator==(const ListConstIterator &other) const {
      return node_ptr_ == other.node_ptr_;
    }

    bool operator!=(const ListConstIterator &other) const {
      return node_ptr_ != other.node_ptr_;
    }
  };

  // List functions
  List() {}
  List(size_type n);
  List(std::initializer_list<value_type> const &items);
  List(const List &l);
  List(List &&l);
  List &operator=(const List &l);
  List &operator=(List &&l);
  ~List();

  // Iterators
  iterator Begin() { return ListIterator(head_); }
  iterator End() { return ListIterator(nullptr); }
  const_iterator CBegin() const { return ListConstIterator(head_); }
  const_iterator CEnd() const { return ListConstIterator(nullptr); }

  // Capacity
  bool Empty() { return head_ == nullptr; }
  size_type Size() { return size_; }
  size_type Max_size() {
    return std::numeric_limits<long long int>::max() / sizeof(Node);
  }

  // Element Access
  const_reference Front() { return head_->data; }
  const_reference Back() { return tail_->data; }

  // Modifiers
  void Clear() { this->~List(); }
  iterator Insert(iterator pos, const_reference value);
  void Push_back(const_reference value);
  void Push_front(const_reference value);
  void Pop_back();
  void Pop_front();
  void Erase(iterator pos);
  void Swap(List &other);
  void Sort();
  void Merge(List &other);
  void Splice(const_iterator pos, List &other);
  void Reverse();
  void Unique();

  // Part 3.
  template <typename... Args>
  iterator Insert_many(const_iterator pos, Args &&...args);

  template <typename... Args>
  void Insert_many_back(Args &&...args);

  template <typename... Args>
  void Insert_many_front(Args &&...args);

};  // class List

//-------------------------------------------------------------------
//++++++++++++++++++++ DEFINING CLASS METHODS +++++++++++++++++++++++
//-------------------------------------------------------------------

// List functions
template <typename T>
List<T>::List(size_type n) {
  for (size_type i = 0; i < n; i++) {
    Push_back(0);
  }
}

template <typename T>
List<T>::List(std::initializer_list<value_type> const &items) {
  for (const auto &value : items) {
    Push_back(value);
  }
}

template <typename T>
List<T>::List(const List &l) {
  Node *iter = l.head_;
  while (iter) {
    Push_back(iter->data);
    iter = iter->next;
  }
}

template <typename T>
List<T> &List<T>::operator=(const List &l) {
  Node *iter = l.head_;
  while (iter) {
    Push_back(iter->data);
    iter = iter->next;
  }
  return *this;
}

template <typename T>
List<T>::List(List &&l) {
  size_ = l.size_;
  head_ = l.head_;
  tail_ = l.tail_;
  l.size_ = 0;
  l.head_ = nullptr;
  l.tail_ = nullptr;
}

template <typename T>
List<T> &List<T>::operator=(List &&l) {
  if (this != &l) {
    this->~List();
    size_ = l.size_;
    head_ = l.head_;
    tail_ = l.tail_;
    l.size_ = 0;
    l.head_ = nullptr;
    l.tail_ = nullptr;
  }
  return *this;
}

template <typename T>
List<T>::~List() {
  while (tail_) {
    Node *prev_node = tail_->prev;
    delete tail_;
    tail_ = prev_node;
    size_--;
  }
  head_ = nullptr;
}

// Modifiers
template <typename T>
void List<T>::Push_back(const_reference value) {
  Node *new_node = new Node(value);
  if (tail_) {
    tail_->next = new_node;
    new_node->prev = tail_;
  }

  if (head_ == nullptr) {
    head_ = new_node;
  }

  tail_ = new_node;
  size_++;
}

template <typename T>
void List<T>::Push_front(const_reference value) {
  Node *new_node = new Node(value);
  new_node->next = head_;

  if (head_) {
    head_->prev = new_node;
  }
  head_ = new_node;
  if (tail_ == nullptr) {
    tail_ = new_node;
  }
  size_++;
}

template <typename T>
typename List<T>::iterator List<T>::Insert(iterator pos,
                                           const_reference value) {
  iterator result = nullptr;
  if (pos == Begin()) {
    Push_front(value);
    result = ListIterator(head_);
  } else if (pos == End()) {
    Push_back(value);
    result = ListIterator(tail_);
  } else {
    Node *new_node = new Node(value);
    new_node->next = pos.node_ptr_;
    new_node->prev = pos.node_ptr_->prev;
    pos.node_ptr_->prev->next = new_node;
    pos.node_ptr_->prev = new_node;
    size_++;
    result = ListIterator(new_node);
  }

  return result;
}

template <typename T>
void List<T>::Pop_back() {
  if (tail_) {
    Node *temp = tail_;
    tail_ = tail_->prev;
    if (tail_) {
      tail_->next = nullptr;
    } else {
      head_ = nullptr;
    }
    delete temp;
    size_--;
  }
}
template <typename T>
void List<T>::Pop_front() {
  if (head_) {
    Node *temp = head_;
    head_ = head_->next;
    if (head_) {
      head_->prev = nullptr;
    } else {
      tail_ = nullptr;
    }
    delete temp;
    size_--;
  }
}

template <typename T>
void List<T>::Erase(iterator pos) {
  if (pos == Begin()) {
    Pop_front();
  } else if (pos.node_ptr_ == tail_) {
    Pop_back();
  } else {
    Node *node = pos.node_ptr_;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    size_--;
  }
}

template <typename T>
void List<T>::Swap(List &other) {
  if (this != &other) {
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    std::swap(size_, other.size_);
  }
}

template <typename T>
void List<T>::Sort() {
  if (head_ != nullptr && size_ > 1) {
    bool list_sorted{false};
    while (!list_sorted) {
      list_sorted = true;
      iterator iter = Begin();
      iterator iter_next = ++Begin();

      while (iter_next != End()) {
        if (*iter > *iter_next) {
          std::swap(*iter, *iter_next);
          list_sorted = false;
        }
        iter++;
        iter_next++;
      }
    }
  }
}

template <typename T>
void List<T>::Merge(List &other) {
  if (this != &other) {
    tail_->next = other.head_;
    other.head_->prev = tail_;
    tail_ = other.tail_;
    size_ += other.size_;
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
    Sort();
  }
}

template <typename T>
void List<T>::Splice(const_iterator pos, List &other) {
  if (this != &other && !other.Empty()) {
    if (head_ == nullptr) {
      head_ = other.head_;
      tail_ = other.tail_;
      size_ = other.size_;
    } else {
      if (pos == CBegin()) {
        other.tail_->next = head_;
        head_->prev = other.tail_;
        head_ = other.head_;
      } else if (pos == CEnd()) {
        tail_->next = other.head_;
        other.head_->prev = tail_;
        tail_ = other.tail_;
      } else {
        Node *prev = pos.node_ptr_->prev;
        Node *current = pos.node_ptr_;

        other.head_->prev = prev;
        prev->next = other.head_;
        current->prev = other.tail_;
        other.tail_->next = current;
      }

      size_ += other.size_;
    }

    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
  }
}

template <typename T>
void List<T>::Reverse() {
  if (size_ > 1) {
    Node *iter{head_};
    for (size_type i = 0; i < size_; i++) {
      std::swap(iter->prev, iter->next);
      iter = iter->prev;
    }
    std::swap(head_, tail_);
  }
}

template <typename T>
void List<T>::Unique() {
  if (!Empty()) {
    for (iterator it = Begin(); it != End();) {
      iterator it_next = it;
      ++it_next;
      if (it_next.node_ptr_ == nullptr) {
        break;
      } else if (*it == *it_next) {
        Erase(it_next);
      } else {
        ++it;
      }
    }
  }
}

// Part 3

template <typename T>
template <typename... Args>
typename List<T>::iterator List<T>::Insert_many(const_iterator pos,
                                                Args &&...args) {
  iterator current_pos{ListIterator(pos.node_ptr_)};
  (Insert(current_pos, std::forward<Args>(args)), ...);

  return current_pos;
}

template <typename T>
template <typename... Args>
void List<T>::Insert_many_back(Args &&...args) {
  for (const auto &arg : {std::forward<Args>(args)...}) {
    Push_back(arg);
  }
}

template <typename T>
template <typename... Args>
void List<T>::Insert_many_front(Args &&...args) {
  for (const auto &arg : {std::forward<Args>(args)...}) {
    Push_front(arg);
  }
}

}  // namespace s21

#endif  // S21_CONTAINERS_S21_LIST_H_