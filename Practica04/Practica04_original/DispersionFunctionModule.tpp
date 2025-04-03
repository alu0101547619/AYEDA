// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Curso: 2º
// Práctica 3: algoritmo y estructura de datos avanzada
// Autor: Adrián Martín Castellano
// Correo: alu0101547619@ull.edu.es
// Fecha: 25/03/2025

#pragma once

#include "DispersionFunction.tpp"

/**
 * @brief Clase que implementa una función de dispersión que calcula el valor de dispersión de una clave 
 * mediante el módulo de la clave y el tamaño de la tabla.
 * @tparam Key Tipo de dato de la clave.
 */
template <class Key>
class DispersionFunctionModule : public DispersionFunction<Key> {
	public:
	  DispersionFunctionModule(unsigned tablesize); // Constructor
		virtual unsigned operator()(const Key&) const override; // Función de dispersión

	private:
		unsigned tablesize_; 
};

/**
 * @brief Constructor de la clase DispersionFunctionModule.
 * @param tablesize Tamaño de la tabla.
 * @tparam Key Tipo de dato de la clave.
 */
template <class Key>
DispersionFunctionModule<Key>::DispersionFunctionModule(unsigned tablesize) {
	tablesize_ = tablesize;
}

/**
 * @brief Función de dispersión que calcula el valor de dispersión de una clave mediante el módulo de la clave y el tamaño de la tabla.
 * @param key Clave.
 * @tparam Key Tipo de dato de la clave.
 * @return unsigned Valor de dispersión de la clave.
 */
template <class Key>
unsigned DispersionFunctionModule<Key>::operator()(const Key& key) const {
	return key % tablesize_;
}