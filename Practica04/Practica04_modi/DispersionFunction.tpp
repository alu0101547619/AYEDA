// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Curso: 2º
// Práctica 3: algoritmo y estructura de datos avanzada
// Autor: Adrián Martín Castellano
// Correo: alu0101547619@ull.edu.es
// Fecha: 25/03/2025

#pragma once

#include <iostream>

/**
 * @brief Clase abstracta que define una función de dispersión.
 * @tparam Key Tipo de dato de la clave.
 * Esta clase define una función de dispersión que se encarga de
 * calcular el valor de dispersión de una clave.
 */
template <class Key>
class DispersionFunction {
public:
	virtual unsigned operator()(const Key&) const = 0; // Función de dispersión
};