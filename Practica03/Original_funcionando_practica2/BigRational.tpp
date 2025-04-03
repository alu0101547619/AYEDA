// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Curso: 2º
// Práctica 2: algoritmo y estructura de datos avanzada
// Autor: Adrián Martín Castellano
// Correo: alu0101547619@ull.edu.es
// Fecha: 25/02/2025

#include "BigRational.h"

// Getter
template <unsigned char Base>
BigInteger<Base> BigRational<Base>::getNum() const {
    return num_;
}

// Getter
template <unsigned char Base>
BigUnsigned<Base> BigRational<Base>::getDen() const {
    return den_;
}

// Constructor de la clase
template <unsigned char Base>
BigRational<Base>::BigRational(const BigInteger<Base>& numerador, const BigUnsigned<Base>& denominador) {
    num_ = numerador;
    den_ = denominador;
}

/**
 * @brief Sobrecarga del operador de extracción para leer un número racional desde un flujo de entrada.
 * @tparam Base La base en la que están representados los números.
 * @param is Flujo de entrada desde el cual se leerá el número racional.
 * @param number Objeto BigRational<Base> donde se almacenará el número leído.
 * @return std::istream& El flujo de entrada modificado.
 */
template <unsigned char Base>
std::istream& operator>>(std::istream& is, BigRational<Base>& number) {
    std::string input;
    is >> input;
    size_t slashPos = input.find('/');
    std::string numStr = input.substr(0, slashPos);
    std::string denStr = input.substr(slashPos + 1);
    const unsigned char* numCStr = reinterpret_cast<const unsigned char*>(numStr.c_str());
    const unsigned char* denCStr = reinterpret_cast<const unsigned char*>(denStr.c_str());
    BigInteger<Base> numerador(numCStr);
    BigUnsigned<Base> denominador(denCStr);
    number = BigRational<Base>(numerador, denominador);
    return is;
}

/**
 * @brief Sobrecarga del operador de inserción para escribir un número racional en un flujo de salida.
 * @tparam Base La base en la que están representados los números.
 * @param os Flujo de salida donde se escribirá el número racional.
 * @param number Objeto BigRational<Base> que se imprimirá en el flujo de salida.
 * @return std::ostream& El flujo de salida modificado.
 */
template <unsigned char Base>
std::ostream& operator<<(std::ostream& os, const BigRational<Base>& number) {
    os << number.getNum() << "/" << number.getDen();
    return os;
}

/**
 * @brief Sobrecarga del operador de inserción para imprimir un número racional en el flujo de salida.
 * @tparam Base La base en la que están representados los números.
 * @param os Flujo de salida donde se imprimirá el número racional.
 * @param number Objeto BigRational<Base> a imprimir.
 * @return std::ostream& El flujo de salida modificado.
 */
template <unsigned char Base>
BigRational<Base>& BigRational<Base>::operator=(const BigRational<Base>& number) {
    num_ = number.getNum();
    den_ = number.getDen();
    return *this;
}

/**
 * @brief Sobrecarga del operador de asignación para BigRational. 
 * @tparam Base La base en la que están representados los números.
 * @param number Objeto BigRational<Base> a asignar.
 * @return BigRational<Base>& Referencia al objeto actual tras la asignación.
 */
template <unsigned char Base>
bool BigRational<Base>::operator==(const BigRational<Base>& number) const {
    return num_ == number.getNum() && den_ == number.getDen();
}

/**
 * @brief Sobrecarga del operador de comparación "menor que" para BigRational.
 * @tparam Base La base en la que están representados los números.
 * @param other Objeto BigRational<Base> a comparar.
 * @return true Si el número racional actual es menor que el otro.
 * @return false Si el número racional actual no es menor que el otro.
 */
template <unsigned char Base>
bool BigRational<Base>::operator<(const BigRational<Base>& other) const {
    BigInteger<Base> num1 = this->getNum();
    BigUnsigned<Base> den1 = this->getDen();
    BigInteger<Base> num2 = other.getNum();
    BigUnsigned<Base> den2 = other.getDen();
    BigInteger<Base> leftProduct = num1 * den2;
    BigInteger<Base> rightProduct = num2 * den1;
    return leftProduct < rightProduct;
}

/**
 * @brief Convierte un número racional de una base arbitraria a base 10.
 * @tparam Base La base en la que están representados los números actuales.
 * @return BigRational<10> Número racional convertido a base decimal.
 */
template <unsigned char Base>
BigRational<10> BigRational<Base>::convertirDecimal() const {
  BigRational<10> result;
  std::cout << this->getNum().getSign() << std::endl;
  BigInteger<10> num = num_.convertirDecimal();
  BigUnsigned<10> den = den_.convertirDecimal();
  result = BigRational<10>(num, den);
  return result;
}

/**
 * @brief Calcula el Máximo Común Divisor (MCD) entre dos números grandes.
 * @tparam Base La base en la que están representados los números.
 * @param first_number Primer número de entrada.
 * @param second_number Segundo número de entrada.
 * @return BigUnsigned<Base> El MCD de los dos números.
 */
template <unsigned char Base>
BigUnsigned<Base> BigRational<Base>::mcd(const BigUnsigned<Base>& first_number, const BigUnsigned<Base>& second_number) {
    BigUnsigned<Base> cero;
    if (second_number == cero) 
        return first_number;
    return mcd(second_number, first_number % second_number);
}

