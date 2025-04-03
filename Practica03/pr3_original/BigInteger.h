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
#include "BigNumber.h"
#include "BigRational.h"

template <unsigned char Base>
class BigInteger : public BigNumber<Base> {
 public:
  // Getter
  BigUnsigned<Base> getNumber() const;  // Obtiene el valor absoluto
  bool getSign() const;

  // Setter del signo
  void setSign(bool newSign) ;

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
  
  // Operadores aritméticos
  BigInteger<Base> operator+(const BigInteger<Base>&) const;
  BigInteger<Base> operator-(const BigInteger<Base>&) const;
  BigInteger<Base> operator*(const BigInteger<Base>&) const;
  BigInteger<Base> operator/(const BigInteger<Base>&) const;
  BigInteger<Base> operator%(const BigInteger<Base>&) const;

  BigInteger<10> convertirDecimal() const;

  BigNumber<Base>& add(const BigNumber<Base>&) const override;
  BigNumber<Base>& subtract(const BigNumber<Base>&) const override;
  BigNumber<Base>& multiply(const BigNumber<Base>&) const override;
  BigNumber<Base>& divide(const BigNumber<Base>&) const override;

  operator BigUnsigned<Base>() const override;
  operator BigRational<Base>() const override;

  // Métodos de lectura y escritura
  std::ostream& write(std::ostream& out) const override;
  std::istream& read(std::istream& in) override;
 
  private:
    BigUnsigned<Base> number_;  // El número sin signo
    bool sign_;  // El signo del número (true para negativo, false para positivo)
};

#include "BigInteger.tpp"