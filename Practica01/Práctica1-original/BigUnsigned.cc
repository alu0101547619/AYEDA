// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Curso: 2º
// Pr ́actica 1: algoritmo y estructura de datos avanzada
// Autor: Adrián Martín Castellano
// Correo: alu0101547619@ull.edu.es
// Fecha: 12/02/2025

#include "BigUnsigned.h"

/**
 * @brief Constructor por defecto
 * @param n Número a asignar
 */
BigUnsigned::BigUnsigned(unsigned n) {
  number_.clear();
  if (n == 0) {
    number_.push_back(0);
  } else {
    while (n > 0) {
      number_.push_back( n % 10);
      n /= 10;
    }
  }
}

// constructor
BigUnsigned::BigUnsigned(const unsigned char* number) {
  number_.clear();
  string str(reinterpret_cast<const char*>(number));
  for (int i = str.size() - 1; i >= 0; i--) {
    number_.push_back(str[i] - '0');
  }
}

// constructor de copia
BigUnsigned::BigUnsigned(const BigUnsigned& number) {
  number_ = number.number_;
}

/**
 * @brief Sobrecarga del operador de asignación
 * @param n Número a asignar
 * @return BigUnsigned& Número asignado
 */
BigUnsigned& BigUnsigned::operator=(const BigUnsigned& other) {
  if (this != &other) {
    number_ = other.number_;
  }
  return *this;
}

/**
 * @brief Sobrecarga del operador de inserción
 * @param os Flujo de salida
 * @param bigUnsigned Número a insertar
 * @return ostream& Flujo de salida
 */
ostream& operator<<(std::ostream& os, const BigUnsigned& bigUnsigned) {
  for (auto it = bigUnsigned.number_.rbegin(); it != bigUnsigned.number_.rend(); ++it) {
    os << static_cast<unsigned char>(*it + '0');
  }
  return os;
}

/**
 * @brief Sobrecarga del operador de extracción
 * @param is Flujo de entrada
 * @param bigUnsigned Número a extraer
 * @return istream& Flujo de entrada
 */
istream& operator>>(istream& is, BigUnsigned& bigUnsigned) {
  bigUnsigned.number_.clear();
  std::string input;
  is >> input;
  for (int i = input.size() - 1; i >= 0; i--) {
    bigUnsigned.number_.push_back(input[i] - '0');
  }
  return is;
}

/**
 * @brief Sobrecarga del operador de comparación
 * @param number Número a comparar
 * @return bool Si es igual (true) o no (false)
 */
bool BigUnsigned::operator==(const BigUnsigned& number) const {
  return number_ == number.number_;
}

/**
 * @brief Sobrecarga del operador de menor que
 * @param number Número a comparar
 * @return bool Si es menor (true) o no (false)
 */
bool operator<(const BigUnsigned& n1, const BigUnsigned& n2) {
  if (n1.number_.size() != n2.number_.size()) {
    return n1.number_.size() < n2.number_.size();
  } else {
    for (int i = n1.number_.size() - 1; i >= 0; --i) {
      if (n1.number_[i] != n2.number_[i]) return n1.number_[i] < n2.number_[i];
    }
  }
  return false;
}

/**
 * @brief Sobrecarga del operador de pre-incremento
 * @return BigUnsigned& Número incrementado
 */
BigUnsigned& BigUnsigned::operator++() { 
  bool carry = true;
  for (int i = 0; i < number_.size() && carry; ++i) {
    if (++number_[i] == 10) number_[i] = 0;
    else carry = false;
  }
  if (carry) number_.push_back(1);
  return *this;
}

/**
 * @brief Sobrecarga del operador de post-incremento
 * @return BigUnsigned Número incrementado
 */
BigUnsigned BigUnsigned::operator++(int) {
  BigUnsigned temp = *this;
  ++(*this);
  return temp;
}

/**
 * @brief Sobrecarga del operador de pre-decremento
 * @return BigUnsigned& Número decrementado
 */
