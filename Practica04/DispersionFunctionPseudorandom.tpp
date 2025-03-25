#pragma once

#include "DispersionFunction.tpp"

/**
 * @brief Clase que implementa una función de dispersión que calcula el valor de dispersión de una clave mediante un valor pseudorandom.
 * @tparam Key Tipo de dato de la clave.
 */
template <class Key>
class DispersionFunctionPseudorandom : public DispersionFunction<Key> {
	public:
	  DispersionFunctionPseudorandom(unsigned tablesize); // Constructor
		virtual unsigned operator()(const Key&) const override; // Función de dispersión

	private:
		unsigned tablesize_; 
};

/**
 * @brief Constructor de la clase DispersionFunctionPseudorandom.
 * @param tablesize Tamaño de la tabla.
 * @tparam Key Tipo de dato de la clave.
 * Esta función se encarga de inicializar la tabla con el tamaño pasado por parámetro.
 */
template <class Key>
DispersionFunctionPseudorandom<Key>::DispersionFunctionPseudorandom(unsigned tablesize) {
	tablesize_ = tablesize;
}

/**
 * @brief Función de dispersión que calcula el valor de dispersión de una clave mediante un valor pseudorandom.
 * @param key Clave.
 * @tparam Key Tipo de dato de la clave.
 * @return unsigned Valor de dispersión de la clave.
 * Esta función se encarga de calcular el valor de dispersión de una clave mediante un valor pseudorandom.
 */
template <class Key>
unsigned DispersionFunctionPseudorandom<Key>::operator()(const Key& key) const {
  std::srand(key);    
	return rand() % tablesize_;
}