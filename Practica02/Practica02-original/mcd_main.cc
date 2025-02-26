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
// #include "BigUnsignedB2.h"

template <unsigned char Base>
void LeerInput(std::ifstream& is, BigRational<Base>& a, BigRational<Base>& b) {
    std::string etiqueta, igual;
    BigRational<Base> valor;
    std::string linea;
    std::getline(is, linea);
    while (is >> etiqueta >> igual >> valor) {
        if (etiqueta == "N1") {
            a = valor;
        } else if (etiqueta == "N2") {
            b = valor;
        }
    }
}

template <unsigned char Base>
void GuardarOutput(const std::string& filename, unsigned char base, const BigRational<Base>& a, const BigRational<Base>& b) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error al abrir el archivo de salida.\n";
        return;
    }

    outFile << "Base = " << static_cast<int>(base) << std::endl;
    outFile << "N1 = " << a << std::endl;
    outFile << "N2 = " << b << std::endl;
    BigRational<10> c = a.convertirDecimal();
    BigRational<10> d = b.convertirDecimal();
    c = c.simplificar();
    d = d.simplificar();
    outFile << "N1 simplificado = " << c << std::endl;
    outFile << "N2 simplificado = " << d << std::endl;
    outFile << "N1 == N2 = " << (c == d ? "True" : "False") << std::endl;
    outFile << "N1 < N2 = " << (c < d ? "True" : "False") << std::endl;

    // Operaciones aritméticas con fracciones
    outFile << "N1 + N2 = " << c + d << std::endl;
    outFile << "N1 - N2 = " << c - d << std::endl;
    outFile << "N1 * N2 = " << c * d << std::endl;
    outFile << "N1 / N2 = " << c / d << std::endl;

    outFile.close();
}


int main(int argc, char* argv[]) {
  if (argc < 3) {
      std::cerr << "Uso: " << argv[0] << " <archivo_entrada> <archivo_salida>" << std::endl;
      return 1;
  }


  std::ifstream archivo(argv[1]);
  if (!archivo) {
      std::cerr << "Error al abrir el archivo de entrada: " << argv[1] << std::endl;
      return 1;
  }

  std::ofstream outFile(argv[2]);
  if (!outFile) {
      std::cerr << "Error al abrir el archivo de salida: " << argv[2] << std::endl;
      return 1;
  }

  unsigned char base = 10;
  std::string etiqueta, igual, valor;

  while (archivo >> etiqueta >> igual >> valor) {
      if (etiqueta == "Base") {
          base = static_cast<unsigned char>(std::stoi(valor));
          break;
      }
  }

  archivo.clear();
  archivo.seekg(0, std::ios::beg);

  switch (base) {
      case 2: {
          BigRational<2> a, b;
          LeerInput(archivo, a, b);
          archivo.close();
          GuardarOutput(argv[2], base, a, b);
          break;
      }
      case 8: {
          BigRational<8> a, b;
          LeerInput(archivo, a, b);
          archivo.close();
          GuardarOutput(argv[2], base, a, b);
          break;
      }
      case 10: {
          BigRational<10> a, b;
          LeerInput(archivo, a, b);
          archivo.close();
          GuardarOutput(argv[2], base, a, b);
          break;
      }
      case 16: {
          BigRational<16> a, b;
          LeerInput(archivo, a, b);
          archivo.close();
          GuardarOutput(argv[2], base, a, b);
          break;
      }
      default:
          std::cerr << "Base no soportada: " << static_cast<int>(base) << std::endl;
          archivo.close();
          return 1;
  }

  return 0;
}