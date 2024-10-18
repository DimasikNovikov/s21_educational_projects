#ifndef S21_CONTAINERS_S21_ARRAY_H_
#define S21_CONTAINERS_S21_ARRAY_H_

#include <iostream>

namespace s21 {
template <typename T, size_t N>
class Array {
 private:
  T data_[N]{};
  size_t size_{N};

 public:
  // member types
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  // member functions
  Array() {}
  Array(std::initializer_list<value_type> const &items);
  //~Array() {}

  // Эти методы в стандартной библиотеке автоматические
  //  Array(const Array &other);
  //  Array(Array &&other);
  //  Array &operator=(Array &&other);
  //  Array &operator=(const Array &other);

  // Capacity
  bool Empty() const { return size_ == 0; }
  size_type Size() const { return size_; }
  size_type Max_size() { return size_; }

  // Element access
  reference At(size_type pos);
  reference operator[](size_type pos) { return data_[pos]; }
  const_reference Front() { return data_[0]; }
  const_reference Back() { return data_[size_ - 1]; }
  iterator Data() { return data_; }

  // Iterators
  iterator Begin() { return data_; }
  iterator End() { return data_ + size_; }

  // Modifiers
  void Swap(Array &other);
  void Fill(const_reference value);

};  // class Array

//--------------------------------------------------------
//+++++++ DEFINING CLASS MEMBER FUNCTIONS ++++++++++++++++
//--------------------------------------------------------

//==============================================
//============= Member functions ===============
//==============================================

template <typename T, size_t N>
Array<T, N>::Array(std::initializer_list<value_type> const &items) {
  for (size_t i{}; i < size_ && i < items.size(); i++) {
    data_[i] = *(items.begin() + i);
  }
}

// template <typename T, size_t N>
// Array<T, N>::Array(const Array &other) {
//   for (size_type i = 0; i < size_; i++) {
//     data_[i] = other.data_[i];
//   }
// }

// template <typename T, size_t N>
// Array<T, N>::Array(Array &&other) {
//   for (size_type i = 0; i < size_; i++) {
//     data_[i] = other.data_[i];
//   }
// }

// template <typename T, size_t N>
// typename Array<T, N>::Array &Array<T, N>::operator=(const Array &other) {
//   if (this != &other) {
//     for (size_type i = 0; i < size_; i++) {
//       data_[i] = other.data_[i];
//     }
//   }
//   return *this;
// }

// template <typename T, size_t N>
// typename Array<T, N>::Array &Array<T, N>::operator=(Array &&other) {
//   if (this != &other) {
//     for (size_type i = 0; i < size_; i++) {
//       data_[i] = other.data_[i];
//     }
//   }
//   return *this;
// }

//==============================================
//============= Element access =================
//==============================================

template <typename T, size_t N>
typename Array<T, N>::reference Array<T, N>::At(size_type pos) {
  if (pos >= N) {
    throw std::out_of_range("Index out of range");
  }
  return data_[pos];
}

//==============================================
//============= Modifiers ======================
//==============================================

template <typename T, size_t N>
void Array<T, N>::Swap(Array &other) {
  std::swap(data_, other.data_);
}

template <typename T, size_t N>
void Array<T, N>::Fill(const_reference value) {
  for (size_type i = 0; i < size_; i++) data_[i] = value;
}

}  // namespace s21

#endif  // S21_CONTAINERS_S21_ARRAY_H_