#pragma once

#include "SortMethod.tpp"
#include "Nif.hpp"

template <class Key>
class QuickSort : public SortMethod<Key> {
  public:
    QuickSort(StaticSequence<Key>& sequence) : SortMethod<Key>(sequence) {}
    void Sort() override;
    void Qsort(unsigned ini, unsigned fin);
    int get_comp() const { return comp_; }
    int get_swap() const { return swap_; }

  private:
    int comp_ = 0;
    int swap_ = 0;
};

template <class Key>
void QuickSort<Key>::Sort() {
  Qsort(0, this->sequence_.size() - 1);
}

template <class Key>
void QuickSort<Key>::Qsort(unsigned ini, unsigned fin) {
  unsigned i = ini;
  unsigned f = fin;
  Key p = this->sequence_[(i + f) / 2];
  while (i <= f) {
    comp_++;
    while (this->sequence_[i] < p) {
      i++;
      comp_++;
    }
    while (this->sequence_[f] > p) {
      f--;
      comp_++;
    }
    if (i <= f) {
      std::swap(this->sequence_[i], this->sequence_[f]);
      swap_++;
      comp_++;
      i++;
      f--;
    }
  }
  if (this->trace_) {
    std::cout << "Partición (ini=" << ini << ", fin=" << fin << ", pivote=" << p << "): ";
    for (unsigned k = 0; k < this->sequence_.size(); ++k) {
      std::cout << this->sequence_[k] << " ";
    }
    std::cout << "\n";
  }
  if (ini < f) {
    comp_++;
    Qsort(ini, f);
  }
  if (i < fin) {
    comp_++;
    Qsort(i, fin);
  }
}