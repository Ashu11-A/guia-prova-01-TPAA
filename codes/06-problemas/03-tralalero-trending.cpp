/**
 * @file 03-tralalero-trending.cpp
 * @brief Solução para "Tralalero Tralatrending".
 *
 * O problema pede o tempo MÍNIMO `t` em que o total de visualizações atinge `X`.
 * A função `total_views(t)` é monotônica crescente (as visualizações só aumentam com o tempo).
 * Isso indica que podemos usar "Busca Binária na Resposta".
 *
 * 1. O que buscamos? O tempo `t`.
 * 2. Qual o intervalo? `esq = 0`, `dir =` um valor muito grande (ex: 10^14).
 * 3. Qual a função `check(t)`? "No tempo `t`, o total de views é >= X?"
 *
 * O `check(t)` calcula, para cada amigo, quantas vezes ele assistiu ao vídeo até o tempo `t`
 * e soma tudo. A fórmula para um amigo é: `(t - t_inicial) / k + 1`.
 *
 * A busca binária então encontra eficientemente o menor `t` para o qual `check(t)` é verdadeiro.
 */
#include <iostream>
#include <vector>

using namespace std;

struct Friend {
  long long t, k;
};

long long N, X;
vector<Friend> friends;

// Função check para a busca binária na resposta.
// Verifica se no tempo `mid` o total de views é pelo menos X.
bool check(long long mid) {
  long long total_views = 0;

  for (int i = 0; i < N; ++i) {
    if (mid >= friends[i].t) {
      total_views += (mid - friends[i].t) / friends[i].k + 1;
    }

    // Se a soma já ultrapassou X, podemos parar para otimizar.
    if (total_views >= X) return true;
  }

  return total_views >= X;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> X;
  friends.resize(N);
  for (int i = 0; i < N; ++i) {
    cin >> friends[i].t >> friends[i].k;
  }

  long long esq = 0, dir = 2e14; // Um limite superior seguro e grande
  long long ans = -1;

  while (esq <= dir) {
    long long mid = esq + (dir - esq) / 2;
    if (check(mid)) {
      // `mid` é um tempo válido. Tentamos um tempo menor.
      ans = mid;
      dir = mid - 1;
    } else {
      // `mid` não é suficiente. Precisamos de mais tempo.
      esq = mid + 1;
    }
  }

  cout << ans << endl;
  return 0;
}