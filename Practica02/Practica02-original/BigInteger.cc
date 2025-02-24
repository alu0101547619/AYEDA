// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Curso: 2º
// Pr ́actica 1: algoritmo y estructura de datos avanzada
// Autor: Adrián Martín Castellano
// Correo: alu0101547619@ull.edu.es
// Fecha: 12/02/2025

#include "BigInteger.h"

BigUnsigned BigInteger::getNumber() const {
    return number_;
} 

bool BigInteger::getSign() const {
    return sign_;
}

// Constructor por defecto
BigInteger::BigInteger(int number) {
  if (number < 0) {
    sign_ = true;
    number_ = BigUnsigned(static_cast<unsigned>(-number));
  } else {
    sign_ = false;
    number_ = BigUnsigned(static_cast<unsigned>(number));
  }
}


// Constructor de cambio de tipo
BigInteger::BigInteger(const BigUnsigned& number) {
  number_ = number;
  sign_ = false;
}

/**
 * @brief Sobrecarga del operador de asignación
 * @param n Número a asignar
 * @return BigInteger& Número asignado
 */
BigInteger& BigInteger::operator=(const BigInteger& n) {
  if (this != &n) {
    number_ = n.number_;
    sign_ = n.sign_;
  }
  return *this;
}

/**
 * @brief Sobrecarga del operador de inserción
 * @param os Flujo de salida
 * @param number Número a insertar
 * @return ostream& Flujo de salida
 */
ostream& operator<<(ostream& os, const BigInteger& number) {
  if (number.sign_) {
    os << '-';
  }
  os << number.number_;
  return os;
}

/**
 * @brief Sobrecarga del operador de extracción
 * @param is Flujo de entrada
 * @param number Número a extraer
 * @return istream& Flujo de entrada
 */
istream& operator>>(istream& is, BigInteger& number) {
    string input;
    is >> input;
    if (input[0] == '-') {
      number.sign_ = true;
      input = input.substr(1);
    } else {
      number.sign_ = false;
    }
    number.number_ = BigUnsigned(reinterpret_cast<const unsigned char*>(input.c_str()));
    return is;
}

/**
 * @brief Sobrecarga del operador de igualdad
 * @param n Número a comparar
 * @return bool Si son iguales (true) o no (false)
 */
bool BigInteger::operator==(const BigInteger& number) const {
  return (sign_ == number.sign_) && (number_ == number.number_);
}

/**
 * @brief Sobrecarga del operador de menor que
 * @param n Número a comparar
 * @return bool Si es menor (true) o no (false) 
 */
bool operator<(const BigInteger& number1, const BigInteger& number2) {
  if(number1.sign_ != number2.sign_ && number2.number_ < number1.number_) {
    return number1.sign_;
  } else if (number1.number_ < number2.number_) { return !number1.sign_; }
  return false;
}

/**
 * @brief Sobrecarga del operador de pre-incremento
 * @return BigInteger& Número incrementado
 */
BigInteger& BigInteger::operator++() { 
  if(sign_) {
    if(number_ == BigUnsigned(1)) {
      number_ = BigUnsigned();
      sign_ = false;
    } else number_--;
  } else number_++;
  return *this;
}

/**
 * @brief Sobrecarga del operador de post-incremento
 * @return BigInteger Número incrementado
 */
BigInteger BigInteger::operator++(int) {
  BigInteger temp = *this;
  ++(*this);
  return temp;
}

/**
 * @brief Sobrecarga del operador de pre-decremento
 * @return BigInteger& Número decrementado
 */
BigInteger& BigInteger::operator--() {
  if(sign_) number_++;
  else {
    if(number_ == BigUnsigned()) {
      number_ = BigUnsigned(1);
      sign_ = true;
    } else number_--;
  }
  return *this;
}

/**
 * @brief Sobrecarga del operador de post-decremento
 * @return BigInteger Número decrementado
 */
BigInteger BigInteger::operator--(int) {
  BigInteger temp = *this;
  --(*this);
  return temp;
}

/**
 * @brief Sobrecarga del operador de suma
 * @param n Número a sumar
 * @return BigInteger Suma de los números en formato unsigned
 */
BigInteger operator+(const BigInteger& number1, const BigInteger& number2) {
  if (number1.sign_ == number2.sign_) {
    BigUnsigned sum = number1.number_ + number2.number_;
    return number1.sign_ ? (BigInteger(sum) * BigInteger(-1)) : BigInteger(sum);
  } else {
    if (number1.number_ < number2.number_) {
      BigUnsigned difference = number2.number_ - number1.number_;
      return number1.sign_? BigInteger(difference) : (BigInteger(difference) * BigInteger(-1));
    } else {
      BigUnsigned difference = number1.number_ - number2.number_;
      return number1.sign_ ? (BigInteger(difference) * BigInteger(-1)) : BigInteger(difference);
    }
  }
}

/**
 * @brief Sobrecarga del operador de resta
 * @param number Número a restar
 * @return BigInteger Resta de los números en formato unsigned
 */
BigInteger BigInteger::operator-(const BigInteger& number) const {
  return *this + (number.sign_ ? BigInteger(number.number_) : BigInteger(number.number_) * BigInteger(-1));
}

/**
 * @brief Sobrecarga del operador de multiplicación
 * @param n Número a multiplicar
 * @return BigInteger Multiplicación de los números en formato unsigned
 */
BigInteger BigInteger::operator*(const BigInteger& number) const {
  BigInteger result(0);
  result.number_ = number_ * number.number_;
  if (result.number_ == BigUnsigned()) result.sign_ = false;
  else result.sign_ = (sign_ != number.sign_);
  return result;
}  

/**
 * @brief Sobrecarga del operador de división
 * @param number1 Número a dividir
 * @param number2 Número divisor
 * @return BigInteger División de los números en formato unsigned
 */
BigInteger operator/(const BigInteger& number1, const BigInteger& number2) {
  BigInteger result(0);
  if (number1 == BigInteger(0)) {
    return result;
  }

  bool result_sign = (number1.sign_ != number2.sign_);
  BigUnsigned dividend = number1.number_;
  BigUnsigned divisor = number2.number_;
  result.number_ = dividend / divisor;
  result.sign_ = !(result.number_ == BigUnsigned()) && result_sign;

  return result;
}

/**
 * @brief Sobrecarga del operador de módulo
 * @param number Número a dividir
 * @return BigInteger Módulo de los números en formato unsigned
 */
BigInteger BigInteger::operator%(const BigInteger& number) const {
  BigInteger result(0);
  if (number == BigInteger(0)) {
    return result;
  }
  BigUnsigned dividend = number_;
  BigUnsigned divisor = number.number_;
  result.number_ = dividend % divisor;
  result.sign_ = sign_;

  return result;
}