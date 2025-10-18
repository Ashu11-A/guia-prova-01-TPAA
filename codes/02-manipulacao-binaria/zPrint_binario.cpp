/**
 * @file zPrint_binario.cpp
 * @brief Funções para imprimir a representação binária de um número.
 */
#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>

using namespace std;

// Método 1: Usando std::bitset (o mais fácil)
void printBinaryWithBitset(int n) {
  cout << "bitset: " << bitset<32>(n) << endl;
}

// Método 2: Loop manual com deslocamento de bits
void printBinaryManual(int n) {
    cout << "manual: ";
    if (n == 0) {
        cout << "0";
        return;
    }
    string binaryString = "";
    while (n > 0) {
      binaryString += (n % 2 == 0 ? "0" : "1");
      n /= 2;
    }
    reverse(binaryString.begin(), binaryString.end());
    cout << binaryString << endl;
}

int main() {
  int numero = 170; // 10101010
  printBinaryWithBitset(numero); // 00000000000000000000000010101010
  printBinaryManual(numero); // 10101010

  return 0;
}