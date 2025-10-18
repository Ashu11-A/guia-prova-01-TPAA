/**
 * @file 06-super-bit-ativar.cpp
 * @brief Solução para "D. Super Bit, Ativar!".
 *
 * O problema pede para "reativar" um bit, ou seja, garantir que ele seja '1',
 * independentemente do seu valor original.
 *
 * A operação bitwise OR (`|`) é perfeita para isso. A expressão `V | (1 << B)`
 * cria uma máscara onde apenas o bit na posição `B` é 1.
 * - Se o bit `B` em `V` já for 1, `1 | 1` resulta em 1 (sem alteração).
 * - Se o bit `B` em `V` for 0, `0 | 1` resulta em 1 (o bit é ativado).
 * - Todos os outros bits de `V` são comparados com 0 na máscara, então
 *   `X | 0` resulta em `X`, mantendo seus valores originais.
 */
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, B;
  cin >> N >> B;

  // Cria a máscara uma única vez, já que B é constante para todas as operações.
  // A máscara terá apenas o B-ésimo bit ligado.
  int mascara = (1 << B);

  while (N--) {
    int V;
    cin >> V;

    // A operação OR com a máscara garante que o B-ésimo bit seja ativado.
    int resultado = V | mascara;
    cout << resultado << "\n";
  }

  return 0;
}