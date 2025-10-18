/**
 * @file 05-navegador.cpp
 * @brief Solução para "Navegador".
 *
 * O problema pede para simular um histórico de navegador com duas operações:
 * 1. Visitar um novo site.
 * 2. Voltar (`<`).
 *
 * A estrutura de dados `std::stack` (pilha) é perfeita para modelar esse
 * comportamento LIFO (Last-In, First-Out).
 * - Quando um site é visitado, ele é "empilhado" (`push`) no topo do histórico.
 * - Quando a ação de voltar é executada, o site atual é "desempilhado" (`pop`),
 *   revelando o site anterior, que agora está no topo.
 *
 * É preciso cuidar do caso em que a pilha está vazia (não há mais histórico para voltar).
 */
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  
  stack<string> historico;

  for (int i = 0; i < N; ++i) {
    string acao;
    cin >> acao;

    if (acao == "<") {
      // Ação de voltar
      if (!historico.empty()) {
        historico.pop();
      }

      if (historico.empty()) {
        cout << "pagina em branco" << endl;
      } else {
        cout << historico.top() << endl;
      }
    } else {
      // Visitar um novo site
      historico.push(acao);
      cout << historico.top() << endl;
    }
  }

  return 0;
}