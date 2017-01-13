#pragma once
#include "tagged_ptr.h"
#include <stdexcept>
#include <cstdint>

template <class T>
tagged_ptr<T>::tagged_ptr() {
}

template <class T>
tagged_ptr<T>::tagged_ptr(std::nullptr_t) {
}

template <class T>
tagged_ptr<T>::tagged_ptr(const tagged_ptr &other)
    : ptr_(other.ptr_) {
}

template <class T>
template <class U>
tagged_ptr<T>::tagged_ptr(const tagged_ptr<U> &other)
    : ptr_(other.ptr_) {
}

template <class T>
tagged_ptr<T>::tagged_ptr(pointer ptr)
    : ptr_(ptr) {
}

template <class T>
auto tagged_ptr<T>::operator=(std::nullptr_t) -> tagged_ptr & {
  ptr_ = nullptr;
  return *this;
}

template <class T>
auto tagged_ptr<T>::operator=(const tagged_ptr &other) -> tagged_ptr & {
  ptr_ = other.ptr_;
  return *this;
}

template <class T>
template <class U>
auto tagged_ptr<T>::operator=(const tagged_ptr<U> &other) -> tagged_ptr & {
  ptr_ = other.ptr_;
  return *this;
}

template <class T>
auto tagged_ptr<T>::operator=(pointer ptr) -> tagged_ptr & {
  ptr_ = ptr;
  return *this;
}

template <class T>
void tagged_ptr<T>::reset(pointer ptr) noexcept {
  ptr_ = ptr;
}

template <class T>
auto tagged_ptr<T>::get() const noexcept -> pointer {
  return reinterpret_cast<T *>(
      reinterpret_cast<intptr_t>(ptr_) & ~intptr_t(tag_max));
}

template <class T>
auto tagged_ptr<T>::tag() const noexcept -> tag_type {
  return reinterpret_cast<intptr_t>(ptr_) & tag_max;
}

template <class T>
void tagged_ptr<T>::tag(tag_type t) {
  if (t < tag_min || t > tag_max)
    throw std::range_error("tag value out of permissible range");
  ptr_ = reinterpret_cast<T *>(
      reinterpret_cast<intptr_t>(get()) | t);
}

template <class T>
tagged_ptr<T>::operator pointer() const noexcept {
  return get();
}

template <class T>
tagged_ptr<T>::operator bool() const noexcept {
  return get();
}

template <class T>
auto tagged_ptr<T>::operator*() const noexcept -> element_type & {
  return *get();
}

template <class T>
auto tagged_ptr<T>::operator->() const noexcept -> pointer {
  return get();
}
