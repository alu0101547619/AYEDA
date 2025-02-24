// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Curso: 2º
// Pr ́actica 1: algoritmo y estructura de datos avanzada
// Autor: Adrián Martín Castellano
// Correo: alu0101547619@ull.edu.es
// Fecha: 12/02/2025

// #include "BigInteger.h"
// #include "mcd.h"
#include "BigUnsigned.h"

template <unsigned char Base>
void LeerInput(std::ifstream& is, BigUnsigned<Base>& a, BigUnsigned<Base>& b) {
  std::string etiqueta, igual, valor;
  while (is >> etiqueta >> igual >> valor) {
    if (etiqueta == "N1") {
      a = BigUnsigned<Base>(reinterpret_cast<const unsigned char*>(valor.c_str()));
    } else if (etiqueta == "N2") {
      b = BigUnsigned<Base>(reinterpret_cast<const unsigned char*>(valor.c_str()));
    }
  }
}

template <unsigned char Base>
void GuardarOutput(const std::string& filename, unsigned char base, const BigUnsigned<Base>& a, const BigUnsigned<Base>& b) {
  std::ofstream outFile(filename);
  if (!outFile) {
    std::cerr << "Error al abrir el archivo de salida.\n";
    return;
  }
  outFile << "Base = " << static_cast<int>(base) << std::endl;
  outFile << "N1 = " << a << std::endl;
  outFile << "N2 = " << b << std::endl;
  outFile << "N1 == N2 = " << (a == b ? "True" : "False") << std::endl;
  outFile << "N1 < N2 = " << (a < b ? "True" : "False") << std::endl;
  BigUnsigned<10> d, e;
  d = a.convertirDecimal();
  e = b.convertirDecimal();
  BigUnsigned<10> c;
  c = d + e;
  outFile << "N1 + N2 = ";
  switch (base) {
    case 8:
      outFile << c.convertirBaseOctal() << std::endl;
      break;
    case 10:
      outFile << c.convertirBaseDecimal() << std::endl;
      break;
    case 16:
      outFile << c.convertirBaseHexadecimal() << std::endl;
      break;
    default:
      outFile << "Base no soportada para N1 + N2." << std::endl;
  }
  c = d - e;
  outFile << "N1 - N2 = ";
  switch (base) {
    case 8:
      outFile << c.convertirBaseOctal() << std::endl;
      break;
    case 10:
      outFile << c.convertirBaseDecimal() << std::endl;
      break;
    case 16:
      outFile << c.convertirBaseHexadecimal() << std::endl;
      break;
    default:
      outFile << "Base no soportada para N1 - N2." << std::endl;
  }

  BigUnsigned<10> f = d * e;
  outFile << "N1 * N2 = ";
  switch (base) {
    case 8:
      outFile << f.convertirBaseOctal() << std::endl;
      break;
    case 10:
      outFile << f.convertirBaseDecimal() << std::endl;
      break;
    case 16:
      outFile << f.convertirBaseHexadecimal() << std::endl;
      break;
    default:
      outFile << "Base no soportada para N1 * N2." << std::endl;
  }

  c = d / e;
  outFile << "N1 / N2 = ";
  switch (base) {
    case 8:
      outFile << c.convertirBaseOctal() << std::endl;
      break;
    case 10:
      outFile << c.convertirBaseDecimal() << std::endl;
      break;
    case 16:
      outFile << c.convertirBaseHexadecimal() << std::endl;
      break;
    default:
      outFile << "Base no soportada para N1 / N2." << std::endl;
  }

  // Cerrar el archivo
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
      BigUnsigned<2> a, b;
      LeerInput(archivo, a, b);
      archivo.close();
    //   GuardarOutput(argv[2], base, a, b);
      break;
    }
    case 8: {
      BigUnsigned<8> a, b;
      LeerInput(archivo, a, b);
      archivo.close();
      GuardarOutput(argv[2], base, a, b);
      break;
    }
    case 10: {
      BigUnsigned<10> a, b;
      LeerInput(archivo, a, b);
      archivo.close();
      GuardarOutput(argv[2], base, a, b);
      break;
    }
    case 16: {
      BigUnsigned<16> a, b;
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