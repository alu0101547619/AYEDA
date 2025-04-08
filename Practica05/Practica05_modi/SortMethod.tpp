#pragma once

#include "StaticSequence.tpp"

template <class Key>
class SortMethod {
 public:
  SortMethod(StaticSequence<Key>& sequence) : sequence_(sequence) {}
  virtual void Sort() = 0;
  virtual ~SortMethod() {}
  void set_trace(bool trace) { trace_ = trace; }

 protected:
  StaticSequence<Key>& sequence_;
  bool trace_ = false;
};
