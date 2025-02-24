// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Curso: 2º
// Pr ́actica 1: algoritmo y estructura de datos avanzada
// Autor: Adrián Martín Castellano
// Correo: alu0101547619@ull.edu.es
// Fecha: 12/02/2025

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

template <unsigned char Base>
class BigUnsigned {
 public:
  // Constructores    
  BigUnsigned(unsigned n = 0);
  BigUnsigned(const unsigned char* );
  BigUnsigned(const BigUnsigned&); // Constructor de copia

  // Asignación
  BigUnsigned& operator=(const BigUnsigned&);

  // Inserción y extracción en flujo
  template <unsigned char B>
  friend ostream& operator<<(ostream&, const BigUnsigned<B>&);

  template <unsigned char B>
  friend istream& operator>>(istream&, BigUnsigned<B>&);
  
  // Comparación
  bool operator==(const BigUnsigned&) const;
  bool operator<(const BigUnsigned&) const;

  // Operadores aritméticos
  BigUnsigned operator+(const BigUnsigned&) const;
  BigUnsigned operator-(const BigUnsigned&) const;
  BigUnsigned operator*(const BigUnsigned&) const;
  BigUnsigned operator/(const BigUnsigned&) const;
  BigUnsigned operator%(const BigUnsigned&) const;

  BigUnsigned<10> convertirDecimal() const;
  BigUnsigned<Base> convertirBase(unsigned char base) const;

 private:
  std::vector<unsigned char> number_;
};

#include "BigUnsigned.tpp"
