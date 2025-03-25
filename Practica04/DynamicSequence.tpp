#pragma once

#include "Sequence.tpp"
#include <vector>

/**
 * @brief Clase que implementa una secuencia dinámica.
 * @tparam Key Tipo de dato de la clave.
 */
template <class Key>
class DynamicSequence : public Sequence<Key> {
  public:
    DynamicSequence(std::vector<int> table); // Constructor
    virtual bool search(const Key& k) const override; // Función de búsqueda
    virtual bool insert(const Key& k) override; // Función de inserción
    virtual bool isFull() const override; // Función que indica si la secuencia está llena

  private:
    std::vector<int> table_;
};

/**
 * @brief Constructor de la clase DynamicSequence.
 * @param table Tabla.
 * @tparam Key Tipo de dato de la clave.
 */
template <class Key>
DynamicSequence<Key>::DynamicSequence(std::vector<int> table) {
  table_ = table;
}

/**
 * @brief Función que indica si la secuencia está llena.
 * @tparam Key Tipo de dato de la clave.
 * @return bool Devuelve true si la secuencia está llena, false en caso contrario.
 */
template <class Key>
bool DynamicSequence<Key>::isFull() const {
  return false;
}

/**
 * @brief Función de búsqueda.
 * @param k Clave.
 * @tparam Key Tipo de dato de la clave.
 * @return bool Devuelve true si la clave se encuentra en la secuencia, false en caso contrario.
 */
template <class Key>
bool DynamicSequence<Key>::search(const Key& k) const {
  for (int i = 0; i < table_.size(); i++) {
    if (table_[i] == k) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Función de inserción.
 * @param k Clave.
 * @tparam Key Tipo de dato de la clave.
 * @return bool Devuelve true si la clave se ha insertado correctamente, false en caso contrario.
 */
template <class Key>
bool DynamicSequence<Key>::insert(const Key& k) {
  if (isFull() || search(k)) {
    return false;
  }
  table_.push_back(k);
  return true;
}