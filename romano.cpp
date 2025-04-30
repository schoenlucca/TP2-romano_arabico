#include <iostream>
#include <string.h>

using namespace std;

int romanoParaArabico(const char *numero) {
    int resultado = 0;
    int valorAtual, valorAnterior = 0;
    
    // Iteração de trás para frente pela string romana
    for (int i = strlen(numero) - 1; i >= 0; i--) {
        // Determina o valor do caractere romano atual
        switch (numero[i]) {
            case 'I': valorAtual = 1; break;
            case 'V': valorAtual = 5; break;
            case 'X': valorAtual = 10; break;
            case 'L': valorAtual = 50; break;
            case 'C': valorAtual = 100; break;
            case 'D': valorAtual = 500; break;
            case 'M': valorAtual = 1000; break;
            default:
                cout << "Caractere romano inválido: " << numero[i] << endl;
                return -1;
        }
        
        // Aplica a regra de subtração dos números romanos
        // Se um valor menor vem antes de um valor maior, ele é subtraído
        if (valorAtual >= valorAnterior)
            resultado += valorAtual;
        else
            resultado -= valorAtual;
            
        valorAnterior = valorAtual;
    }
    
    return resultado;
}
/*
int main() {
    char numeroRomano[20];
    
    cout << "Digite um número romano: ";
    cin >> numeroRomano;
    
    int valorArabico = romanoParaArabico(numeroRomano);
    
    if (valorArabico != -1)
        cout << "O valor arábico de " << numeroRomano << " é " << valorArabico << endl;
    else
        cout << "Número romano inválido!" << endl;
        
    return 0;
}
*/
