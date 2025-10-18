/**
 * @file 01-primos-gemeos.cpp
 * @brief Solução para "Primos Gêmeos".
 *
 * O problema pede para verificar se um número `V` é um "primo gêmeo".
 * Dois números primos `p1` e `p2` são gêmeos se a diferença entre eles é 2.
 * Exemplos: (3, 5), (5, 7), (11, 13).
 *
 * Um número `V` é um primo gêmeo se:
 * 1. `V` for primo.
 * 2. E (`V-2` for primo) OU (`V+2` for primo).
 *
 * A solução requer uma função de teste de primalidade. Para os limites do problema
 * (V até 10^6), uma função O(sqrt(N)) é eficiente o suficiente.
 */
#include <iostream>
#include <cmath>

using namespace std;

// Função para testar a primalidade de um número n.
// Complexidade: O(sqrt(n))
bool isPrime(int n) {
    // 0 e 1 não são primos. Números negativos não são considerados.
    if (n <= 1) return false;
    
    // Itera de 2 até a raiz quadrada de n. Se encontrarmos algum divisor, n não é primo.
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    while (N--) {
      int V;
      cin >> V;
      
      // Um número V é primo gêmeo se ele mesmo for primo E um de seus "vizinhos"
      // (V-2 ou V+2) também for primo.
      if (isPrime(V) && (isPrime(V - 2) || isPrime(V + 2))) {
        cout << "O numero " << V << " eh um primo gemeo" << endl;
      } else {
        cout << "O numero " << V << " nao eh um primo gemeo" << endl;
      }
    }
    return 0;
}