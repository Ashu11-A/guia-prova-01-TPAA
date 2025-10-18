/**
 * @file 02-sliding-window.cpp
 * @brief Implementação da técnica Sliding Window (Janela Deslizante).
 *
 * Usada para processar subarrays/substrings de um tamanho fixo ou variável
 * de forma eficiente, geralmente em tempo linear O(N).
 *
 * Exemplo: Encontrar a soma máxima de um subarray de tamanho K.
 * (Similar em conceito ao problema "Telemarketing")
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v = {1, 4, 2, 10, 2, 3, 1, 0, 20};
  int K = 3; // Tamanho da janela

  if (v.size() < K) {
      cout << "Vetor menor que o tamanho da janela." << endl;
      return 0;
  }

  // 1. Calcula a soma da primeira janela
  int soma_atual = 0;
  for (int i = 0; i < K; ++i) {
    soma_atual += v[i];
  }
  int soma_maxima = soma_atual;

  // 2. Desliza a janela pelo resto do vetor
  for (int i = K; i < v.size(); ++i) {
    // Para "deslizar" a janela, adicionamos o novo elemento que entra (v[i])
    // e subtraímos o elemento que sai (v[i-K]).
    soma_atual += v[i] - v[i - K];
    
    // Atualiza a soma máxima encontrada
    if (soma_atual > soma_maxima) {
      soma_maxima = soma_atual;
    }
  }

  cout << "A soma máxima de um subarray de tamanho " << K << " é: " << soma_maxima << endl;

  return 0;
}