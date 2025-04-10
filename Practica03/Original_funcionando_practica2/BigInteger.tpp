// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Curso: 2º
// Pr ́actica 2: algoritmo y estructura de datos avanzada
// Autor: Adrián Martín Castellano
// Correo: alu0101547619@ull.edu.es
// Fecha: 25/02/2025

#pragma once
#include "BigInteger.h"

// Getter
template <unsigned char Base>
BigUnsigned<Base> BigInteger<Base>::getNumber() const {
    return number_;
} 

// Getter
template <unsigned char Base>
bool BigInteger<Base>::getSign() const {
    return sign_;
}

// Setter del signo
template <unsigned char Base>
void BigInteger<Base>::setSign(bool newSign) {
  sign_ = newSign;
}

// Constructor por defecto
template <unsigned char Base>
BigInteger<Base>::BigInteger(int number) {
  if (number < 0) {
    sign_ = true;
    number_ = BigUnsigned<Base>(static_cast<unsigned>(-number));
  } else {
    sign_ = false;
    number_ = BigUnsigned<Base>(static_cast<unsigned>(number));
  }
}

// Constructor de cambio de tipo
template <unsigned char Base>
BigInteger<Base>::BigInteger(const BigUnsigned<Base>& number) {
  number_ = number; 
  if (isNegative) sign_ = true;
  else sign_ = false; 
}


/**
 * @brief Sobrecarga del operador de asignación
 * @param n Número a asignar
 * @return BigInteger& Número asignado
 */
