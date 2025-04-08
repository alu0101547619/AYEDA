#pragma once

#include "Sequence.tpp"

template <class Key>
class StaticSequence : public Sequence<Key> {
  public:
    StaticSequence(unsigned size);
    unsigned size() const { return size_; }
    virtual Key operator[](const unsigned) const override;
    virtual Key& operator[](const unsigned) override;

  private:
    unsigned size_;
    Key* array_;
};

template <class Key>
StaticSequence<Key>::StaticSequence(unsigned size) : size_(size) {
  array_ = new Key[size];
}

template <class Key>
Key StaticSequence<Key>::operator[](const unsigned index) const {
  if (index >= size_) {
    std::cerr << "Fuera de rango" << std::endl;
    exit(1);
  }
  return array_[index];
}

template <class Key>
Key& StaticSequence<Key>::operator[](const unsigned index) {
  if (index >= size_) {
    std::cerr << "Fuera de rango" << std::endl;
    exit(1);
  }
  return array_[index];
}