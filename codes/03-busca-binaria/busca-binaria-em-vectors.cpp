/**
 * @brief Uso de funções de busca binária da STL em vetores ordenados.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> v = {2, 5, 8, 8, 10, 15, 29, 30, 50};

  // binary_search: Retorna true se o elemento existe.
  if (binary_search(v.begin(), v.end(), 10)) {
    cout << "10 foi encontrado no vetor." << endl;
  }

  // lower_bound: Primeiro elemento >= valor.
  auto it_lower = lower_bound(v.begin(), v.end(), 8);
  cout << "lower_bound para 8 está na posição " << distance(v.begin(), it_lower) << endl; // lower_bound para 8 está na posição 2

  // upper_bound: Primeiro elemento > valor.
  auto it_upper = upper_bound(v.begin(), v.end(), 8);
  cout << "upper_bound para 8 está na posição " << distance(v.begin(), it_upper) << endl; // upper_bound para 8 está na posição 4

  // Contando ocorrências de um número.
  cout << "O número 8 aparece " << distance(it_lower, it_upper) << " vezes." << endl; // O número 8 aparece 2 vezes.

  // Exemplo: contar quantos são maiores que X.
  int nota_corte = 20;
  auto it = upper_bound(v.begin(), v.end(), nota_corte);
  cout << "Existem " << distance(it, v.end()) << " notas maiores que " << nota_corte << endl; // Existem 3 notas maiores que 20

  return 0;
}