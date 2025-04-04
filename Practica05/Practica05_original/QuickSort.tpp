#pragma once

#include "SortMethod.tpp"
#include "Nif.hpp"

template <class Key>
class QuickSort : public SortMethod<Key> {
  public:
    QuickSort(StaticSequence<Key>& sequence) : SortMethod<Key>(sequence) {}
    void Sort() override;
    void Qsort(unsigned ini, unsigned fin);
};

template <class Key>
void QuickSort<Key>::Sort() {
  Qsort(0, this->sequence_.size() - 1);
}

template <class Key>
void QuickSort<Key>::Qsort(unsigned ini, unsigned fin) {
  unsigned i = ini;
  unsigned f = fin;
  Nif p = this->sequence_[(i + f) / 2];
  while (i <= f) {
    while (this->sequence_[i] < p) i++;
    while (this->sequence_[f] > p) f--;
    if (i <= f) {
      std::swap(this->sequence_[i], this->sequence_[f]);
      i++;
      f--;
    }
  }
  if (ini < f) Qsort(ini, f);
  if (i < fin) Qsort(i, fin);
}