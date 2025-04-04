#pragma once

#include "SortMethod.tpp"

template <class Key>
class ShellSort : public SortMethod<Key> {
  public:
    ShellSort(StaticSequence<Key>& sequence, double alpha = 0.5) : SortMethod<Key>(sequence), alpha_(alpha) {}
    void Sort() override;
    void Deltasort(int delta, unsigned n);
  private:
    double alpha_;
};

template <class Key>
void ShellSort<Key>::Sort() {
  unsigned n = this->sequence_.size();
  int delta = n;
  while (delta > 1) {
    delta = static_cast<int>(delta * alpha_);
    if (delta < 1) delta = 1;
    Deltasort(delta, n);
    if (delta == 1) break;
  }
}

template <class Key>
void ShellSort<Key>::Deltasort(int delta, unsigned n) {
  for (unsigned i = delta; i < n; i++) {
    Key x = this->sequence_[i];
    int j = i;
    while (j >= delta && x < this->sequence_[j - delta]) {
      this->sequence_[j] = this->sequence_[j - delta];
      j -= delta;
    }
    this->sequence_[j] = x;
  }
}