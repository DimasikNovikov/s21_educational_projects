#ifndef S21_CONTAINERS_S21_MAP_H_
#define S21_CONTAINERS_S21_MAP_H_

namespace s21 {

template <typename Key, typename T>
class Map {
 public:
  // Member types
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;

 private:
  List<value_type> cont_;

 public:
  using iterator = class MapIterator {
   public:
    typename List<value_type>::iterator iter_list;

    MapIterator(typename List<value_type>::iterator iter) : iter_list(iter) {}

    reference operator*() { return *iter_list; }
    value_type *operator->() { return &iter_list.node_ptr_->data; }

    MapIterator &operator++() {
      ++iter_list;
      return *this;
    }

    MapIterator operator++(int) {
      MapIterator temp(*this);
      ++iter_list;
      return temp;
    }

    MapIterator &operator--() {
      --iter_list;
      return *this;
    }

    MapIterator operator--(int) {
      MapIterator temp(*this);
      --iter_list;
      return temp;
    }

    bool operator==(const MapIterator &other) const {
      return iter_list == other.iter_list;
    }

    bool operator!=(const MapIterator &other) const {
      return iter_list != other.iter_list;
    }
  };

  using const_iterator = class MapConstIterator {};

  // Member functions
  Map() : cont_() {}
  Map(std::initializer_list<value_type> const &items);
  Map(const Map &s) : cont_(s.cont_){};
  Map(Map &&s) : cont_(std::move(s.cont_)){};

  Map &operator=(const Map &s) {
    cont_ = s.cont_;
    return *this;
  };
  Map &operator=(Map &&s) {
    cont_ = std::move(s.cont_);
    return *this;
  };
  ~Map() {}

  // Capacity
  bool Empty() { return cont_.Empty(); }
  size_type Size() { return cont_.Size(); }
  size_type Max_size() { return cont_.Max_size(); }

  // Iterators
  iterator Begin() { return MapIterator(cont_.Begin()); }
  iterator End() { return MapIterator(cont_.End()); }

  // Modifiers
  void Clear() { cont_.Clear(); }
  std::pair<iterator, bool> Insert(const value_type &value);
  std::pair<iterator, bool> Insert(const Key &key, const T &obj);
  std::pair<iterator, bool> Insert_or_assign(const Key &key, const T &obj);
  void Erase(iterator pos) { cont_.Erase(pos.iter_list); }
  void Swap(Map &other) { cont_.Swap(other.cont_); }
  void Merge(Map &other);

  // Element access
  T &At(const Key &key);
  T &operator[](const Key &key);

  // Lookup
  bool Contains(const Key &key);

  // Part 3
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> Insert_many(Args &&...args) {
    std::vector<std::pair<iterator, bool>> result;
    std::vector<value_type> arguments = {args...};
    for (auto &elem : arguments) {
      result.push_back(Insert(elem));
    }
    return result;
  }
};  // class Map

//-------------------------------------------------------------------
//++++++++++++++++++++ DEFINING CLASS METHODS +++++++++++++++++++++++
//-------------------------------------------------------------------

template <typename Key, typename T>
Map<Key, T>::Map(std::initializer_list<value_type> const &items) {
  for (const auto &elem : items) {
    Insert(elem);
  }
}

template <typename Key, typename T>
std::pair<typename Map<Key, T>::iterator, bool> Map<Key, T>::Insert(
    const value_type &value) {
  auto it_list = cont_.Begin();
  bool insert_value = false;

  while (true) {
    if (it_list == cont_.End() || it_list->first > value.first) {
      it_list = cont_.Insert(it_list, value);
      insert_value = true;
      break;
    } else if (it_list->first == value.first) {
      break;
    }
    ++it_list;
  }

  return std::make_pair(MapIterator(it_list), insert_value);
}

template <typename Key, typename T>
std::pair<typename Map<Key, T>::iterator, bool> Map<Key, T>::Insert(
    const Key &key, const T &obj) {
  return Insert(std::make_pair(key, obj));
}

template <typename Key, typename T>
std::pair<typename Map<Key, T>::iterator, bool> Map<Key, T>::Insert_or_assign(
    const Key &key, const T &obj) {
  auto it_list = cont_.Begin();
  bool insert_value = false;

  while (true) {
    if (it_list == cont_.End() || it_list->first > key) {
      it_list = cont_.Insert(it_list, std::make_pair(key, obj));
      insert_value = true;
      break;
    } else if (it_list->first == key) {
      it_list->second = obj;
      break;
    }
    ++it_list;
  }

  return std::make_pair(MapIterator(it_list), insert_value);
}

template <typename Key, typename T>
void Map<Key, T>::Merge(Map &other) {
  iterator it_other = other.Begin();

  while (it_other != other.End()) {
    if (Contains(it_other->first)) {
      ++it_other;
    } else {
      Insert(*it_other);
      iterator temp(it_other++);
      other.Erase(temp);
    }
  }
}

template <typename Key, typename T>
bool Map<Key, T>::Contains(const Key &key) {
  bool result = false;

  auto it{Begin()};
  for (; it != End() && it->first != key; ++it)
    ;
  if (it != MapIterator(nullptr)) {
    result = true;
  }

  return result;
}

template <typename Key, typename T>
T &Map<Key, T>::operator[](const Key &key) {
  iterator it = Begin();

  if (Contains(key)) {
    while (it->first != key) {
      ++it;
    }
  } else {
    auto temp_pair = Insert(key, T());
    it = temp_pair.first;
  }

  return it->second;
}

template <typename Key, typename T>
T &Map<Key, T>::At(const Key &key) {
  iterator it = Begin();

  if (Contains(key)) {
    while (it->first != key) {
      ++it;
    }
  } else {
    throw std::out_of_range("The key does not exist!");
  }

  return it->second;
}

}  // namespace s21

#endif  // S21_CONTAINERS_S21_MAP_H_