#pragma once
#include <utility>

template <class T>
class tagged_ptr {
 public:
  typedef T *pointer;
  typedef T element_type;

  typedef int tag_type;
  static constexpr unsigned tag_bits = 2;
  static constexpr tag_type tag_min = 0, tag_max = (1 << tag_bits) - 1;

  tagged_ptr();
  tagged_ptr(std::nullptr_t);
  tagged_ptr(const tagged_ptr &other);
  template <class U> tagged_ptr(const tagged_ptr<U> &other);
  tagged_ptr(pointer ptr);

  tagged_ptr &operator=(std::nullptr_t);
  tagged_ptr &operator=(const tagged_ptr &other);
  template <class U> tagged_ptr &operator=(const tagged_ptr<U> &other);
  tagged_ptr &operator=(pointer ptr);

  void reset(pointer ptr) noexcept;
  pointer get() const noexcept;

  tag_type tag() const noexcept;
  void tag(tag_type t);

  operator pointer() const noexcept;
  explicit operator bool() const noexcept;

  element_type &operator*() const noexcept;
  pointer operator->() const noexcept;

 private:
  pointer ptr_ = nullptr;
};

#include "tagged_ptr.tcc"
