// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Curso: 2º
// Pr ́actica 1: algoritmo y estructura de datos avanzada
// Autor: Adrián Martín Castellano
// Correo: alu0101547619@ull.edu.es
// Fecha: 25/02/2025

bool isNegative = false;

#include "BigUnsigned.h"
#include "BigInteger.h"
#include "BigRational.h"
#include "BigNumber.h"

// template <unsigned char Base>
// void LeerInput(std::ifstream& is, BigRational<Base>& a, BigRational<Base>& b) {
//     std::string etiqueta, igual;
//     BigRational<Base> valor;
//     std::string linea;
//     std::getline(is, linea);
//     while (is >> etiqueta >> igual >> valor) {
//         if (etiqueta == "N1") {
//             a = valor;
//         } else if (etiqueta == "N2") {
//             b = valor;
//         }
//     }
// }

// template <unsigned char Base>
// void GuardarOutput(const std::string& filename, unsigned char base, const BigRational<Base>& a, const BigRational<Base>& b) {
//     std::ofstream outFile(filename);
//     if (!outFile) {
//         std::cerr << "Error al abrir el archivo de salida.\n";
//         return;
//     }
    
//     outFile << "Base = " << static_cast<int>(base) << std::endl;
//     outFile << "N1 = " << a << std::endl;
//     outFile << "N2 = " << b << std::endl;
//     BigRational<10> c = a.convertirDecimal();
//     BigRational<10> d = b.convertirDecimal();
//     std::cout << c.getNum().getSign() << " " << d.getNum().getSign() << std::endl;
//     c = c.simplificar();
//     d = d.simplificar();
//     outFile << "N1 simplificado = " << c << std::endl;
//     outFile << "N2 simplificado = " << d << std::endl;
//     outFile << "N1 == N2 = " << (c == d ? "True" : "False") << std::endl;
//     outFile << "N1 < N2 = " << (c < d ? "True" : "False") << std::endl;

//     // Operaciones aritméticas con fracciones
//     outFile << "N1 + N2 = " << c + d << std::endl;
//     outFile << "N1 - N2 = " << c - d << std::endl;
//     outFile << "N1 * N2 = " << c * d << std::endl;
//     outFile << "N1 / N2 = " << c / d << std::endl;

//     c = c.convertirBase(static_cast<int>(base));
//     outFile << "Conversion = " <<c << std::endl;
//     d = d.convertirBase(static_cast<int>(base));
//     outFile << "Conversion = " << d << std::endl;
//     outFile.close();
// }

int main(int argc, char* argv[]) {
    try {
        BigNumber<10>* bigUnsigned1 = BigNumber<10>::create("1234u");
        BigNumber<10>* bigUnsigned2 = BigNumber<10>::create("5678u");
        BigNumber<10>* sumResult = bigUnsigned1->add(*bigUnsigned2);
        std::cout << "Resultado de la suma: " << *sumResult << std::endl;
        delete bigUnsigned1;
        delete bigUnsigned2;
        delete sumResult;
    } catch (const std::exception& e) {
        std::cout << "Excepción: " << e.what() << std::endl;
    }

  return 0;
}