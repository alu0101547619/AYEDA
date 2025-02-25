#pragma once

#include "BigUnsigned.h"
#include "BigUnsignedB2.h"


BigUnsigned<2>::BigUnsigned(unsigned n) {
    while (n > 0) {
        bits_.push_back(n % 2);  // Añadimos el bit al vector
        n /= 2;  // Reducimos el número dividiendo entre 2
    }
    if (bits_.empty()) {
        bits_.push_back(false);  // Si es cero, almacenamos el 0
    }
}

BigUnsigned<2>::BigUnsigned(const string& str) {
    for (char c : str) {
        if (c == '1') {
            bits_.push_back(true);
        } else if (c == '0') {
            bits_.push_back(false);
        } else {
            throw std::invalid_argument("Cadena no válida para base 2");
        }
    }
}

// Operador de inserción (ostream)
ostream& operator<<(ostream& os, const BigUnsigned<2>& num) {
    for (auto it = num.bits_.rbegin(); it != num.bits_.rend(); ++it) {
        os << (*it ? '1' : '0');
    }
    return os;
}

// Operador de comparación de igualdad
bool BigUnsigned<2>::operator==(const BigUnsigned& other) const {
    return bits_ == other.bits_;
}

// Operador menor que
bool BigUnsigned<2>::operator<(const BigUnsigned& other) const {
    if (bits_.size() != other.bits_.size()) {
        return bits_.size() < other.bits_.size();
    }

    // Si tienen el mismo tamaño, comparamos bit por bit
    for (size_t i = bits_.size(); i > 0; --i) {
        if (bits_[i-1] != other.bits_[i-1]) {
            return bits_[i-1] < other.bits_[i-1];
        }
    }
    return false;  // Son iguales
}

// Operador de suma
BigUnsigned<2> BigUnsigned<2>::operator+(const BigUnsigned& other) const {
    BigUnsigned<2> result;
    bool carry = false;
    size_t max_size = std::max(bits_.size(), other.bits_.size());

    for (size_t i = 0; i < max_size; ++i) {
        bool bit1 = (i < bits_.size()) ? bits_[i] : false;
        bool bit2 = (i < other.bits_.size()) ? other.bits_[i] : false;

        bool sum = bit1 ^ bit2 ^ carry;  // XOR de los bits + acarreo
        carry = (bit1 && bit2) || (carry && (bit1 || bit2));  // Generación de acarreo

        result.bits_.push_back(sum);
    }

    if (carry) {
        result.bits_.push_back(carry);  // Si queda un acarreo al final
    }

    return result;
}

// Operador de resta
BigUnsigned<2> BigUnsigned<2>::operator-(const BigUnsigned& other) const {
    // Implementación simple de resta bit a bit (sin complemento a dos)
    BigUnsigned<2> result;
    bool borrow = false;
    size_t max_size = std::max(bits_.size(), other.bits_.size());

    for (size_t i = 0; i < max_size; ++i) {
        bool bit1 = (i < bits_.size()) ? bits_[i] : false;
        bool bit2 = (i < other.bits_.size()) ? other.bits_[i] : false;

        bool diff = bit1 ^ bit2 ^ borrow;  // XOR para la resta
        borrow = !bit1 && (bit2 || borrow);  // Verifica si se necesita "prestar"

        result.bits_.push_back(diff);
    }

    // Eliminar los ceros a la izquierda
    while (result.bits_.size() > 1 && !result.bits_.back()) {
        result.bits_.pop_back();
    }

    return result;
}

// Operador de multiplicación
BigUnsigned<2> BigUnsigned<2>::operator*(const BigUnsigned& other) const {
    BigUnsigned<2> result;

    for (size_t i = 0; i < other.bits_.size(); ++i) {
        if (other.bits_[i]) {
            BigUnsigned<2> temp = *this;
            temp.bits_.insert(temp.bits_.begin(), i, false);  // Desplazamos bits
            result = result + temp;  // Sumamos el término desplazado
        }
    }

    return result;
}

// Operador de división (simples restas sucesivas)
// Operador de división
BigUnsigned<2> BigUnsigned<2>::operator/(const BigUnsigned& divisor) const {
    // Si el divisor es 0, lanzamos una excepción (división por cero)
    if (divisor == BigUnsigned()) {
        throw std::invalid_argument("División por cero.");
    }

    BigUnsigned<2> dividend = *this;
    BigUnsigned<2> quotient;
    BigUnsigned<2> remainder;

    // Recorremos el dividendo bit por bit
    for (int i = dividend.bits_.size() - 1; i >= 0; --i) {
        remainder.bits_.insert(remainder.bits_.begin(), dividend.bits_[i]); // Agregar el siguiente bit del dividendo
        // Si el resto es mayor o igual al divisor, realizamos la resta
        if (!(remainder < divisor)) {
            remainder = remainder - divisor;
            quotient.bits_.push_back(true); // El bit del cociente es 1
        } else {
            quotient.bits_.push_back(false); // El bit del cociente es 0
        }
    }

    // El cociente tiene los bits en orden invertido, los revertimos
    std::reverse(quotient.bits_.begin(), quotient.bits_.end());

    // Eliminar los ceros a la izquierda
    while (quotient.bits_.size() > 1 && !quotient.bits_.front()) {
        quotient.bits_.erase(quotient.bits_.begin());
    }

    return quotient;
}


// Operador de módulo
// Operador de módulo
BigUnsigned<2> BigUnsigned<2>::operator%(const BigUnsigned& divisor) const {
    // Si el divisor es 0, lanzamos una excepción (módulo por cero)
    if (divisor == BigUnsigned()) {
        throw std::invalid_argument("Módulo por cero.");
    }

    BigUnsigned<2> dividend = *this;
    BigUnsigned<2> remainder;

    // Recorremos el dividendo bit por bit
    for (int i = dividend.bits_.size() - 1; i >= 0; --i) {
        remainder.bits_.insert(remainder.bits_.begin(), dividend.bits_[i]); // Agregar el siguiente bit del dividendo
        // Si el resto es mayor o igual al divisor, realizamos la resta
        if (!(remainder < divisor)) {
            remainder = remainder - divisor;
        }
    }

    return remainder;
}


