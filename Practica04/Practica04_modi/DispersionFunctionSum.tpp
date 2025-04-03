#pragma once

#include "DispersionFunction.tpp"

/**
 * @brief Clase que implementa una función de dispersión que calcula el valor de dispersión de una clave mediante la suma de los dígitos de la clave.
 * @tparam Key Tipo de dato de la clave.
 */
template <class Key>
class DispersionFunctionSum : public DispersionFunction<Key> {
	public:
	  DispersionFunctionSum(unsigned tablesize); // Constructor
		virtual unsigned operator()(const Key&) const override; // Función de dispersión

	private:
		unsigned tablesize_; 
};

/**
 * @brief Constructor de la clase DispersionFunctionSum.
 * @param tablesize Tamaño de la tabla.
 * @tparam Key Tipo de dato de la clave.
 */
template <class Key>
DispersionFunctionSum<Key>::DispersionFunctionSum(unsigned tablesize) {
  tablesize_ = tablesize;
}

/**
 * @brief Función de dispersión que calcula el valor de dispersión de una clave mediante la suma de los dígitos de la clave.
 * @param key Clave.
 * @tparam Key Tipo de dato de la clave.
 * @return unsigned Valor de dispersión de la clave.
 */
template <class Key>
unsigned DispersionFunctionSum<Key>::operator()(const Key& key) const {
  unsigned sum = 0;
  unsigned key_var = key;
  unsigned var = 0;
  while (key_var > 0) {
    var = key_var % 10;
    sum += var;
    key_var /= 10;
  }
  return sum % tablesize_;
}