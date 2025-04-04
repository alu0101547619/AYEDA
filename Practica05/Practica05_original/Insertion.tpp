#pragma once

#include "SortMethod.tpp"

template <class Key>
class Insertion : public SortMethod<Key> {
 public:
  Insertion(StaticSequence<Key>& sequence) : SortMethod<Key>(sequence) {}
  void Sort() override;
};

template <class Key>
void Insertion<Key>::Sort() {
  int n = this->sequence_.size();
  for (int i = 1; i < n; i++) {
    Key x = this->sequence_[i];
    int j = i;
    while (j > 0 && x < this->sequence_[j - 1]) {
      this->sequence_[j] = this->sequence_[j - 1];
      j--;
    }
    this->sequence_[j] = x;
  }
}
