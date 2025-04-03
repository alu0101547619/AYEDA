// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Curso: 2º
// Práctica 3: algoritmo y estructura de datos avanzada
// Autor: Adrián Martín Castellano
// Correo: alu0101547619@ull.edu.es
// Fecha: 06/03/2025

#pragma once
#include <iostream>
#include <string>
#include "BigUnsigned.h"
#include "BigInteger.h"
#include "BigRational.h"


template <unsigned char Base>
class BigNumber {
public:
    // Operadores aritméticos
    virtual BigNumber<Base>& add(const BigNumber<Base>&) const = 0;
    virtual BigNumber<Base>& subtract(const BigNumber<Base>&) const = 0;
    virtual BigNumber<Base>& multiply(const BigNumber<Base>&) const = 0;
    virtual BigNumber<Base>& divide(const BigNumber<Base>&) const = 0;

    // Cambio de tipo
    virtual operator BigUnsigned<Base>() const = 0;
    virtual operator BigInteger<Base>() const = 0;
    virtual operator BigRational<Base>() const = 0;

    // Entrada/salida de datos
    virtual std::ostream& write(std::ostream&) const = 0;
    virtual std::istream& read(std::istream&) = 0;

    // Operadores de flujo
    template <unsigned char B>
    friend std::ostream& operator<<(std::ostream&, const BigNumber<B>&);
    template <unsigned char B>
    friend std::istream& operator>>(std::istream&, BigNumber<B>&);

    // Método estático para crear instancias en tiempo de ejecución
    static BigNumber<Base>* create(const char*);

    // Destructor virtual
    virtual ~BigNumber() {}
};
