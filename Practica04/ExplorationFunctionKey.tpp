#pragma once

#include <iostream>

/**
 * @brief Clase abstracta que define una función de exploración.
 * @tparam Key Tipo de dato de la clave.
 */
template <class Key>
class ExplorationFuction {
  public:
    virtual unsigned operator()(const Key&, unsigned) const = 0; // Función de exploración
};