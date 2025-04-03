// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Curso: 2º
// Práctica 2: algoritmo y estructura de datos avanzada
// Autor: Adrián Martín Castellano
// Correo: alu0101547619@ull.edu.es
// Fecha: 25/02/2025

#pragma once
#include "BigUnsigned.h"

template <unsigned char Base>
class BigInteger {
 public:
  // Getter
  BigUnsigned<Base> getNumber() const;  // Obtiene el valor absoluto
  bool getSign() const;

  // Constructorea
  BigInteger(int n = 0);
  BigInteger(const BigUnsigned<Base>&); // Constructor de cambio de tipo

  // Asignación
  BigInteger& operator=(const BigInteger<Base>&);

  // Operadores inserción y extracción
  template <unsigned char B>
  friend ostream& operator<<(ostream&, const BigInteger&); // Inserción de flujo
  template <unsigned char B>
  friend istream& operator>>(istream&, BigInteger&); // Extracción de flujo
  
  // Operadores de comparación
  bool operator==(const BigInteger<Base>&) const;
  bool operator<(const BigInteger<Base>&) const;

  // Incremento/Decremento
  // BigInteger& operator++(); // Pre-incremento
  // BigInteger operator++(int); // Post-incremento
  // BigInteger& operator--(); // Pre-decremento
  // BigInteger operator--(int); // Post-decremento
  
  // Operadores aritméticos
  BigInteger<Base> operator+(const BigInteger<Base>&) const;
  BigInteger<Base> operator-(const BigInteger<Base>&) const;
  BigInteger<Base> operator*(const BigInteger<Base>&) const;
  BigInteger<Base> operator/(const BigInteger<Base>&) const;
  BigInteger<Base> operator%(const BigInteger<Base>&) const;

  BigInteger<10> convertirDecimal() const;
 
  private:
    BigUnsigned<Base> number_;  // El número sin signo
    bool sign_;  // El signo del número (true para negativo, false para positivo)
};

#include "BigInteger.tpp"