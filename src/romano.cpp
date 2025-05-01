#include <iostream>
#include <string.h>

using namespace std;

#include <cstring>
#include <iostream>
using namespace std;

int valorRomano(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return -1;
    }
}

bool subtracaoValida(char atual, char proximo) {
    // Regras válidas de subtração
    if (atual == 'I' && (proximo == 'V' || proximo == 'X')) return true;
    if (atual == 'X' && (proximo == 'L' || proximo == 'C')) return true;
    if (atual == 'C' && (proximo == 'D' || proximo == 'M')) return true;
    return false;
}

int romanoParaArabico(const char *numero) {
    if (numero == nullptr || strlen(numero) == 0) return -1;

    int resultado = 0;
    int valorAtual, valorProximo;
    int repeticoes = 1;
    char anterior = '\0';

    for (size_t i = 0; numero[i] != '\0'; i++) {
        if (valorRomano(numero[i]) == -1) return -1; // caractere inválido
    }

    size_t len = strlen(numero);
    for (int i = len - 1; i >= 0; i--) {
        valorAtual = valorRomano(numero[i]);
        if (valorAtual == -1) return -1;

        // Validação de repetições
        if (i < len - 1 && numero[i] == numero[i + 1]) {
            repeticoes++;
            // V, L e D não podem se repetir
            if (numero[i] == 'V' || numero[i] == 'L' || numero[i] == 'D') return -1;
            if (repeticoes > 3) return -1;
        } else {
            repeticoes = 1;
        }

        valorProximo = (i + 1 < len) ? valorRomano(numero[i + 1]) : 0;

        if (valorAtual < valorProximo) {
            if (!subtracaoValida(numero[i], numero[i + 1])) return -1;
            resultado -= valorAtual;
        } else {
            resultado += valorAtual;
        }
    }

    // Verificação final: valor máximo permitido
    if (resultado <= 0 || resultado > 3999) return -1;

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
