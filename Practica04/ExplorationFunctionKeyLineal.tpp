#pragma once

#include "ExplorationFunctionKey.tpp"

/**
 * @brief Clase que implementa una función de exploración que calcula el valor de exploración de una clave mediante la función lineal.
 * @tparam Key Tipo de dato de la clave.
 */
template <class Key>
class ExplorationFunctionKeyLineal : public ExplorationFuction<Key> {
  public:
    virtual unsigned operator()(const Key&, unsigned) const override; // Función de exploración
};

/**
 * @brief Función de exploración que calcula el valor de exploración de una clave mediante la función lineal.
 * @param key Clave.
 * @param i Índice.
 * @tparam Key Tipo de dato de la clave.
 * @return unsigned Valor de exploración de la clave.
 */
template <class Key>
unsigned ExplorationFunctionKeyLineal<Key>::operator()(const Key& key, unsigned i) const {
  (void)key;
  return i;
}