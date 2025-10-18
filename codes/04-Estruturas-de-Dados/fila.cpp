/**
 * @file fila.cpp
 * @brief Uso da estrutura de dados Fila (Queue) - FIFO (First-In, First-Out).
 */
#include <iostream>
#include <queue>

using namespace std;

int main() {
  queue<int> fila;

  fila.push(10);
  fila.push(20);
  fila.push(30);

  cout << "Tamanho da fila: " << fila.size() << endl; // 3
  cout << "Elemento da frente: " << fila.front() << endl; // 10

  fila.pop(); // Remove o 10

  cout << "Elemento da frente após pop(): " << fila.front() << endl; // 20

  cout << "Esvaziando a fila: ";
  while (!fila.empty()) {
    cout << fila.front() << " "; // 20 30
    fila.pop();
  }
  cout << endl;
  
  return 0;
}