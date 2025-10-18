/**
 * @file 00-numero-faltante.cpp
 * @brief Duas técnicas para encontrar um número faltante em uma sequência de 1 a N.
 *
 * Este é um problema clássico com soluções elegantes e eficientes.
 */
#include <iostream>
#include <vector>
#include <numeric> // Para std::accumulate

using namespace std;

int main() {
  long long N = 10;
  vector<long long> v = {3, 8, 2, 4, 1, 10, 6, 7, 9}; // O 5 está faltando

  // --- Técnica 1: Soma por Progressão Aritmética ---
  // A soma de todos os números de 1 a N é dada pela fórmula da PA: N * (N + 1) / 2.
  // Se somarmos os números que temos e subtrairmos da soma total esperada,
  // o resultado será exatamente o número que falta.
  // Complexidade: O(N) para somar, mas muito eficiente.
  
  long long soma_total_esperada = N * (N + 1) / 2;
  long long soma_atual = 0;
  for(long long x : v) {
    soma_atual += x;
  }
  // A função accumulate faz a mesma coisa:
  // long long soma_atual_accumulate = accumulate(v.begin(), v.end(), 0LL);
  
  cout << "Método da PA: O número faltante é " << soma_total_esperada - soma_atual << endl;


  // --- Técnica 2: Operador XOR ---
  // A propriedade A ^ A = 0 e A ^ 0 = A é a chave aqui.
  // Se fizermos o XOR de todos os números de 1 a N, e depois fizermos o XOR
  // desse resultado com todos os números presentes no vetor, os números que
  // aparecem duas vezes se anularão (A ^ A), e o único que sobrará será
  // o número faltante.
  // Complexidade: O(N), geralmente mais rápido que a soma e não corre risco de overflow.
  
  long long xor_total = 0;
  for (long long i = 1; i <= N; ++i) {
    xor_total ^= i;
  }

  long long xor_vetor = 0;
  for (long long x : v) {
    xor_vetor ^= x;
  }

  cout << "Método do XOR: O número faltante é " << (xor_total ^ xor_vetor) << endl;

  return 0;
}