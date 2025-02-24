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

/**
 * @brief Constructor por defecto
 * @param n Número a asignar
 */
template <unsigned char Base>
BigUnsigned<Base>::BigUnsigned(unsigned n) {
  std::cout << "NO\n";
  number_.clear();
  if (n == 0) {
    number_.push_back(0);
  } else {
    while (n > 0) {
      number_.push_back( n % Base);
      n /= Base;
    }
  }
}

// constructor
template <unsigned char Base>
BigUnsigned<Base>::BigUnsigned(const unsigned char* number) {
  std::cout << "NO\n";
  number_.clear();
  string str(reinterpret_cast<const char*>(number));

  for (int i = str.size() - 1; i >= 0; i--) {
    unsigned char digit;

    if (str[i] >= '0' && str[i] <= '9') {
      digit = str[i] - '0';
    } else if (Base > 10 && str[i] >= 'A' && str[i] <= 'F') {
      digit = str[i] - 'A' + 10;
    } else if (Base > 10 && str[i] >= 'a' && str[i] <= 'f') {
      digit = str[i] - 'a' + 10;
    } else {
      throw invalid_argument("Número contiene dígitos inválidos para la base especificada.");
    }

    if (digit >= Base) {
      throw invalid_argument("Dígito inválido para la base especificada.");
    }

    number_.push_back(digit);
  }
}

// constructor de copia
template <unsigned char Base>
BigUnsigned<Base>::BigUnsigned(const BigUnsigned<Base>& number) {
  number_ = number.number_;
}

/**
 * @brief Sobrecarga del operador de asignación
 * @param n Número a asignar
 * @return BigUnsigned& Número asignado
 */
template <unsigned char Base>
BigUnsigned<Base>& BigUnsigned<Base>::operator=(const BigUnsigned<Base>& other) {
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
template <unsigned char Base>
ostream& operator<<(std::ostream& os, const BigUnsigned<Base>& bigUnsigned) {
  for (auto it = bigUnsigned.number_.rbegin(); it != bigUnsigned.number_.rend(); ++it) {
    if (*it < 10) {
      os << static_cast<unsigned char>(*it + '0');  // 0-9
    } else {
      os << static_cast<unsigned char>(*it - 10 + 'A');  // 10-15 → A-F
    }
  }
  return os;
}

/**
 * @brief Sobrecarga del operador de extracción
 * @param is Flujo de entrada
 * @param bigUnsigned Número a extraer
 * @return istream& Flujo de entrada
 */
template <unsigned char Base>
istream& operator>>(istream& is, BigUnsigned<Base>& bigUnsigned) {
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
template <unsigned char Base>
bool BigUnsigned<Base>::operator==(const BigUnsigned<Base>& number) const {
  return number_ == number.number_;
}

/**
 * @brief Sobrecarga del operador de menor que
 * @param number Número a comparar
 * @return bool Si es menor (true) o no (false)
 */
template <unsigned char Base>
bool BigUnsigned<Base>::operator<(const BigUnsigned<Base>& n1) const {
  if (number_.size() != n1.number_.size()) {
    return number_.size() < n1.number_.size();
  } else {
    for (int i = number_.size() - 1; i >= 0; --i) {
      if (number_[i] != n1.number_[i]) {
        return number_[i] < n1.number_[i];
      }
    }
  }
  return false; 
}

/**
 * @brief Sobrecarga del operador de suma
 * @param first Primer número a sumar
 * @param second Segundo número a sumar
 * @return BigUnsigned Suma de los números
 */
template <unsigned char Base>
BigUnsigned<Base> BigUnsigned<Base>::operator+(const BigUnsigned<Base>& n1) const {
  BigUnsigned<Base> result;
  result.number_.clear();
  int carry = 0;
  size_t i = 0;
  while (i < number_.size() || i < n1.number_.size() || carry) {
    int a = (i < number_.size()) ? number_[i] : 0;  
    int b = (i < n1.number_.size()) ? n1.number_[i] : 0;   
    int sum = a + b + carry; 
    result.number_.push_back(sum % Base);  
    carry = sum / Base;  
    i++;
  }
  return result;
}

/**
 * @brief Sobrecarga del operador de resta
 * @param other Número a restar
 * @return BigUnsigned Resta de los números
 */
template <unsigned char Base>
BigUnsigned<Base> BigUnsigned<Base>::operator-(const BigUnsigned<Base>& other) const {
  BigUnsigned result;
  result.number_.resize(number_.size());
  int borrow = 0;
  for (size_t i = 0; i < number_.size(); ++i) {
    int a = number_[i];
    int b = (i < other.number_.size()) ? other.number_[i] : 0;
    int diff = a - b - borrow;
    if (diff < 0) {
      diff += Base;
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
template <unsigned char Base>
BigUnsigned<Base> BigUnsigned<Base>::operator*(const BigUnsigned<Base>& other) const {
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
      result.number_[i + j] = sum % Base;
      carry = 0;
      while (sum >= Base) {
        sum -= Base;
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
template <unsigned char Base>
BigUnsigned<Base> BigUnsigned<Base>::operator/(const BigUnsigned& n1) const {
  if (n1 == BigUnsigned()) return BigUnsigned();
  BigUnsigned quotient;
  BigUnsigned remainder = *this;
  while (!(remainder < n1)) {
    remainder = remainder - n1;
    quotient = quotient + BigUnsigned<Base>(1);
  }
  return quotient;
}

/**
 * @brief Sobrecarga del operador de módulo
 * @param n1 Número a dividir
 * @param n2 Número divisor
 * @return BigUnsigned Módulo de los números
 */
template <unsigned char Base>
BigUnsigned<Base> BigUnsigned<Base>::operator%(const BigUnsigned& n1) const {
  if (n1 == BigUnsigned<Base>()) return BigUnsigned<Base>();
  BigUnsigned<Base> remainder = *this;
  while (!(remainder < n1)) {
    remainder = remainder - n1;
  }
  return remainder;
}

template <unsigned char Base>
BigUnsigned<10> BigUnsigned<Base>::convertirDecimal() const {
  BigUnsigned<10> resultado;
  BigUnsigned<10> baseActual(1);
  for (size_t i = 0; i < number_.size(); i++) {
    resultado = resultado + (BigUnsigned<10>(number_[i]) * baseActual);
    baseActual = baseActual * BigUnsigned<10>(Base);
  }
  return resultado;
}

template <unsigned char Base>
BigUnsigned<Base> BigUnsigned<Base>::convertirBase(unsigned char nuevaBase) const {

  // Convertimos primero a decimal si la base no es 10
  BigUnsigned<10> temp = this->convertirDecimal();
  BigUnsigned<Base> resultado;  
  resultado.number_.clear();

  BigUnsigned<Base> cero;
  while (!(temp == cero)) {
    BigUnsigned<10> digito = temp % BigUnsigned<10>(nuevaBase);
    resultado.number_.push_back(digito.number_[0]); // Agregar dígito
    temp = temp / BigUnsigned<10>(nuevaBase);
  }

  if (resultado.number_.empty()) {
    resultado.number_.push_back(0);
  }

  return resultado;
}



