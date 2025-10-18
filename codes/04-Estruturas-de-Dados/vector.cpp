/**
 * @file vector.cpp
 * @brief Funcionalidades essenciais do std::vector.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    vector<int> v;
    v.push_back(30);
    v.push_back(10);
    v.push_back(20);

    cout << "Vetor: ";
    for (int x : v) cout << x << " "; // Vetor: 30 10 20
    cout << endl;

    // Ordenar
    sort(v.begin(), v.end());
    cout << "Vetor ordenado: "; // Vetor ordenado: 10 20 30
    for (int x : v) cout << x << " ";
    cout << endl;

    // Remover um elemento por valor (ex: 20)
    // "erase-remove idiom"
    v.push_back(20); // adicionando outro 20 para o exemplo
    v.erase(remove(v.begin(), v.end(), 20), v.end());
    cout << "Vetor após remover todos os 20: "; // Vetor após remover todos os 20: 10 30 
    for (int x : v) cout << x << " ";
    cout << endl;

    // Remover um elemento por índice (ex: índice 1)
    v.erase(v.begin() + 1);
    cout << "Vetor após remover o elemento no índice 1: ";
    for (int x : v) cout << x << " "; // Vetor após remover o elemento no índice 1: 10
    cout << endl;

    return 0;
}