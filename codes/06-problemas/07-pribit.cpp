/**
 * @file 7-pribit.cpp
 * @brief Solução para "E. Pribit".
 *
 * O problema define "pribit" como um número cuja representação binária
 * possui uma quantidade prima de bits com valor '1'.
 *
 * A solução consiste em duas etapas:
 * 1. Contar o número de bits '1' (set bits) no número `V`. A função intrínseca
 *    do GCC/Clang `__builtin_popcountll(V)` é a forma mais eficiente de fazer isso
 *    para um `long long`, pois é traduzida para uma única instrução de máquina.
 * 2. Verificar se a contagem de bits é um número primo. Como o número de bits em um
 *    `long long` é no máximo 64, precisamos apenas de uma função `isPrime` que
 *    funcione para números pequenos.
 */
#include <iostream>

using namespace std;

// Função para testar primalidade, eficiente para números pequenos.
bool isPrime(int n) {
  if (n <= 1) return false; // 0 e 1 não são primos.
  if (n <= 3) return true;  // 2 e 3 são primos.
  if (n % 2 == 0 || n % 3 == 0) return false; // Divisíveis por 2 ou 3.

  // A partir de 5, todos os primos são da forma 6k ± 1.
  for (int i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  while (N--) {
    long long V;
    cin >> V;

    // 1. Conta os bits '1' de forma super otimizada.
    int bit_count = __builtin_popcountll(V);

    // 2. Verifica se a contagem é um número primo.
    if (isPrime(bit_count)) {
      cout << V << " eh um pribit\n";
    } else {
      cout << V << " nao eh um pribit\n";
    }
  }
  return 0;
}