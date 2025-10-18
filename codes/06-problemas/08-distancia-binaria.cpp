/**
 * @file 08-distancia-binaria.cpp
 * @brief Solução para "A. Distância Binária".
 *
 * O problema pede a Distância de Hamming entre dois números, que é o número
 * de posições de bits em que eles diferem.
 *
 * A solução explora uma propriedade elegante do operador XOR (`^`).
 * 1. A operação `X ^ Y` resulta em um novo número. Este número terá um bit '1'
 *    em cada posição onde os bits de `X` e `Y` eram diferentes, e '0' onde
 *    eram iguais.
 *    Ex: X = 1010, Y = 1100 -> X^Y = 0110. Os bits diferem nas posições 1 e 2.
 * 2. O problema, então, se resume a contar quantos bits '1' existem no resultado
 *    de `X ^ Y`.
 * 3. Novamente, `__builtin_popcountll()` é a ferramenta perfeita e mais eficiente
 *    para essa contagem.
 */
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    unsigned long long X, Y;
    cin >> X >> Y;

    // 1. Encontra as posições onde os bits diferem usando XOR.
    unsigned long long diferenca_bits = X ^ Y;

    // 2. Conta quantos bits '1' existem no resultado. O resultado é a distância.
    int distancia = __builtin_popcountll(diferenca_bits);

    cout << distancia << "\n";
  }

  return 0;
}