#include <iostream>
#include "ShellSort.tpp"  // Asegúrate de que esto esté bien incluido

int main() {
  StaticSequence<int> seq(5);
  seq[0] = 42;
  seq[1] = 7;
  seq[2] = 23;
  seq[3] = 15;
  seq[4] = 3;

  std::cout << "Secuencia original:\n";
  for (unsigned i = 0; i < seq.size(); ++i)
    std::cout << seq[i] << " ";
  std::cout << "\n";

  ShellSort<int> sorter(seq, 0.6);  // Aquí decides el valor de α
  sorter.Sort();

  std::cout << "Secuencia ordenada:\n";
  for (unsigned i = 0; i < seq.size(); ++i)
    std::cout << seq[i] << " ";
  std::cout << "\n";

  return 0;
}
