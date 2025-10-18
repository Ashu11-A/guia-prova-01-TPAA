/**
 * @brief Funções para verificar, ligar, desligar e inverter bits.
 */
#include <iostream>
#include <bitset>

using namespace std;

// Verifica se o k-ésimo bit de 'n' está ligado (é 1).
// Usa o operador AND. Se o resultado for não-zero, o bit estava ligado.
bool isSet(int n, int k) {
  return (n & (1 << k)) != 0;
}

// Liga (seta para 1) o k-ésimo bit de 'n'.
// Usa o operador OR. O OR com 1 sempre resulta em 1, sem afetar outros bits.
int setBit(int n, int k) {
  return n | (1 << k);
}

// Desliga (seta para 0) o k-ésimo bit de 'n'.
// Cria uma máscara com todos os bits 1, exceto o k-ésimo (ex: 11110111).
// O AND com essa máscara zera o k-ésimo bit e mantém os outros.
int clearBit(int n, int k) {
  return n & (~(1 << k));
}

// Inverte (flipa) o k-ésimo bit de 'n' (0 vira 1, 1 vira 0).
// Usa o operador XOR. XOR com 1 inverte o bit, XOR com 0 mantém o bit.
int toggleBit(int n, int k) {
    return n ^ (1 << k);
}

int main() {
  int numero = 46; // 00101110
  int bit_pos = 3;

  // Número original: 46 (00101110)
  cout << "Número original: " << numero << " (" << bitset<8>(numero) << ")" << endl;

  // O bit 3 está ligado.
  if (isSet(numero, bit_pos)) {
    cout << "O bit " << bit_pos << " está ligado." << endl;
  } else {
    cout << "O bit " << bit_pos << " está desligado." << endl;
  }

    // Ligando Bit (6)
    // n: 00101110
    //  : 01101110
  int numero_com_bit_ligado = setBit(numero, 6);
  cout << "Ligando o bit 6: " << numero_com_bit_ligado << " (" << bitset<8>(numero_com_bit_ligado) << ")" << endl; // Ligando o bit 6: 110 (01101110)

    // Desligando Bit (3)
    // n: 00101110
    //  : 00100110
  int numero_com_bit_desligado = clearBit(numero, 3);
  cout << "Desligando o bit 3: " << numero_com_bit_desligado << " (" << bitset<8>(numero_com_bit_desligado) << ")" << endl; // Desligando o bit 3: 38 (00100110)
  
    // Invertendo Bit (1)
    // n: 00101110
    //  : 00101100
  int numero_com_bit_invertido = toggleBit(numero, 1);
  cout << "Invertendo o bit 1: " << numero_com_bit_invertido << " (" << bitset<8>(numero_com_bit_invertido) << ")" << endl; // Invertendo o bit 1: 44 (00101100)

  return 0;
}