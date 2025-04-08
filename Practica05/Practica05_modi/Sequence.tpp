#pragma once

#include <iostream>

template <class Key>
class Sequence {
  public:
    virtual Key operator[](const unsigned) const = 0;
    virtual Key& operator[](const unsigned) = 0;
};