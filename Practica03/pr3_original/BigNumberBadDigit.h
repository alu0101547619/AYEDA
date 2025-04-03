// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Curso: 2º
// Práctica 3: algoritmo y estructura de datos avanzada
// Autor: Adrián Martín Castellano
// Correo: alu0101547619@ull.edu.es
// Fecha: 06/03/2025

#pragma once

#include "BigNumberException.h"

class BigNumberBadDigit : public BigNumberException {
  public:
    explicit BigNumberBadDigit(const std::string& msg) : BigNumberException("BigNumberBadDigit: " + msg) {}
};