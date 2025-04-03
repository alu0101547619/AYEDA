// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Curso: 2º
// Pr ́actica 1: algoritmo y estructura de datos avanzada
// Autor: Adrián Martín Castellano
// Correo: alu0101547619@ull.edu.es
// Fecha: 25/02/2025

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm> 
#include "BigNumber.h"
#include "BigInteger.h"
#include "BigRational.h"

using namespace std;

template <unsigned char Base>
class BigUnsigned : public BigNumber<Base> {
 public:
  // Constructores    
  BigUnsigned(unsigned n = 0);
  BigUnsigned(const unsigned char* );
  BigUnsigned(const BigUnsigned&); // Constructor de copia

  // Getter
  const vector<unsigned char>& getNumber() const { return number_; }

  // Setter
  void setNumber(const std::vector<unsigned char>& new_number) {
    number_ = new_number;
  }

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

  // Método adicional
  BigUnsigned<10> convertirDecimal() const;

  // Operadores aritméticos de la clase base
  BigNumber<Base>& add(const BigNumber<Base>&) const override;     
  BigNumber<Base>& subtract(const BigNumber<Base>&) const override; 
  BigNumber<Base>& multiply(const BigNumber<Base>&) const override; 
  BigNumber<Base>& divide(const BigNumber<Base>&) const override;

  // Métodos de conversión
  operator BigInteger<Base>() const override;    
  operator BigRational<Base>() const override;   

  // Métodos de lectura/escritura
  std::ostream& write(std::ostream&) const override;
  std::istream& read(std::istream&) override; 

 private:
  std::vector<unsigned char> number_;
};

#include "BigUnsigned.tpp"