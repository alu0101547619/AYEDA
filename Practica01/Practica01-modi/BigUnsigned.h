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

using namespace std;

class BigUnsigned {
 public:
  // Constructores    
  BigUnsigned(unsigned n = 0);
  BigUnsigned(const unsigned char* );
  BigUnsigned(const BigUnsigned&); // Constructor de copia

  // Asignación
  BigUnsigned& operator=(const BigUnsigned&);

  // Inserción y extracción en flujo
  friend ostream& operator<<(ostream&, const BigUnsigned&);
  friend istream& operator>>(istream&, BigUnsigned&);
  
  // Comparación
  bool operator==(const BigUnsigned&) const;
  friend bool operator<(const BigUnsigned&, const BigUnsigned&);

  // Incremento/decremento
  BigUnsigned& operator++(); // Pre-incremento
  BigUnsigned operator++(int); // Post-incremento
  BigUnsigned& operator--(); // Pre-decremento
  BigUnsigned operator--(int); // Post-decremento

  // Operadores aritméticos
  friend BigUnsigned operator+(const BigUnsigned&, const BigUnsigned&);
  BigUnsigned operator-(const BigUnsigned&) const;
  BigUnsigned operator*(const BigUnsigned&) const;
  friend BigUnsigned operator/(const BigUnsigned&, const BigUnsigned&);
  BigUnsigned operator%(const BigUnsigned&) const;

 private:
  std::vector<unsigned char> number_;
};