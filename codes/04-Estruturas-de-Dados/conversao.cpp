/**
 * @file conversao.cpp
 * @brief Conversão entre números e strings.
 */
#include <iostream>
#include <string>

using namespace std;

int main() {
  // Número para String
  int num = 1337;
  string str_num = to_string(num);
  cout << "Número " << num << " como string: \"" << str_num << "\"" << endl; // Número 1337 como string: "1337"

  // String para Número
  string str = "42";
  int int_str = stoi(str);
  cout << "String \"" << str << "\" como int: " << int_str << endl; // String "42" como int: 42

  string str_ll = "9876543210987";
  long long ll_str = stoll(str_ll);
  cout << "String \"" << str_ll << "\" como long long: " << ll_str << endl; // String "9876543210987" como long long: 9876543210987

  // Char (dígito) para Número
  char digito = '7';
  int valor_digito = digito - '0';
  cout << "Char '" << digito << "' como int: " << valor_digito << endl; // Char '7' como int: 7
  
  // Exemplo: somar os dígitos de um número grande lido como string
  string numero_grande = "123456789";
  long long soma_digitos = 0;
  for (char c : numero_grande) {
    soma_digitos += (c - '0');
  }
  cout << "A soma dos dígitos de " << numero_grande << " é: " << soma_digitos << endl; // A soma dos dígitos de 123456789 é: 45

  return 0;
}