template <unsigned char Base>
BigInteger<Base>& BigInteger<Base>::operator=(const BigInteger<Base>& n) {
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
template <unsigned char Base>
std::ostream& operator<<(std::ostream& os, const BigInteger<Base>& number) {
  if (number.getSign()) { // Usamos el getter para el signo
    std::cout << "hola" << std::endl;
    os << '-';
  }
  os << number.getNumber(); // Usamos el getter para el número sin signo
  return os;
}



/**
 * @brief Sobrecarga del operador de extracción
 * @param is Flujo de entrada
 * @param number Número a extraer
 * @return istream& Flujo de entrada
 */
template <unsigned char Base>
istream& operator>>(istream& is, BigInteger<Base>& number) {
    string input;
    is >> input;
    if (input[0] == '-') {
        number.sign_ = true;
        input = input.substr(1); 
    } else {
        number.sign_ = false;
    }
    number.number_ = BigUnsigned<Base>(reinterpret_cast<const unsigned char*>(input.c_str()));
    return is;
}


/**
 * @brief Sobrecarga del operador de igualdad
 * @param n Número a comparar
 * @return bool Si son iguales (true) o no (false)
 */
template <unsigned char Base>
bool BigInteger<Base>::operator==(const BigInteger<Base>& number) const {
  return (sign_ == number.sign_) && (number_ == number.number_);
}

/**
 * @brief Sobrecarga del operador de menor que
 * @param n Número a comparar
 * @return bool Si es menor (true) o no (false) 
 */
template <unsigned char Base>
bool BigInteger<Base>::operator<(const BigInteger<Base>& other) const {
  if (sign_ != other.sign_ && other.number_ < number_) {
    return sign_;
  } else if (number_ < other.number_) {
    return !sign_;
  }
  return false;
}

/**
 * @brief Sobrecarga del operador de pre-incremento
 * @return BigInteger& Número incrementado
 */
// BigInteger& BigInteger::operator++() { 
//   if(sign_) {
//     if(number_ == BigUnsigned(1)) {
//       number_ = BigUnsigned();
//       sign_ = false;
//     } else number_--;
//   } else number_++;
//   return *this;
// }

/**
 * @brief Sobrecarga del operador de post-incremento
 * @return BigInteger Número incrementado
 */
// BigInteger BigInteger::operator++(int) {
//   BigInteger temp = *this;
//   ++(*this);
//   return temp;
// }

/**
 * @brief Sobrecarga del operador de pre-decremento
 * @return BigInteger& Número decrementado
 */
// BigInteger& BigInteger::operator--() {
//   if(sign_) number_++;
//   else {
//     if(number_ == BigUnsigned()) {
//       number_ = BigUnsigned(1);
//       sign_ = true;
//     } else number_--;
//   }
//   return *this;
// }

/**
 * @brief Sobrecarga del operador de post-decremento
 * @return BigInteger Número decrementado
 */
// BigInteger BigInteger::operator--(int) {
//   BigInteger temp = *this;
//   --(*this);
//   return temp;
// }

/**
 * @brief Sobrecarga del operador de suma
 * @param n Número a sumar
 * @return BigInteger Suma de los números en formato unsigned
 */
template <unsigned char Base>
BigInteger<Base> BigInteger<Base>::operator+(const BigInteger<Base>& number2) const {
  if (sign_ == number2.sign_) {
    BigUnsigned sum = number_ + number2.number_;
    return sign_ ? (BigInteger(sum) * BigInteger(-1)) : BigInteger(sum);
  } else {
    if (number_ < number2.number_) {
      BigUnsigned difference = number2.number_ - number_;
      return sign_? BigInteger(difference) : (BigInteger(difference) * BigInteger(-1));
    } else {
      BigUnsigned difference = number_ - number2.number_;
      return sign_ ? (BigInteger(difference) * BigInteger(-1)) : BigInteger(difference);
    }
  }
}

/**
 * @brief Sobrecarga del operador de resta
 * @param number Número a restar
 * @return BigInteger Resta de los números en formato unsigned
 */
template <unsigned char Base>
BigInteger<Base> BigInteger<Base>::operator-(const BigInteger<Base>& number) const {
  return *this + (number.sign_ ? BigInteger<Base>(number.number_) : BigInteger<Base>(number.number_) * BigInteger<Base>(-1));
}

/**
 * @brief Sobrecarga del operador de multiplicación
 * @param n Número a multiplicar
 * @return BigInteger Multiplicación de los números en formato unsigned
 */
template <unsigned char Base>
BigInteger<Base> BigInteger<Base>::operator*(const BigInteger<Base>& number) const {
  BigInteger result(0);
  result.number_ = number_ * number.number_;
  BigUnsigned<Base> cero;
  if (result.number_ == cero) result.sign_ = false;
  else result.sign_ = (sign_ != number.sign_);
  return result;
}  

/**
 * @brief Sobrecarga del operador de división
 * @param number1 Número a dividir
 * @param number2 Número divisor
 * @return BigInteger División de los números en formato unsigned
 */
template <unsigned char Base>
BigInteger<Base> BigInteger<Base>::operator/(const BigInteger<Base>& number2) const {
    BigInteger<Base> result;
    const BigInteger<Base> cero;
    if (this->number_ == cero.getNumber()) {
        return result;
    }
    bool result_sign = (sign_ != number2.sign_);
    BigUnsigned<Base> dividend = number_;
    BigUnsigned<Base> divisor = number2.number_;
    if (divisor == BigUnsigned<Base> ()) {
        throw std::runtime_error("Error: División por 0 en BigInteger::operator/");
    }
    result.number_ = dividend / divisor; 
    BigUnsigned<Base> cero_;
    result.sign_ = !(result.number_ == cero_) && result_sign;
    return result;
}


/**
 * @brief Sobrecarga del operador de módulo
 * @param number Número a dividir
 * @return BigInteger Módulo de los números en formato unsigned
 */
template <unsigned char Base>
BigInteger<Base> BigInteger<Base>::operator%(const BigInteger<Base>& number) const {
  BigInteger<Base> result;
  const BigInteger<Base> cero;
  if (this->number_ == cero.getNumber()) {
    return result;
  }

  BigUnsigned<Base> dividend = number_;
  BigUnsigned<Base> divisor = number.number_;
  result.number_ = dividend % divisor;
  result.sign_ = sign_;

  return result;
}

/**
 * @brief Convierte el número de la base actual a base 10.
 * @tparam Base La base en la que está representado el número original.
 * @return BigInteger<10> Número convertido a base 10.
 */
template <unsigned char Base>
BigInteger<10> BigInteger<Base>::convertirDecimal() const {

    BigUnsigned<10> resultado;
    BigUnsigned<10> cero;
    resultado = cero;  
    const vector<unsigned char>& number = number_.getNumber();
    BigUnsigned<10> baseActual(1); 
    for (size_t i = 0; i < number.size(); i++) {
        unsigned char digit = number[i];
        resultado = resultado + (BigUnsigned<10>(digit) * baseActual);
        baseActual = baseActual * BigUnsigned<10>(Base);
    }
    BigInteger<10> final(resultado); 
    final.setSign(this->getSign());
    return final;
}

