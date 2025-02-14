// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Curso: 2º
// Pr ́actica 1: algoritmo y estructura de datos avanzada
// Autor: Adrián Martín Castellano
// Correo: alu0101547619@ull.edu.es
// Fecha: 12/02/2025

#include "mcd.h"

/**
 * @brief Calcula el máximo común divisor de dos números
 * @param first_number Primer número
 * @param second_number Segundo número
 * @return BigInteger Máximo común divisor
 */
BigInteger mcd(const BigInteger& first_number, const BigInteger& second_number) {
  if (second_number == 0) 
    return first_number;
    BigInteger remainder = first_number % second_number;
    if (remainder < BigInteger()) {
      remainder = remainder + second_number;
    }
    return mcd(second_number, remainder);
}