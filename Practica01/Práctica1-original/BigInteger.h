// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Curso: 2º
// Pr ́actica 1: algoritmo y estructura de datos avanzada
// Autor: Adrián Martín Castellano
// Correo: alu0101547619@ull.edu.es
// Fecha: 12/02/2025

#pragma once
#include "BigUnsigned.h"

class BigInteger {
 public:
  // Getter
  BigUnsigned getNumber() const; 
  bool getSign() const; 

  // Constructorea
  BigInteger(int n = 0);
  BigInteger(const BigUnsigned&); // Constructor de cambio de tipo

  // Asignación
  BigInteger& operator=(const BigInteger&);

  // Operadores inserción y extracción
  friend ostream& operator<<(ostream&, const BigInteger&); // Inserción de flujo
  friend istream& operator>>(istream&, BigInteger&); // Extracción de flujo
  
  // Comparación
  bool operator==(const BigInteger&) const;
  friend bool operator<(const BigInteger&, const BigInteger&);

  // Incremento/Decremento
  BigInteger& operator++(); // Pre-incremento
  BigInteger operator++(int); // Post-incremento
  BigInteger& operator--(); // Pre-decremento
  BigInteger operator--(int); // Post-decremento
  
  // Operadores aritméticos
  friend BigInteger operator+(const BigInteger&, const BigInteger&);
  BigInteger operator-(const BigInteger&) const;
  BigInteger operator*(const BigInteger&) const;
  friend  BigInteger operator/(const BigInteger&, const BigInteger&);
  BigInteger operator%(const BigInteger&) const;

  // Opradores insertar y extraer en flujo
 private:
  BigUnsigned number_;
  bool sign_;
};