/*
      __builtin_ctz(x)        // Numero de zeros a direita
      __builtin_clz(x)        // Numero de zeros a esquerda
      __builtin_popcount(x)   // Numero de bits 1 __builtin_popcountll(x) para long long x
      __builtin_ffs(x)        // Posicao do primeiro bit 1 (1-indexed)

      // Adicionar ll ao final para long long [__builtin_clzll(x)]
*/

/**
 * @brief Funções `__builtin` do GCC/Clang para operações de bits otimizadas.
 */
#include <iostream>

using namespace std;

int main() {
  int x = 29; // 00011101

  // __builtin_popcount(x): Conta o número de bits '1'.
  cout << "Número de bits '1' em " << x << ": " << __builtin_popcount(x) << endl; // 4

  // __builtin_clz(x): Conta zeros à esquerda.
  if (x != 0) {
      cout << "Zeros à esquerda em " << x << ": " << __builtin_clz(x) << endl; // 27 -> 32 bits (0x27)11101
  }

  // __builtin_ctz(x): Conta zeros à direita.
  if (x != 0) {
      cout << "Zeros à direita em " << x << ": " << __builtin_ctz(x) << endl; // 0
  }

  // __builtin_ffs(x): Índice do primeiro bit '1' (1-indexed).
  cout << "Índice do primeiro bit '1' em " << x << ": " << __builtin_ffs(x) << endl; // 1

  long long y = 1LL << 60; // ativa o bit 60
  cout << "\nPara long long y = 2^60:" << endl;
  cout << "Popcount de y: " << __builtin_popcountll(y) << endl; // 1
  cout << "Leading zeros de y: " << __builtin_clzll(y) << endl; // 3, já que é 64 bits 0001000...
  cout << "Trailing zeros de y: " << __builtin_ctzll(y) << endl; // 60
  
  return 0;
}