BigUnsigned& BigUnsigned::operator--() {
  int borrow = 1;
  for (int i = 0; i < number_.size(); ++i) {
    int digit = number_[i] - borrow;
    if (digit < 0) {
      number_[i] = digit + 10;
      borrow = 1;
    } else {
      number_[i] = digit;
      borrow = 0;
      break;
    }
  }
  if (borrow == 1) {
    number_.pop_back();
  }
  return *this;
}

/**
 * @brief Sobrecarga del operador de post-decremento
 * @return BigUnsigned Número decrementado
 */
BigUnsigned BigUnsigned::operator--(int) {
  BigUnsigned temp = *this;
  --(*this);
  return temp;
}

/**
 * @brief Sobrecarga del operador de suma
 * @param first Primer número a sumar
 * @param second Segundo número a sumar
 * @return BigUnsigned Suma de los números
 */
BigUnsigned operator+(const BigUnsigned& first, const BigUnsigned& second) {
  BigUnsigned result;
  result.number_.clear();

  int carry = 0;
  size_t i = 0;
  
  while (i < first.number_.size() || i < second.number_.size() || carry) {
    int a = (i < first.number_.size()) ? first.number_[i] : 0;
    int b = (i < second.number_.size()) ? second.number_[i] : 0;
      
    int sum = a + b + carry;
    result.number_.push_back(sum % 10);
    carry = sum / 10;

    i++;
  }

  return result;
}

/**
 * @brief Sobrecarga del operador de resta
 * @param other Número a restar
 * @return BigUnsigned Resta de los números
 */
BigUnsigned BigUnsigned::operator-(const BigUnsigned& other) const {
  BigUnsigned result;
  result.number_.resize(number_.size());
  int borrow = 0;
  for (size_t i = 0; i < number_.size(); ++i) {
    int a = number_[i];
    int b = (i < other.number_.size()) ? other.number_[i] : 0;
    int diff = a - b - borrow;
    if (diff < 0) {
      diff += 10;
      borrow = 1;
    } else {
      borrow = 0;
    }
    result.number_[i] = diff;
  }
  while (result.number_.size() > 1 && result.number_.back() == 0) {
      result.number_.pop_back();
  }
  return result;
}

/**
 * @brief Sobrecarga del operador de multiplicación
 * @param other Número a multiplicar
 * @return BigUnsigned Multiplicación de los números
 */
BigUnsigned BigUnsigned::operator*(const BigUnsigned& other) const {
  BigUnsigned result;
  result.number_.resize(number_.size() + other.number_.size(), 0);
  for (size_t i = 0; i < number_.size(); i++) {
    int carry = 0;
    for (size_t j = 0; j < other.number_.size(); j++) {
      int sum = 0;
      for (int k = 0; k < number_[i]; k++) {
        sum += other.number_[j];
      }
      sum += result.number_[i + j] + carry;
      result.number_[i + j] = sum % 10;
      carry = 0;
      while (sum >= 10) {
        sum -= 10;
        carry++;
      }
    }
    result.number_[i + other.number_.size()] += carry;
  }
  while (result.number_.size() > 1 && result.number_.back() == 0) {
    result.number_.pop_back();
  }
  return result;
}

/**
 * @brief Sobrecarga del operador de división
 * @param n1 Número a dividir
 * @param n2 Número divisor
 * @return BigUnsigned División de los números
 */
BigUnsigned operator/(const BigUnsigned& n1, const BigUnsigned& n2) {
  if (n2 == BigUnsigned()) return BigUnsigned();
  BigUnsigned quotient;
  BigUnsigned remainder = n1;
  while (!(remainder < n2)) {
    remainder = remainder - n2;
    ++quotient;
  }
  return quotient;
}

/**
 * @brief Sobrecarga del operador de módulo
 * @param n1 Número a dividir
 * @param n2 Número divisor
 * @return BigUnsigned Módulo de los números
 */
BigUnsigned BigUnsigned::operator%(const BigUnsigned& n1) const {
  if (n1 == BigUnsigned()) return BigUnsigned();
  BigUnsigned remainder = *this;
  while (!(remainder < n1)) {
    remainder = remainder - n1;
  }
  return remainder;
}