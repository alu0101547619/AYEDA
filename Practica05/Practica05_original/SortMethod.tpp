#pragma once

#include "StaticSequence.tpp"

template <class Key>
class SortMethod {
 public:
  SortMethod(StaticSequence<Key>& sequence) : sequence_(sequence) {}
  virtual void Sort() = 0;
  virtual ~SortMethod() {}

 protected:
  StaticSequence<Key>& sequence_;
};
