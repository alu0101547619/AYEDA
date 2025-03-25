#pragma once

#include "Sequence.tpp"
#include "StaticSequence.tpp"
#include "DispersionFunction.tpp"
#include "ExplorationFunctionKey.tpp"
#include "DynamicSequence.tpp"

/**
 * @brief Clase que implementa una tabla hash.
 * @tparam Key Tipo de dato de la clave.
 * @tparam Container Tipo de contenedor.
 */
template <class Key, class Container = StaticSequence<Key>>
class HashTable : public Sequence<Key> {
  public:
    HashTable(unsigned, DispersionFunction<Key>&, ExplorationFuction<Key>&, unsigned); // Constructor
    virtual ~HashTable(); // Destructor
    virtual bool search(const Key& k) const override; // Función de búsqueda
    virtual bool insert(const Key& k) override; // Función de inserción
    virtual bool isFull() const override { return false; } // Función que indica si la tabla está llena

  private:
    unsigned tablesize_;
    Container** table_;
    DispersionFunction<Key>* fd_;
    ExplorationFuction<Key>* fe_;
    unsigned blockSize_;

};

/**
 * @brief Clase que implementa una tabla hash con secuencias dinámicas.
 * @tparam Key Tipo de dato de la clave.
 */
template <class Key>
class HashTable<Key, DynamicSequence<Key>> : public Sequence<Key> {
  public:
    HashTable(unsigned, DispersionFunction<Key>&); // Constructor
    virtual ~HashTable(); // Destructor
    virtual bool search(const Key& k) const override; // Función de búsqueda
    virtual bool insert(const Key& k) override; // Función de inserción
    virtual bool isFull() const override { return false; } // Función que indica si la tabla está llena

  private:
    unsigned tablesize_;
    std::vector<StaticSequence<Key>*> table_;
    DispersionFunction<Key>* fd_;

};

/**
 * @brief Constructor de la clase HashTable.
 * @param tablesize Tamaño de la tabla.
 * @param fd Función de dispersión.
 * @param fe Función de exploración.
 */
template <class Key, class Container>
HashTable<Key,Container>::HashTable(unsigned tablesize, DispersionFunction<Key>& fd, ExplorationFuction<Key>& fe, unsigned blockSize) : tablesize_(tablesize), fd_(&fd), fe_(&fe), blockSize_(blockSize) {
  table_ = new Container*[tablesize_];
  for (unsigned i = 0; i < tablesize_; i++) {
    table_[i] = new Container(blockSize_);
  }
}

/**
 * @brief Destructor de la clase HashTable.
 * @tparam Key Tipo de dato de la clave.
 * @tparam Container Tipo de contenedor.
 */
template <class Key, class Container>
HashTable<Key,Container>::~HashTable() {
  for (unsigned i = 0; i < tablesize_; i++) {
    delete table_[i];
  }
  delete[] table_;
}

/**
 * @brief Función de búsqueda.
 * @param k Clave.
 * @tparam Key Tipo de dato de la clave.
 * @return bool Devuelve true si la clave se encuentra en la tabla, false en caso contrario.
 */
template <class Key, class Container>
bool HashTable<Key,Container>::search(const Key& k) const {
  unsigned initial = fd_->operator()(k) % tablesize_;
  for (unsigned i = 0; i < tablesize_; i++) {
    unsigned pos = (initial + fe_->operator()(k, i)) % tablesize_;
    if (table_[pos]->search(k)) {
      return true;
    }
    if (!table_[pos]->isFull()) {
      return false;
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
template <class Key, class Container>
bool HashTable<Key,Container>::insert(const Key& k) {
  unsigned initial = fd_->operator()(k) % tablesize_;
  for (unsigned i = 0; i < tablesize_; i++) {
    unsigned pos = (initial + fe_->operator()(k, i)) % tablesize_;
    if (table_[pos]->search(k)) {
      return false;
    }
    if (!table_[pos]->isFull()) {
      table_[pos]->insert(k);
      return true;
    }
  }
  return false;
}

/**
 * @brief Constructor de la clase HashTable.
 * @param tablesize Tamaño de la tabla.
 * @param fd Función de dispersión.
 * @tparam Key Tipo de dato de la clave.
 * @tparam Container Tipo de contenedor.
 */
template <class Key>
HashTable<Key,DynamicSequence<Key>>::HashTable(unsigned tablesize, DispersionFunction<Key>& fd) : tablesize_(tablesize), fd_(&fd) {
  for (unsigned i = 0; i < tablesize_; i++) {
    table_.push_back(new StaticSequence<Key>(1));
  }
}

/**
 * @brief Destructor de la clase HashTable.
 * @tparam Key Tipo de dato de la clave.
 */
template <class Key>
HashTable<Key,DynamicSequence<Key>>::~HashTable() {
  for (unsigned i = 0; i < tablesize_; i++) {
    delete table_[i];
  }
}

/**
 * @brief Función de búsqueda.
 * @param k Clave.
 * @tparam Key Tipo de dato de la clave.
 * @return bool Devuelve true si la clave se encuentra en la tabla, false en caso contrario.
 */
template <class Key>
bool HashTable<Key,DynamicSequence<Key>>::search(const Key& k) const {
  unsigned pos = fd_->operator()(k) % tablesize_;
  return table_[pos]->search(k);
}

/** 
 * @brief Función de inserción.
 * @param k Clave.
 * @tparam Key Tipo de dato de la clave.
 * @return bool Devuelve true si la clave se ha insertado correctamente, false en caso contrario.
 */
template <class Key>
bool HashTable<Key,DynamicSequence<Key>>::insert(const Key& k) {
  unsigned pos = fd_->operator()(k) % tablesize_;
  return table_[pos]->insert(k);
}