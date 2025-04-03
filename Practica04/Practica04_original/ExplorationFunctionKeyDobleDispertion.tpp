#pragma once

#include "ExplorationFunctionKey.tpp"
#include "DispersionFunction.tpp"

/**
 * @brief Clase que implementa una función de exploración que calcula el valor de exploración de una clave mediante la función de doble dispersión.
 * @tparam Key Tipo de dato de la clave.
 */
template <class Key>
class ExplorationFunctionKeyDobleDispertion : public ExplorationFuction<Key> {
  public:
    ExplorationFunctionKeyDobleDispertion(DispersionFunction<Key>* fd); // Constructor
    virtual unsigned operator()(const Key&, unsigned) const override; // Función de exploración

  private:
    DispersionFunction<Key>* fd_;
};

/**
 * @brief Constructor de la clase ExplorationFunctionKeyDobleDispertion.
 * @param fd Función de dispersión.
 * @tparam Key Tipo de dato de la clave.
 */
template <class Key>
ExplorationFunctionKeyDobleDispertion<Key>::ExplorationFunctionKeyDobleDispertion(DispersionFunction<Key>* fd) {
  fd_ = fd;
}

/**
 * @brief Función de exploración que calcula el valor de exploración de una clave mediante la función de doble dispersión.
 * @param key Clave.
 * @param i Índice.
 * @tparam Key Tipo de dato de la clave.
 * @return unsigned Valor de exploración de la clave.
 */
template <class Key>
unsigned ExplorationFunctionKeyDobleDispertion<Key>::operator()(const Key& key, unsigned i) const {
  return i * (*fd_)(key);
}