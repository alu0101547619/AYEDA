#include "Nif.hpp"

Nif::Nif() : number_(10000000 + (std::rand() % 90000000)) {}

Nif::Nif(long number) : number_(number) {}

Nif::operator long() const { return number_; }

bool Nif::operator==(const Nif& other) const { return number_ == other.number_; }
bool Nif::operator!=(const Nif& other) const { return number_ != other.number_; }
bool Nif::operator<(const Nif& other) const { return number_ < other.number_; }
bool Nif::operator>(const Nif& other) const { return number_ > other.number_; }
bool Nif::operator<=(const Nif& other) const { return number_ <= other.number_; }
bool Nif::operator>=(const Nif& other) const { return number_ >= other.number_; }