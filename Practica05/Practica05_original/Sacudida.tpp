#pragma once

#include "SortMethod.tpp"

template <class Key>
class Sacudida : public SortMethod<Key> {
  public:
    Sacudida(StaticSequence<Key>& sequence) : SortMethod<Key>(sequence) {}
    void Sort() override;
};

template <class Key>
void Sacudida<Key>::Sort() {
  unsigned ini = 1; 
  unsigned fin = this->sequence_.size() - 1; 
  unsigned cam = this->sequence_.size();
  while (ini < fin){
    for (unsigned j = fin; j >= ini; j--)
      if (this->sequence_[j] < this->sequence_[j - 1]) {
        std::swap(this->sequence_[j - 1], this->sequence_[j]);
        cam = j;
      } 
    ini = cam + 1;
    for (unsigned j = ini; j <= fin; j++)
      if (this->sequence_[j] < this->sequence_[j - 1]) {
        std::swap(this->sequence_[j - 1], this->sequence_[j]);
        cam = j;
      } 
    fin = cam - 1 ;
  } 
}