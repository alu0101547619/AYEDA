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
#include "BigInteger.h"
#include "BigNumber.h"

template <unsigned char Base>
class BigRational : public BigNumber<Base> {
  public:
    // Getter
    BigInteger<Base> getNum() const;
    BigUnsigned<Base> getDen() const;
  
    // Constructorea
    BigRational(const BigInteger<Base>& numerador=0, const BigUnsigned<Base>& denominador=1);
  
    // Asignación
    BigRational& operator=(const BigRational<Base>&);
  
    // Operadores inserción y extracción
    template <unsigned char B>
    friend ostream& operator<<(ostream&, const BigInteger<B>&); // Inserción de flujo
    template <unsigned char B>
    friend istream& operator>>(istream&, BigRational<B>&); // Extracción de flujo
    
    // Operadores de comparación
    bool operator==(const BigRational<Base>&) const;
    bool operator<(const BigRational<Base>&) const;
  
    // Operadores aritméticos
    BigRational<Base> operator+(const BigRational<Base>&) const;
    BigRational<Base> operator-(const BigRational<Base>&) const;
    BigRational<Base> operator*(const BigRational<Base>&) const;
    BigRational<Base> operator/(const BigRational<Base>&) const;
  
    BigRational<10> convertirDecimal() const;
    BigUnsigned<Base> mcd(const BigUnsigned<Base>&, const BigUnsigned<Base>&);
    BigRational<Base> simplificar();
    BigRational<Base> convertirBase(int);

    BigNumber<Base>& add(const BigNumber<Base>&) const override;
    BigNumber<Base>& subtract(const BigNumber<Base>&) const override;
    BigNumber<Base>& multiply(const BigNumber<Base>&) const override;
    BigNumber<Base>& divide(const BigNumber<Base>&) const override;

    // Conversión de tipo
    operator BigUnsigned<Base>() const override;
    operator BigInteger<Base>() const override;

    // Entrada y salida de datos
    std::ostream& write(std::ostream&) const override;
    std::istream& read(std::istream&) override;
   
  private:
    BigInteger<Base> num_;  // numerador que puede tener signo
    BigUnsigned<Base> den_;  // denominador que no tiene signo
};
  
#include "BigRational.tpp"