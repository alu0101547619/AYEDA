#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "Nif.hpp"
#include "StaticSequence.tpp"
#include "SortMethod.tpp"
#include "Insertion.tpp"
#include "Sacudida.tpp"
#include "QuickSort.tpp"
#include "HeapSort.tpp"
#include "ShellSort.tpp"

using namespace std;

int main(int argc, char* argv[]) {
  int i = 1;
  unsigned size;
  string fdCode, hashTechnique, filename;
  bool trace = false;
  double alfa = 0.5;
  while (i < argc) {
    string arg = argv[i];
    if (arg[0] == '-') {
      switch (arg[1]) {
        case 's':
          if (arg == "-size") {
            if (++i < argc) size = static_cast<unsigned>(stoi(argv[i]));
            else {
              cout << "Falta valor para -size" << endl;
              return 1;
            }
          } else {
            cout << "Opción desconocida: " << arg << endl;
            return 1;
          }
          break;
        case 'o':
          if (arg == "-ord") {
            if (++i < argc) fdCode = argv[i];
            else {
              cout << "Falta valor para -ord" << endl;
              return 1;
            }
          } else {
            cout << "Opción desconocida: " << arg << endl;
            return 1;
          }
          break;
        case 'i':
          if (arg == "-init") {
            if (++i < argc) hashTechnique = argv[i];
            if (hashTechnique == "file" && ++i < argc)
              filename = argv[i];
          } else {
            cout << "Opción desconocida: " << arg << endl;
            return 1;
          }
          break;
        case 't':
          if (arg == "-trace") {
            if (++i < argc) trace = (argv[i][0] == 'y');
            else {
              cout << "Falta valor para -trace" << endl;
              return 1;
            }
          } else {
            cout << "Opción desconocida: " << arg << endl;
            return 1;
          }
          break;
        case 'a':
          if (arg == "-alfa") {
            if (++i < argc) alfa = stod(argv[i]);
            else {
              cout << "Falta valor para -alfa" << endl;
              return 1;
            }
          } else {
            cout << "Opción desconocida: " << arg << endl;
            return 1;
          }
          break;
        default:
          cout << "Opción desconocida: " << arg << endl;
          return 1;
      }
    } else {
      cout << "Argumento inesperado: " << arg << endl;
      return 1;
    }
    i++;
  }

	StaticSequence<Nif> seq(size);
  if (hashTechnique == "manual") {
    cout << "Introduce los " << size << " NIFs:\n";
			long input;
			for (unsigned i = 0; i < size; ++i) {
				std::cout << "Introduce el NIF[" << i << "]: ";
				std::cin >> input;
				seq[i] = Nif(input); 
			}
    } else if (hashTechnique == "random") {
      std::srand(std::time(nullptr)); 
      for (unsigned i = 0; i < size; ++i)
        seq[i] = Nif(); 
    } else if (hashTechnique == "file") {
        ifstream file(filename);
        if (!file.is_open()) {
          cerr << "No se pudo abrir el archivo: " << filename << endl;
          return 1;
        }
        long temp;
        for (unsigned i = 0; i < size && file >> temp; ++i) seq[i] = Nif(temp);
    } else {
        cerr << "Inicialización no reconocida\n";
        return 1;
    }

    cout << "Secuencia original:\n";
    for (unsigned i = 0; i < seq.size(); ++i) cout << seq[i] << " ";
    cout << "\n";

    SortMethod<Nif>* sorter = nullptr;
    if (fdCode == "insertion") sorter = new Insertion<Nif>(seq);
    else if (fdCode == "shakesort") sorter = new Sacudida<Nif>(seq);
    else if (fdCode == "quicksort") sorter = new QuickSort<Nif>(seq);
    else if (fdCode == "heapsort") sorter = new HeapSort<Nif>(seq);
    else if (fdCode == "shellsort") sorter = new ShellSort<Nif>(seq, alfa);
    else {
      cout << "Método de ordenación desconocido\n";
      return 1;
    }

    // if (trace) sorter->set_trace(true);

    sorter->Sort();
 
    cout << "Secuencia ordenada:\n";
    for (unsigned i = 0; i < seq.size(); ++i) cout << seq[i] << " ";
    cout << "\n";

    delete sorter;
    return 0;
}
