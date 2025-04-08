#pragma once

#include "SortMethod.tpp"

template <class Key>
class Insertion : public SortMethod<Key> {
 public:
  Insertion(StaticSequence<Key>& sequence) : SortMethod<Key>(sequence) {}
  void Sort() override;

  int get_comp() const { return comp_; }
  int get_swap() const { return swap_; }

  private:
    int comp_ = 0;
    int swap_ = 0;
};

template <class Key>
void Insertion<Key>::Sort() {
  int n = this->sequence_.size();
  for (int i = 1; i < n; i++) {
    Key x = this->sequence_[i];
    int j = i;
    while (j > 0 && x < this->sequence_[j - 1]) {
      comp_++;
      this->sequence_[j] = this->sequence_[j - 1];
      swap_++;
      j--;
    }
    this->sequence_[j] = x;
    if (this->trace_) {
      std::cout << "Iteración i=" << i << ": ";
      for (int k = 0; k < n; ++k) {
        std::cout << this->sequence_[k] << " ";
      }
      std::cout << "\n";
    }
  }
}
