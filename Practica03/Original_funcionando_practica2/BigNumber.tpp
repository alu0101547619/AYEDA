// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Curso: 2º
// Práctica 3: algoritmo y estructura de datos avanzada
// Autor: Adrián Martín Castellano
// Correo: alu0101547619@ull.edu.es
// Fecha: 06/03/2025

#pragma once
#include "BigNumber.h"

template <unsigned char Base>
std::ostream& operator<<(std::ostream& os, const BigNumber<Base>& num) {
    return num.write(os);
}

template <unsigned char Base>
std::istream& operator>>(std::istream& is, BigNumber<Base>& num) {
    return num.read(is);
}

template <unsigned char Base>
BigNumber<Base>* BigNumber<Base>::create(const char* str) {
    std::string input(str);
    if (input.empty()) {
        throw BigNumberBadDigit("Cadena vacía");
    }

    if (input.back() == 'u') {
        return new BigUnsigned<Base>(input.substr(0, input.size() - 1));
    } 
    else if (input.back() == 'i') {
        return new BigInteger<Base>(input.substr(0, input.size() - 1));
    } 
    else if (input.back() == 'r') {
        return new BigRational<Base>(input.substr(0, input.size() - 1));
    } 
    else {
        throw BigNumberBadDigit("Formato de número no reconocido: " + input);
    }
}