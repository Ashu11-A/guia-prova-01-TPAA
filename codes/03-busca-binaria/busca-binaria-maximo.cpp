/**
 * @file busca-binaria-maximo.cpp
 * @brief Template para busca binária pelo maior valor que satisfaz uma condição.
 *
 * A chave é entender a propriedade da função de busca (monotônica).
 * Aqui, procuramos o último valor 'V' em um domínio que se parece com:
 * [V, V, V, ..., V, F, F, ..., F]
 * onde 'V' significa que a condição é verdadeira e 'F' que é falsa.
 */
#include <iostream>

using namespace std;

// Condição de exemplo: o número é válido se for <= 42.
bool check(int x) {
  return x <= 42;
}

int main() {
  int esq = 0, dir = 100;
  int ans = -1; // Armazena a melhor resposta válida encontrada até agora.

  while (esq <= dir) {
    // `mid = esq + (dir - esq) / 2;`
    // Esta forma de calcular o `mid` previne um possível overflow de inteiros
    // que poderia ocorrer com `(esq + dir) / 2` se `esq` e `dir` forem muito grandes.
    int mid = esq + (dir - esq) / 2;

    if (check(mid)) {
      // Se `mid` é uma resposta válida, a salvamos.
      ans = mid;
      // E tentamos encontrar uma resposta ainda melhor (maior) à direita.
      esq = mid + 1;
    } else {
      // Se `mid` não é uma resposta válida, a resposta (se existir)
      // deve estar à esquerda.
      dir = mid - 1;
    }
  }

  cout << "O maior valor que satisfaz a condição é: " << ans << endl;
  return 0;
}