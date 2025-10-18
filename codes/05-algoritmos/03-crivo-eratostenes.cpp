/**
 * @file crivo-eratostenes.cpp
 * @brief Implementação do Crivo de Eratóstenes.
 *
 * Utilizado para gerar todos os números primos até um limite N de forma muito eficiente.
 * A complexidade é O(N log log N), que é quase linear.
 * Essencial para problemas que exigem múltiplas verificações de primalidade
 * dentro de um intervalo fixo, como nos problemas "É primo ou não é" ou "Primos Gêmeos".
 */
#include <iostream>
#include <vector>

using namespace std;

// Gera um vector<bool> onde isPrime[i] é true se i for primo.
vector<bool> sieve(int N) {
  vector<bool> isPrime(N + 1, true);
  isPrime[0] = isPrime[1] = false;

  for (int p = 2; p * p <= N; ++p) {
    if (isPrime[p]) {
      // Marca todos os múltiplos de p, começando por p*p, como não-primos.
      // Começamos de p*p porque os múltiplos menores (p*2, p*3, ...)
      // já terão sido marcados por primos menores que p.
      for (int i = p * p; i <= N; i += p) {
        isPrime[i] = false;
      }
    }
  }
  return isPrime;
}

int main() {
  const int MAX_LIMIT = 1000000;
  vector<bool> primes = sieve(MAX_LIMIT);

  cout << "Verificando primalidade com o crivo pré-calculado:" << endl;
  
  int num1 = 999983; // É primo
  cout << num1 << (primes[num1] ? " eh primo" : " nao eh primo") << endl;

  int num2 = 1000000; // Não é primo
  cout << num2 << (primes[num2] ? " eh primo" : " nao eh primo") << endl;

  return 0;
}