/**
 * @brief Simplifica el número racional dividiendo numerador y denominador por su MCD.
 * @tparam Base La base en la que están representados los números.
 * @return BigRational<Base> El número racional simplificado.
 * @throws std::runtime_error Si el MCD es 0, indicando una posible división por cero.
 */
template <unsigned char Base>
BigRational<Base> BigRational<Base>::simplificar() {
    BigUnsigned<Base> mcd_ = mcd(num_.getNumber(), den_);
    BigUnsigned<Base> cero;
    if (mcd_ == cero) {
        throw std::runtime_error("Error: MCD es 0, posible división por cero en simplificar()");
    }
    BigInteger<Base> mcd_aux(mcd_);
    BigInteger<Base> num = num_ / mcd_aux;
    BigUnsigned<Base> den = den_ / mcd_;
    return BigRational<Base>(num, den);
}

/**
 * @brief Sobrecarga del operador de suma para BigRational.
 * @tparam Base La base en la que están representados los números.
 * @param other El número racional con el que se va a sumar.
 * @return BigRational<Base> El número racional resultante de la suma.
 */
template <unsigned char Base>
BigRational<Base> BigRational<Base>::operator+(const BigRational<Base>& other) const {
    BigInteger<Base> newNum = num_ * other.den_;
    BigInteger<Base> otherNum = other.num_ * den_; 
    BigUnsigned<Base> newDen = den_ * other.den_; 
    BigInteger<Base> resultNum = newNum + otherNum;
    return BigRational<Base>(resultNum, newDen).simplificar();
}

/**
 * @brief Sobrecarga del operador de resta para BigRational.
 * @tparam Base La base en la que están representados los números.
 * @param other El número racional con el que se va a restar.
 * @return BigRational<Base> El número racional resultante de la resta.
 */
template <unsigned char Base>
BigRational<Base> BigRational<Base>::operator-(const BigRational<Base>& other) const {
    BigInteger<Base> newNum = num_ * other.den_;
    BigInteger<Base> otherNum = other.num_ * den_;
    BigUnsigned<Base> newDen = den_ * other.den_; 
    BigInteger<Base> resultNum = newNum - otherNum;
    return BigRational<Base>(resultNum, newDen).simplificar();
}

/**
 * @brief Sobrecarga del operador de multiplicación para BigRational.
 * @tparam Base La base en la que están representados los números.
 * @param other El número racional con el que se va a multiplicar.
 * @return BigRational<Base> El número racional resultante de la multiplicación.
 */
template <unsigned char Base>
BigRational<Base> BigRational<Base>::operator*(const BigRational<Base>& other) const {
    BigInteger<Base> resultNum = num_ * other.num_; 
    BigUnsigned<Base> resultDen = den_ * other.den_; 
    return BigRational<Base>(resultNum, resultDen).simplificar();
}

/**
 * @brief Sobrecarga del operador de división para BigRational.
 * @tparam Base La base en la que están representados los números.
 * @param other El número racional con el que se va a dividir.
 * @return BigRational<Base> El número racional resultante de la división.
 */
template <unsigned char Base>
BigRational<Base> BigRational<Base>::operator/(const BigRational<Base>& other) const {
    BigInteger<Base> resultNum = num_ * other.den_;
    BigUnsigned<Base> resultDen = den_ * other.num_.getNumber(); 
    return BigRational<Base>(resultNum, resultDen).simplificar();
}

template <unsigned char Base>
BigRational<Base> BigRational<Base>::convertirBase(int base) {
    BigRational<Base> result;
    BigUnsigned<Base> digits = num_.getNumber();
    BigUnsigned<Base> digits_den = den_;
    BigUnsigned<Base> base_(base); 
    std::vector<BigUnsigned<Base>> resultado_digitos_num; 
    std::vector<BigUnsigned<Base>> resultado_digitos_den;  

    // Conversión del numerador
    while (!(digits < base_)) {
        BigUnsigned<Base> cociente = digits / base_;
        BigUnsigned<Base> resto = digits % base_;

        resultado_digitos_num.push_back(resto);
        digits = cociente;
    }

    BigUnsigned<Base> cero;
    if (cero < digits) {
        resultado_digitos_num.push_back(digits);
    }

    // Conversión del denominador
    while (!(digits_den < base_)) {
        BigUnsigned<Base> cociente = digits_den / base_;
        BigUnsigned<Base> resto = digits_den % base_;

        resultado_digitos_den.push_back(resto);
        digits_den = cociente;
    }

    if (cero < digits_den) {
        resultado_digitos_den.push_back(digits_den);
    }

    // Convertimos los dígitos del numerador a un número final
    std::vector<unsigned char> number_final_num;
    for (const auto& digito : resultado_digitos_num) {
        const auto& numero = digito.getNumber();  
        for (const auto& caracter : numero) {  
            number_final_num.push_back(caracter);
        }
    }

    // Convertimos los dígitos del denominador a un número final
    std::vector<unsigned char> number_final_den;
    for (const auto& digito : resultado_digitos_den) {
        const auto& numero = digito.getNumber();
        for (const auto& caracter : numero) {
            number_final_den.push_back(caracter);
        }
    }

    // Asignar a los objetos finales
    BigUnsigned<Base> prueba_num;
    prueba_num.setNumber(number_final_num);

    BigUnsigned<Base> prueba_den;
    prueba_den.setNumber(number_final_den);
    
    BigInteger<Base> numb_sign(prueba_num);
    numb_sign.setSign(this->getNum().getSign());
    result.num_ = numb_sign;
    result.den_ = prueba_den;

    return result;
}
