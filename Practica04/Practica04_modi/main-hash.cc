#include <iostream>
#include <cstring>  
#include <cstdlib>   

#include "HashTable.tpp"  
#include "StaticSequence.tpp"  
#include "DynamicSequence.tpp"  
#include "DispersionFunction.tpp"
#include "DispersionFunctionSum.tpp"
#include "DispersionFunctionModule.tpp"
#include "DispersionFunctionPseudorandom.tpp"
#include "ExplorationFunctionKey.tpp"
#include "ExplorationFunctionKeyLineal.tpp"
#include "ExplorationFunctionKeyCuadratic.tpp"
#include "ExplorationFunctionKeyRedispertion.tpp"
#include "ExplorationFunctionKeyDobleDispertion.tpp"
#include "Nif.hpp"
#include "PersonalUll.hpp"

using namespace std;

/**
 * @brief Muestra el menú de opciones.
 * @return void
 */
void showMenu() {
	cout << "\n--- Menú de Tabla Hash ---\n";
	cout << "1. Insertar NIF\n";
	cout << "2. Buscar NIF\n";
	cout << "3. Salir\n";
	cout << "Seleccione una opción: ";
}

int main(int argc, char *argv[]) {
	unsigned tableSize = 0, blockSize = 0;
	string fdCode, feCode, hashTechnique;
	int i = 1;

	while (i < argc) {
		string arg = argv[i];
		if (arg[0] == '-') {
			switch(arg[1]) {
				case 't':
					if (arg == "-ts") {
						if (++i < argc) tableSize = static_cast<unsigned>(stoi(argv[i]));
						else {
							cout << "Falta valor para -ts" << endl;
							return 1;
						}
					} else {
						cout << "Opción desconocida: " << arg << endl;
						return 1;
					}
					break;
				case 'f': 
					if (arg == "-fd") {
						if (++i < argc) fdCode = argv[i];
						else {
							cout << "Falta valor para -fd" << endl;
							return 1;
						}
					} else if (arg == "-fe") {
						if (++i < argc) feCode = argv[i];
						else {
							cout << "Falta valor para -fe" << endl;
							return 1;
						}
					} else {
						cout << "Opción desconocida: " << arg << endl;
						return 1;
					}
					break;
				case 'h': 
					if (arg == "-hash") {
						if (++i < argc) hashTechnique = argv[i];
						else {
							cout << "Falta valor para -hash" << endl;
							return 1;
						}
					} else {
						cout << "Opción desconocida: " << arg << endl;
						return 1;
					}
					break;
				case 'b': 
					if (arg == "-bs") {
						if (++i < argc) blockSize = static_cast<unsigned>(stoi(argv[i]));
						else {
							cout << "Falta valor para -bs" << endl;
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

	if (tableSize == 0 || fdCode.empty() || hashTechnique.empty()) {
		cout << "Uso: " << argv[0] << " -ts <tableSize> -fd <fdCode> -hash <open|close> [ -bs <blockSize> -fe <feCode> ]" << endl;
		return 1;
	}
	if (hashTechnique == "close") {
		if (blockSize == 0 || feCode.empty()) {
			cout << "Para dispersión cerrada se requieren -bs y -fe." << endl;
			return 1;
		}
	}

	DispersionFunction<PersonalUll>* dispersionFunction = nullptr;
	if (fdCode == "mod") {
		dispersionFunction = new DispersionFunctionModule<PersonalUll>(tableSize);
	} else if (fdCode == "sum") {
		dispersionFunction = new DispersionFunctionSum<PersonalUll>(tableSize);
	} else if (fdCode == "random") {
		dispersionFunction = new DispersionFunctionPseudorandom<PersonalUll>(tableSize);
	} else {
		cout << "Error: Código de función de dispersión no reconocido." << endl;
		return 1;
	}

  Sequence<PersonalUll>* hashTable = nullptr;
  if (hashTechnique == "close") {
    ExplorationFuction<PersonalUll>* explorationFunction = nullptr;
    if (feCode == "lineal") {
      explorationFunction = new ExplorationFunctionKeyLineal<PersonalUll>();
    } else if (feCode == "cuadratica") {
      explorationFunction = new ExplorationFunctionKeyCuadratic<PersonalUll>();
    } else if (feCode == "doble") {
      explorationFunction = new ExplorationFunctionKeyDobleDispertion<PersonalUll>(dispersionFunction);
    } else if (feCode == "redispersion") {
      explorationFunction = new ExplorationFunctionKeyRedispertion<PersonalUll>(dispersionFunction, tableSize);
    } else {
      cout << "Error: Código de función de exploración no reconocido." << endl;
      return 1;
    }
    hashTable = new HashTable<PersonalUll, StaticSequence<PersonalUll>>(tableSize, *dispersionFunction, *explorationFunction, blockSize);
  } else {
    hashTable = new HashTable<PersonalUll, DynamicSequence<PersonalUll>>(tableSize, *dispersionFunction);
  }

  int opcion;
	do {
    showMenu();
    cin >> opcion;
    switch (opcion) {
      case 1: { 
				string numero, nombre, apellido1, apellido2;
				cout << "Ingrese el id del personal: ";
				cin >> numero;
				cout << "Ingrese el nombre del personal: ";
				cin >> nombre;
				cout << "Ingrese el apellido1 del personal: ";
				cin >> apellido1;
				cout << "Ingrese el apellido2 del personal: ";
				cin >> apellido2;
				PersonalUll nif(numero, nombre, apellido1, apellido2);
				if (hashTable->insert(nif)) {
					cout << "NIF insertado correctamente.\n";
				} else {
					cout << "Error: NIF ya existe o la tabla está llena.\n";
				}
				break;
      }
      case 2: { 
				string numero, nombre, apellido1, apellido2;
				cout << "Ingrese el id del personal: ";
				cin >> numero;
				cout << "Ingrese el nombre del personal: ";
				cin >> nombre;
				cout << "Ingrese el apellido1 del personal: ";
				cin >> apellido1;
				cout << "Ingrese el apellido2 del personal: ";
				cin >> apellido2;
				PersonalUll nif(numero, nombre, apellido1, apellido2);
        if (hashTable->search(nif)) {
          cout << "NIF encontrado en la tabla.\n";
        } else {
          cout << "NIF no encontrado.\n";
        }
        break;
      }
      case 3:
        cout << "Saliendo del programa...\n";
        break;
      default:
        cout << "Opción no válida. Intente de nuevo.\n";
				break;
    }
	} while (opcion != 3);
  return 0;
}
