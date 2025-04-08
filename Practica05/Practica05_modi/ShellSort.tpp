#pragma once

#include "SortMethod.tpp"

template <class Key>
class ShellSort : public SortMethod<Key> {
  public:
    ShellSort(StaticSequence<Key>& sequence, double alpha = 0.5) : SortMethod<Key>(sequence), alpha_(alpha) {}
    void Sort() override;
    void Deltasort(int delta, unsigned n);
    int get_comp() const { return comp_; }
    int get_swap() const { return swap_; }
   
  private:
    double alpha_;
    int comp_ = 0;
    int swap_ = 0;
};

template <class Key>
void ShellSort<Key>::Sort() {
  unsigned n = this->sequence_.size();
  int delta = n;
  while (delta > 1) {
    comp_++;
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
      comp_++;
      swap_++;
      this->sequence_[j] = this->sequence_[j - delta];
      j -= delta;
    }
    this->sequence_[j] = x;
    if (this->trace_) {
      std::cout << "Iteración i=" << i << ", delta=" << delta << ": ";
      for (unsigned k = 0; k < this->sequence_.size(); ++k) {
        std::cout << this->sequence_[k] << " ";
      }
      std::cout << "\n";
    }
  }
}