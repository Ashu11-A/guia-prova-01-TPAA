/**
 * @file 09-maiores-notas.cpp
 * @brief Solução para "E. Maiores Notas".
 *
 * O problema pede para, dado um vetor ORDENADO de notas e várias notas de corte,
 * encontrar para cada corte quantas notas são ESTRITAMENTE maiores.
 *
 * Esta é uma aplicação direta de busca binária. A função `std::upper_bound`
 * da biblioteca `<algorithm>` é a ferramenta ideal.
 *
 * - `upper_bound(inicio, fim, valor)`: Retorna um iterador para o primeiro
 *   elemento no intervalo que é *maior* que `valor`.
 *
 * Uma vez que temos o iterador para o primeiro elemento maior que a nota de corte,
 * todos os elementos a partir daquele ponto até o final do vetor também serão maiores
 * (pois o vetor está ordenado). A quantidade de tais elementos é a distância
 * entre esse iterador e o final do vetor.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int A, Q;
  cin >> A >> Q;

  vector<int> notas(A);
  for (int i = 0; i < A; ++i) {
    cin >> notas[i];
  }

  while (Q--) {
    int nota_corte;
    cin >> nota_corte;

    // Encontra o primeiro elemento estritamente maior que a nota_corte.
    // Complexidade: O(log A)
    auto it = upper_bound(notas.begin(), notas.end(), nota_corte);

    // A quantidade de notas maiores é a distância do iterador até o fim.
    int count = distance(it, notas.end());

    cout << count << " notas maiores que " << nota_corte << endl;
  }
  return 0;
}