#pragma once

#include <iostream>

template <class Key>
class Sequence {
  public:
    virtual bool search(const Key& k) const = 0;
    virtual bool insert(const Key& k) = 0;
    virtual bool isFull() const = 0;
};