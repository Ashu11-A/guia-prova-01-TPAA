/**
 * @file busca-binaria-minimo.cpp
 * @brief Template para busca binária pelo menor valor que satisfaz uma condição.
 *
 * Similar à busca pelo máximo, mas para um domínio que se parece com:
 * [F, F, F, ..., F, V, V, ..., V]
 * O objetivo é encontrar o primeiro valor 'V'.
 */
#include <iostream>

using namespace std;

// Condição de exemplo: o número é válido se for >= 42.
bool check(int x) {
    return x >= 42;
}

int main() {
  int esq = 0, dir = 100;
  int ans = -1;

  while (esq <= dir) {
    // Cálculo do `mid` que evita overflow.
    int mid = esq + (dir - esq) / 2;

    if (check(mid)) {
      // Se `mid` é uma resposta válida, a salvamos.
      ans = mid;
      // E tentamos encontrar uma resposta ainda melhor (menor) à esquerda.
      dir = mid - 1;
    } else {
      // Se `mid` não é uma resposta válida, a resposta (se existir)
      // deve estar à direita.
      esq = mid + 1;
    }
  }

  cout << "O menor valor que satisfaz a condição é: " << ans << endl;
  return 0;
}