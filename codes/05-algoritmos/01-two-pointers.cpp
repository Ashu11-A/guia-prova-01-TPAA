/**
 * @file 01-two-pointers.cpp
 * @brief Implementação da técnica Two Pointers (Dois Ponteiros).
 *
 * Usada em vetores ORDENADOS para encontrar pares de elementos que satisfazem
 * uma condição, geralmente em tempo linear O(N).
 *
 * Exemplo clássico: Encontrar um par de números que somam um valor S.
 * (Problema "Soma Igual")
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> v = {1, 3, 4, 6, 8, 9, 11};
  int S = 14;

  int esq = 0;
  int dir = v.size() - 1;
  bool encontrado = false;

  while (esq < dir) {
    int soma_atual = v[esq] + v[dir];

    if (soma_atual == S) {
      cout << "Par encontrado: " << v[esq] << " + " << v[dir] << " = " << S << endl;
      encontrado = true;
      break; // Se só precisar de um par, pode parar aqui.
    } else if (soma_atual < S) {
      // A soma é muito pequena. Precisamos aumentá-la.
      // Movemos o ponteiro da esquerda para a direita para pegar um número maior.
      esq++;
    } else { // soma_atual > S
      // A soma é muito grande. Precisamos diminuí-la.
      // Movemos o ponteiro da direita para a esquerda para pegar um número menor.
      dir--;
    }
  }

  if (!encontrado) {
    cout << "Nenhum par encontrado com a soma " << S << endl;
  }

  return 0;
}