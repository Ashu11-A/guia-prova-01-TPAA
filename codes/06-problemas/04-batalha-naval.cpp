/**
 * @file 04-batalha-naval.cpp
 * @brief Solução para "Batalha Naval Numérica".
 *
 * O problema pede para encontrar a primeira ocorrência de um número `V`
 * em uma matriz onde as linhas e colunas estão ordenadas crescentemente.
 *
 * Uma solução eficiente é iterar por cada linha e, como cada linha está
 * ordenada, usar busca binária (`lower_bound`) para encontrar o número.
 *
 * - `lower_bound` retorna um iterador para o primeiro elemento que não é menor que `V` (>= V).
 * - Se o iterador não for o fim da linha e o valor que ele aponta for `V`,
 *   então encontramos o número.
 * - Como queremos a *primeira* ocorrência, assim que encontrarmos, podemos parar a busca.
 * - A coluna é calculada pela distância do início da linha até o iterador.
 *
 * O uso de uma função `lambda` é comum com algoritmos da STL, mas para um
 * `vector<int>`, a versão padrão de `lower_bound` funciona perfeitamente.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, Q;
  cin >> N >> M >> Q;

  vector<vector<int>> grid(N, vector<int>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> grid[i][j];
    }
  }

  while (Q--) {
    int V;
    cin >> V;

    int row = -1, col = -1;
    bool found = false;

    // Itera por cada linha da grade
    for (int i = 0; i < N; ++i) {
      // Usa lower_bound para fazer busca binária na linha atual
      auto it = lower_bound(grid[i].begin(), grid[i].end(), V);

      // Verifica se o valor foi realmente encontrado
      if (it != grid[i].end() && *it == V) {
        row = i;
        col = distance(grid[i].begin(), it); // Calcula a coluna
        found = true;
        break; // Encontrou a primeira ocorrência, pode parar
      }
    }

    if (found) {
      cout << row << " " << col << endl;
    } else {
      cout << -1 << " " << -1 << endl;
    }
  }

  return 0;
}