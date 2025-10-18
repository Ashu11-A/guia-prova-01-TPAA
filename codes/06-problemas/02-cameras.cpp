/**
 * @file 02-cameras.cpp
 * @brief Solução para "Câmeras".
 *
 * O problema pede para comprimir a lista de presença de até 64 alunos em um
 * único número inteiro.
 *
 * Esta é uma aplicação direta de máscaras de bits (bitmasking).
 * - Usamos um inteiro de 64 bits (`unsigned long long`) como uma "máscara".
 * - Cada bit, da posição 0 à 63, representa um aluno.
 * - Se o aluno `i` está presente, o `i`-ésimo bit da máscara é ligado (setado para 1).
 *
 * A operação para ligar um bit `i` sem afetar os outros é o OR bitwise:
 * `mascara = mascara | (1ULL << i);`
 * O `1ULL` garante que a operação seja feita com um `unsigned long long` de 64 bits.
 */
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int N;
  cin >> N;
  
  unsigned long long mascara_presenca = 0;

  for (int i = 0; i < N; ++i) {
    int indice_aluno;
    cin >> indice_aluno;
    
    // Liga o bit correspondente ao índice do aluno.
    mascara_presenca = mascara_presenca | (1ULL << indice_aluno);
  }

  cout << mascara_presenca << "\n";

  return 0;
}