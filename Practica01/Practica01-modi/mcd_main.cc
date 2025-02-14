// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Curso: 2º
// Pr ́actica 1: algoritmo y estructura de datos avanzada
// Autor: Adrián Martín Castellano
// Correo: alu0101547619@ull.edu.es
// Fecha: 12/02/2025

#include "BigInteger.h"
#include "mcd.h"
#include "BigFloat.h"

int main () {
  std::string a;
  std::cin >> a;
  unsigned char* c = (unsigned char*)a.c_str();
  BigUnsigned number1(c);
  BigUnsigned number2;
  std::cin >> number2;
  
  if (number1 == number2) {
    std::cout << "\nSon iguales" << std::endl;
  } else {
    std::cout << "\nNo son iguales" << std::endl;
  }
  if (number1 < number2) {
    std::cout << "\nEs menor\n" << std::endl;
  } else {
    std::cout << "\nNo es menor\n" << std::endl;
  }
  std::cout << "Número1: " << number1 <<  std::endl;
  std::cout << "++Número1: " << ++number1 <<  std::endl;
  std::cout << "Número1: " << number1 <<  std::endl;

  std::cout << "\nNúmero2: " << number2 <<  std::endl;
  std::cout << "Número2++: " << number2++ <<  std::endl;
  std::cout << "Número2: " << number2 <<  std::endl;

  std::cout << "\nNúmero1: " << number1 <<  std::endl;
  std::cout << "--Número1: " << --number1 <<  std::endl;
  std::cout << "Número1: " << number1 <<  std::endl;

  std::cout << "\nNúmero2: " << number2 <<  std::endl;
  std::cout << "Número2--: " << number2-- <<  std::endl;
  std::cout << "Número2: " << number2 <<  std::endl;

  std::cout << "\nSuma de " << number1 << " + " << number2 << " : "<< number1 + number2 << std::endl;
  std::cout << "\nResta de " << number1 << " - " << number2 << " : " <<  number1 - number2 << std::endl;
  std::cout << "\nMultiplicación de " << number1 << " * " << number2 << " : " <<  number1 * number2 << std::endl;
  std::cout << "\nDivisión de " << number1 << " / " << number2 << " : " <<  number1 / number2 << std::endl;
  std::cout << "\nMódulo de " << number1 << " % " << number2 << " : " <<  number1 % number2 << std::endl;

  BigInteger number3(number1);
  std::cin >> number3;
  BigInteger number4(number2);
  std::cin >> number4;

  if (number3 == number4) {
    std::cout << "\nSon iguales" << std::endl;
  } else {
    std::cout << "\nNo son iguales" << std::endl;
  }

  if (number3 < number4) {
    std::cout << "\nEs menor\n" << std::endl;
  } else {
    std::cout << "\nNo es menor\n" << std::endl;
  }

  std::cout << "Número3: " << number3 <<  std::endl;
  std::cout << "++Número3: " << ++number3 <<  std::endl;
  std::cout << "Número3: " << number3 <<  std::endl;

  std::cout << "\nNúmero4: " << number4 <<  std::endl;
  std::cout << "Número4++: " << number4++ <<  std::endl;
  std::cout << "Número4: " << number4 <<  std::endl;

  std::cout << "\nNúmero3: " << number3 <<  std::endl;
  std::cout << "--Número3: " << --number3 <<  std::endl;
  std::cout << "Número3: " << number3 <<  std::endl;

  std::cout << "\nNúmero4: " << number4 <<  std::endl;
  std::cout << "Número4--: " << number4-- <<  std::endl;
  std::cout << "Número4: " << number4 <<  std::endl;

  std::cout << "\nSuma de " << number3 << " + " << number4 << " : "<< number3 + number4 << std::endl;
  std::cout << "\nResta de " << number3 << " - " << number4 << " : " <<  number3 - number4 << std::endl;
  std::cout << "\nMultiplicación de " << number3 << " * " << number4 << " : " <<  number3 * number4 << std::endl;
  if (!(number4 == BigInteger())) {
  std::cout << "\nDivisión de " << number3 << " / " << number4 << " : " <<  number3 / number4 << std::endl;
  std::cout << "\nMódulo de " << number3 << " % " << number4 << " : " <<  number3 % number4 << std::endl;
  }
  std::cout << "MCD de " << number3 << " y " << number4 << " : " << mcd(number3, number4) << std::endl;

  BigFloat number5(number3, number4);

  std::cout << number5 << std::endl;

  return 0;
}