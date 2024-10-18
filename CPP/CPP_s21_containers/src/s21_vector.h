#ifndef S21_CONTAINERS_S21_VECTOR_H_
#define S21_CONTAINERS_S21_VECTOR_H_
#include <iostream>

namespace s21 {
template <typename T>
class Vector {
 public:
  // member types
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = size_t;


 private:
  T* data_;
  size_type size_;
  size_type capacity_;

 public:
  // Member functions
  Vector() : data_{nullptr}, size_{0}, capacity_{0} {}
  Vector(size_type n);
  Vector(std::initializer_list<value_type> const& items);
  Vector(const Vector& other);
  Vector(Vector&& other);
  ~Vector() { delete[] data_; }

  Vector& operator=(const Vector& other);
  Vector& operator=(Vector&& other);

  // Element access
  reference At(size_type pos);
  reference operator[](size_type pos) { return data_[pos]; }
  const_reference Front() const { return data_[0]; }
  const_reference Back() const { return data_[size_ - 1]; }
  T* Data() { return data_; }

  // Iterators
  iterator Begin() { return data_; }
  iterator End() { return data_ + size_; }

  // Vector capacity
  bool Empty() const { return size_ == 0; }
  size_type Size() const { return size_; }
  size_type Capacity() const { return capacity_; }
  size_type Max_size() {
    return std::numeric_limits<long long int>::max() / sizeof(value_type);
  }
  void Reserve(size_type size);
  void Shrink_to_fit();

  // Modifiers
  void Clear();
  void Push_back(const_reference value);
  void Pop_back();
  iterator Insert(iterator pos, const_reference value);
  void Erase(iterator pos);
  void Swap(Vector& other);

  // Part 3 of the task. Extra methods: Insert_many

  template <typename... Args>
  iterator Insert_many(const_iterator pos, Args&&... args);

  template <typename... Args>
  void Insert_many_back(Args&&... args);

};  // class Vector

//--------------------------------------------------------
//+++++++ DEFINING CLASS MEMBER FUNCTIONS ++++++++++++++++
//--------------------------------------------------------

// ===============================================
// ============ Member functions =================
// ===============================================

template <typename T>
Vector<T>::Vector(size_type n) {
  size_ = n;
  capacity_ = n;
  if (n == 0) {
    data_ = nullptr;
  } else {
    data_ = new T[capacity_];
  }
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> const& items) {
  size_ = items.size();
  capacity_ = items.size();
  data_ = new T[capacity_];

  size_type i = 0;
  for (const auto& element : items) {
    data_[i++] = element;
  }
}

template <typename T>
Vector<T>::Vector(const Vector& other) : Vector(other.size_) {
  for (size_type i = 0; i < size_; i++) {
    data_[i] = other.data_[i];
  }
}

template <typename T>
Vector<T>::Vector(Vector&& other) {
  size_ = other.size_;
  capacity_ = other.capacity_;
  data_ = other.data_;
  other.data_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
  size_ = other.size_;
  capacity_ = other.capacity_;
  data_ = new T[capacity_];

  for (size_type i = 0; i < size_; i++) {
    data_[i] = other.data_[i];
  }
  return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) {
  this->~Vector();
  size_ = other.size_;
  capacity_ = other.capacity_;
  data_ = other.data_;
  other.data_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
  return *this;
}

// ===============================================
// ============ Element access ===================
// ===============================================

template <typename T>
typename Vector<T>::reference Vector<T>::At(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Index is out of range!");
  }

  return data_[pos];
}

// ===============================================
// ============ Capacity =========================
// ===============================================

template <typename T>
void Vector<T>::Reserve(size_type size) {
  if (size > capacity_) {
    Vector<T> temp(size);
    for (size_t i{}; i < size_; i++) {
      temp.data_[i] = data_[i];
    }
    temp.size_ = size_;

    this->~Vector();
    *this = temp;
  }
}

template <typename T>
void Vector<T>::Shrink_to_fit() {
  if (capacity_ > size_) {
    Vector<T> temp(size_);
    for (size_t i{}; i < size_; i++) {
      temp.data_[i] = data_[i];
    }

    this->~Vector();
    *this = temp;
  }
}

// ===============================================
// ============ Modifiers ========================
// ===============================================

template <typename T>
void Vector<T>::Clear() {
  size_ = 0;
}

template <typename T>
void Vector<T>::Push_back(const_reference value) {
  if (size_ == capacity_) {
    if (capacity_ == 0) {
      Reserve(1);
    } else {
      Reserve(capacity_ * 2);
    }
  }

  data_[size_] = value;
  size_++;
}

template <typename T>
void Vector<T>::Pop_back() {
  if (size_ > 0) {
    size_--;
  }
}

template <typename T>
typename Vector<T>::iterator Vector<T>::Insert(iterator pos,
                                               const_reference value) {
  size_type index = pos - Begin();
  if (size_ == capacity_) {
    if (capacity_ == 0) {
      Reserve(1);
    } else {
      Reserve(capacity_ * 2);
    }
  }

  for (size_type i = size_; i > index; i--) {
    data_[i] = data_[i - 1];
  }
  data_[index] = value;
  size_++;

  return Begin() + index;
}

template <typename T>
void Vector<T>::Erase(iterator pos) {
  for (auto iter = pos; iter != End() - 1; iter++) {
    *iter += 1;
  }
  size_--;
}

template <typename T>
void Vector<T>::Swap(Vector& other) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

// ===============================================
// ============ Insert_many ======================
// ===============================================

template <typename T>
template <typename... Args>
typename Vector<T>::iterator Vector<T>::Insert_many(const_iterator pos,
                                                    Args&&... args) {
  size_type index = pos - Begin();
  size_type args_count{sizeof...(Args)};

  if (size_ + args_count > capacity_) {
    Reserve(size_ + args_count);
  }

  for (size_type i{size_ + args_count - 1}; i > index + args_count - 1; i--) {
    data_[i] = data_[i - args_count];
  }

  size_type i = 0;
  ((data_[index + i++] = std::forward<Args>(args)), ...);

  size_ += args_count;

  return Begin() + index;
}

template <typename T>
template <typename... Args>
void Vector<T>::Insert_many_back(Args&&... args) {
  size_type args_count = sizeof...(Args);

  if (size_ + args_count > capacity_) {
    Reserve(size_ + args_count);
  }

  size_type i = 0;
  ((data_[size_ + i++] = std::forward<Args>(args)), ...);
  size_ += args_count;
}

}  // namespace s21

#endif  // S21_CONTAINERS_S21_VECTOR_H_