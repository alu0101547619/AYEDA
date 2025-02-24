#pragma once

#include "BigUnsigned.h"

template <>
class BigUnsigned<2> {
 public:
  // Constructores    
  BigUnsigned(unsigned n = 0);
  BigUnsigned(const string&);
  BigUnsigned(const BigUnsigned&); // Constructor de copia

  // Asignación
  // BigUnsigned& operator=(const BigUnsigned&);

  // Inserción y extracción en flujo
  // friend ostream& operator<<(ostream&, const BigUnsigned&);
  // friend istream& operator>>(istream&, BigUnsigned&);

  // Comparación
  // bool operator==(const BigUnsigned&) const;
  // bool operator<(const BigUnsigned&) const;

  // Operaciones
  // BigUnsigned operator+(const BigUnsigned&) const;
  // BigUnsigned operator-(const BigUnsigned&) const;
  // BigUnsigned operator*(const BigUnsigned&) const; 
  // BigUnsigned operator/(size_t) const; 
  // BigUnsigned operator%(size_t) const; 

 private:
  std::vector<bool> bits_;

};

#include "BigUnsignedB2.tpp"