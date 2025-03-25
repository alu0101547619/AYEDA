#pragma once

#include "ExplorationFunctionKey.tpp"
#include "DispersionFunction.tpp"

/**
 * @brief Clase que implementa una función de exploración que calcula el valor de exploración de una clave mediante la función de redispersión.
 * @tparam Key Tipo de dato de la clave.
 */
template <class Key>
class ExplorationFunctionKeyRedispertion : public ExplorationFuction<Key> {
  public:
    ExplorationFunctionKeyRedispertion(DispersionFunction<Key>* fd, unsigned tablesize); // Constructor
    virtual unsigned operator()(const Key&, unsigned) const override; // Función de exploración
  private:
    DispersionFunction<Key>* fd_;
    unsigned tablesize_;
  
};

/**
 * @brief Constructor de la clase ExplorationFunctionKeyRedispertion.
 * @param fd Función de dispersión.
 * @param tablesize Tamaño de la tabla.
 * @tparam Key Tipo de dato de la clave.
 */
template <class Key>
ExplorationFunctionKeyRedispertion<Key>::ExplorationFunctionKeyRedispertion(DispersionFunction<Key>* fd, unsigned tablesize) {
  tablesize_ = tablesize;
  fd_ = fd;
}

/**
 * @brief Función de exploración que calcula el valor de exploración de una clave mediante la función de redispersión.
 * @param key Clave.
 * @param i Índice.
 * @tparam Key Tipo de dato de la clave.
 * @return unsigned Valor de exploración de la clave.
 */
template <class Key>
unsigned ExplorationFunctionKeyRedispertion<Key>::operator()(const Key& key, unsigned i) const {
  (*fd_)(key); 
  for (unsigned j = 0; j < i; j++) {
    std::rand();
  }
  return tablesize_ % std::rand();
}