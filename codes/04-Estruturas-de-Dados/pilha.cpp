/**
 * @file pilha.cpp
 * @brief Uso da estrutura de dados Pilha (Stack) - LIFO (Last-In, First-Out).
 */
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<string> pilha;

    pilha.push("site1.com");
    pilha.push("site2.com");
    pilha.push("site3.com");

    cout << "Tamanho da pilha: " << pilha.size() << endl; // 3
    cout << "Elemento no topo: " << pilha.top() << endl; // site3.com

    pilha.pop(); // Remove "site3.com"

    cout << "Elemento no topo após pop(): " << pilha.top() << endl; // site2.com

    cout << "Esvaziando a pilha: ";
    while (!pilha.empty()) {
        cout << pilha.top() << " "; // site2.com site1.com
        pilha.pop();
    }
    cout << endl;

    return 0;
}