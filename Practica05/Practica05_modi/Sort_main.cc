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
#include "PersonalUll.hpp"

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

	StaticSequence<PersonalUll> seq(size);
if (hashTechnique == "manual") {
    std::cout << "Introduce los " << size << " elementos de PersonalUll:\n";
    for (unsigned i = 0; i < size; ++i) {
        std::string id, nombre, apellido1, apellido2;
        
        std::cout << "\nElemento [" << i << "]:\n";
        std::cout << "  Introduce el ID: ";
        std::cin >> id;
        
        std::cout << "  Introduce el nombre: ";
        std::cin >> nombre;
        
        std::cout << "  Introduce el primer apellido: ";
        std::cin >> apellido1;
        
        std::cout << "  Introduce el segundo apellido: ";
        std::cin >> apellido2;
        
        // Construimos el objeto PersonalUll y lo asignamos a la secuencia
        seq[i] = PersonalUll(id, nombre, apellido1, apellido2);
    }
} else {
        cerr << "Inicialización no reconocida\n";
        return 1;
    }

    cout << "Secuencia original:\n";
    for (unsigned i = 0; i < seq.size(); ++i) cout << seq[i] << " ";
    cout << "\n";

    SortMethod<PersonalUll>* sorter = nullptr;

    if (fdCode == "6") {
      // Hacemos una copia de la secuencia original para restaurarla antes de cada sort.
      StaticSequence<PersonalUll> seq_original = seq;
    
      // Insertion Sort
      {
        StaticSequence<PersonalUll> seq_temp = seq_original;  // copia para ordenar
        SortMethod<PersonalUll>* sorter = new Insertion<PersonalUll>(seq_temp);
        if (trace) sorter->set_trace(true);
        sorter->Sort();
        cout << "\nSecuencia ordenada con Insertion:" << endl;
        for (unsigned i = 0; i < seq_temp.size(); ++i)
          cout << seq_temp[i] << " ";
        cout << "\n";
        Insertion<PersonalUll>* quick_ptr = dynamic_cast<Insertion<PersonalUll>*>(sorter);
        if (quick_ptr != nullptr) {
            cout << "Comparaciones: " << quick_ptr->get_comp() << endl;
            cout << "Intercambios: " << quick_ptr->get_swap() << endl;
        }
        delete sorter;
      }
    
      // Sacudida Sort (Shake Sort)
      {
        StaticSequence<PersonalUll> seq_temp = seq_original;  // restauramos la secuencia original
        SortMethod<PersonalUll>* sorter = new Sacudida<PersonalUll>(seq_temp);
        if (trace) sorter->set_trace(true);
        sorter->Sort();
        cout << "\nSecuencia ordenada con Sacudida:" << endl;
        for (unsigned i = 0; i < seq_temp.size(); ++i)
          cout << seq_temp[i] << " ";
        cout << "\n";
        Sacudida<PersonalUll>* quick_ptr = dynamic_cast<Sacudida<PersonalUll>*>(sorter);
        if (quick_ptr != nullptr) {
            cout << "Comparaciones: " << quick_ptr->get_comp() << endl;
            cout << "Intercambios: " << quick_ptr->get_swap() << endl;
        }
        delete sorter;
      }   
      // QuickSort
      {
        StaticSequence<PersonalUll> seq_temp = seq_original;
        SortMethod<PersonalUll>* sorter = new QuickSort<PersonalUll>(seq_temp);
        if (trace) sorter->set_trace(true);
        sorter->Sort();
        cout << "\nSecuencia ordenada con QuickSort:" << endl;
        for (unsigned i = 0; i < seq_temp.size(); ++i)
          cout << seq_temp[i] << " ";
        cout << "\n";
        QuickSort<PersonalUll>* quick_ptr = dynamic_cast<QuickSort<PersonalUll>*>(sorter);
        if (quick_ptr != nullptr) {
            cout << "Comparaciones: " << quick_ptr->get_comp() << endl;
            cout << "Intercambios: " << quick_ptr->get_swap() << endl;
        }
        delete sorter;
      }   
      // HeapSort
      {
        StaticSequence<PersonalUll> seq_temp = seq_original;
        SortMethod<PersonalUll>* sorter = new HeapSort<PersonalUll>(seq_temp);
        if (trace) sorter->set_trace(true);
        sorter->Sort();
        cout << "\nSecuencia ordenada con HeapSort:" << endl;
        for (unsigned i = 0; i < seq_temp.size(); ++i)
          cout << seq_temp[i] << " ";
        cout << "\n";
        HeapSort<PersonalUll>* quick_ptr = dynamic_cast<HeapSort<PersonalUll>*>(sorter);
        if (quick_ptr != nullptr) {
            cout << "Comparaciones: " << quick_ptr->get_comp() << endl;
            cout << "Intercambios: " << quick_ptr->get_swap() << endl;
        }
        delete sorter;
      }   
      // ShellSort (usando alfa)
      {
        StaticSequence<PersonalUll> seq_temp = seq_original;
        SortMethod<PersonalUll>* sorter = new ShellSort<PersonalUll>(seq_temp, alfa);
        if (trace) sorter->set_trace(true);
        sorter->Sort();
        cout << "\nSecuencia ordenada con ShellSort:" << endl;
        for (unsigned i = 0; i < seq_temp.size(); ++i)
          cout << seq_temp[i] << " ";
        cout << "\n";
        ShellSort<PersonalUll>* quick_ptr = dynamic_cast<ShellSort<PersonalUll>*>(sorter);
        if (quick_ptr != nullptr) {
            cout << "Comparaciones: " << quick_ptr->get_comp() << endl;
            cout << "Intercambios: " << quick_ptr->get_swap() << endl;
        }
        delete sorter;
      }   
      // Al terminar la opción "6", salimos para no ejecutar el resto del código
      return 0;
    } else {
      // Resto de la lógica: crea sorter según fdCode y ordena la secuencia.
      if (fdCode == "insertion") 
        sorter = new Insertion<PersonalUll>(seq);
      else if (fdCode == "shakesort") 
        sorter = new Sacudida<PersonalUll>(seq);
      else if (fdCode == "quicksort") 
        sorter = new QuickSort<PersonalUll>(seq);
      else if (fdCode == "heapsort") 
        sorter = new HeapSort<PersonalUll>(seq);
      else if (fdCode == "shellsort") 
        sorter = new ShellSort<PersonalUll>(seq, alfa);
      else {
        cout << "Método de ordenación desconocido\n";
        return 1;
      }     
      if (trace) sorter->set_trace(true);
      sorter->Sort();  
      cout << "\nSecuencia ordenada:\n";
      for (unsigned i = 0; i < seq.size(); ++i)
        cout << seq[i] << " ";
      cout << "\n";  
      delete sorter;
    }
    return 0;
}
