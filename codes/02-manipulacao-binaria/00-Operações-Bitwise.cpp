/*Operaçãoes bit a bit:
        ~x op binária complementar
        x & y op E bit a bit entre x e y
        x | y op OU bit a bit entre x e y
        x ^ y op XOR bit a bit entre x e y
        x << int op SHIFT LEFT de i posições
        x >> int op SHIFT RIGHT de i posições
*/

/**
 * @brief Visão geral dos operadores bitwise em C++.
 */
#include <iostream>
#include <bitset>

using namespace std;

int main() {
    // a = 11001100 (204)
    unsigned char a = 0b11001100;
    // b = 10101010 (170)
    unsigned char b = 0b10101010;

    cout << "a = " << bitset<8>(a) << " (" << (int)a << ")" << endl;
    cout << "b = " << bitset<8>(b) << " (" << (int)b << ")" << endl;
    cout << "----------------------------------" << endl;

    // AND (&)
    // a: 11001100
    // b: 10101010
    //  : 10001000
    unsigned char res_and = a & b; // 136
    cout << "a & b = " << bitset<8>(res_and) << " (" << (int)res_and << ")" << endl;

    // OR (|)
    // a: 11001100
    // b: 10101010
    //  : 11101110
    unsigned char res_or = a | b; // 238
    cout << "a | b = " << bitset<8>(res_or) << " (" << (int)res_or << ")" << endl;

    // XOR (^)
    // a: 11001100
    // b: 10101010
    //  : 01100110
    unsigned char res_xor = a ^ b; // 102
    cout << "a ^ b = " << bitset<8>(res_xor) << " (" << (int)res_xor << ")" << endl;

    // NOT (~)
    // a: 11001100
    //  : 00110011
    unsigned char res_not_a = ~a; // 51
    cout << "~a    = " << bitset<8>(res_not_a) << " (" << (int)res_not_a << ")" << endl;

    // Left Shift (<<)
    // v: 00000101
    //  : 00010100
    unsigned char res_lshift = 5 << 2; // 20
    cout << "5 << 2= " << bitset<8>(res_lshift) << " (" << (int)res_lshift << ")" << endl;

    // Right Shift (>>)
    // v: 00010100
    //  : 00000101
    unsigned char res_rshift = 20 >> 2; // 5
    cout << "20 >> 2= " << bitset<8>(res_rshift) << " (" << (int)res_rshift << ")" << endl;
    cout << bitset<8>(20) << endl;

    return 0;
}