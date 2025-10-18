/**
 * @file 10-funcao.cpp
 * @brief Solução para "D. Função".
 *
 * O problema pede para encontrar a raiz da equação `A*x + B*cos(x) = C`,
 * o que é o mesmo que encontrar `x` tal que `f(x) = A*x + B*cos(x) - C = 0`.
 *
 * A função `f(x)` é estritamente crescente para os limites dados (`A > B >= 0`).
 * Isso nos garante que há uma única raiz e que podemos usar Busca Binária (ou
 * Método da Bisseção) para encontrá-la.
 *
 * 1. Definimos um intervalo de busca `[low, high]`.
 * 2. Calculamos `mid = (low + high) / 2`.
 * 3. Avaliamos o sinal de `f(mid)`:
 *    - Se `f(mid) > 0`, significa que `mid` é maior que a raiz. A raiz deve
 *      estar no intervalo `[low, mid]`. Então, `high = mid`.
 *    - Se `f(mid) < 0`, `mid` é menor que a raiz. A raiz deve estar em
 *      `[mid, high]`. Então, `low = mid`.
 * 4. Repetimos o processo um número fixo de vezes (e.g., 100) para garantir
 *    alta precisão, mais do que suficiente para as 4 casas decimais exigidas.
 */
#include <iostream>
#include <cmath>
#include <iomanip> // Para setprecision

using namespace std;

double A, B, C;

// A função cuja raiz queremos encontrar: f(x) = A*x + B*cos(x) - C
double f(double x) {
  return A * x + B * cos(x) - C;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> A >> B >> C;

  double low = 0.0, high = 200000.0;

  // 100 iterações são mais que suficientes para a precisão de double.
  for (int i = 0; i < 100; ++i) {
    double mid = low + (high - low) / 2.0;
    if (f(mid) > 0) {
      high = mid; // A raiz está na metade inferior
    } else {
      low = mid;  // A raiz está na metade superior
    }
  }
  
  // Imprime o resultado com a formatação exigida.
  cout << fixed << setprecision(4) << high << endl;

  return 0;
}