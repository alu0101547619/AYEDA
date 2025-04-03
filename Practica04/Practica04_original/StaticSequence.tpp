#pragma once

#include "Sequence.tpp"

template <class Key>
class StaticSequence : public Sequence<Key> {
  public:
    StaticSequence(unsigned tablesize);
    virtual ~StaticSequence();
    virtual bool search(const Key& k) const override;
    virtual bool insert(const Key& k) override;
    virtual bool isFull() const override;

  private:
    unsigned blockSize_;
    Key* array_;
    unsigned size_;
};

template <class Key>
StaticSequence<Key>::StaticSequence(unsigned tablesize) : blockSize_(tablesize), size_(0) {
  array_ = new Key[blockSize_];
}

template <class Key>
StaticSequence<Key>::~StaticSequence() {
  delete[] array_;
}

template <class Key>
bool StaticSequence<Key>::isFull() const {
  return this->size_ == blockSize_;
}

template <class Key>
bool StaticSequence<Key>::search(const Key& k) const {
  for (unsigned i = 0; i < this->size_; i++) {
    if (array_[i] == k) {
      return true;
    }
  }
  return false;
}

template <class Key>
bool StaticSequence<Key>::insert(const Key& k) {
  if (isFull()) {
    return false;
  }
  array_[this->size_] = k;
  this->size_++;
  return true;
}