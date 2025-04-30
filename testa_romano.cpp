#include <iostream>
#include <string.h>
#include <cassert>

using namespace std;

int romanoParaArabico(const char *numero);

void testar_conversao(const char* romano, int arabico_esperado) {
    int resultado = romanoParaArabico(romano);
    if (resultado == arabico_esperado) {
        cout << "✓ " << romano << " -> " << resultado << endl;
    } else {
        cout << "✗ " << romano << " -> " << resultado << " (esperado: " << arabico_esperado << ")" << endl;

    }
}

int main() {
    cout << "\n=== TESTES DE CONVERSÃO ROMANO PARA ARÁBICO ===\n" << endl;
    
    testar_conversao("I", 1);
    testar_conversao("V", 5);
    testar_conversao("X", 10);
    testar_conversao("L", 50);
    testar_conversao("C", 100);
    testar_conversao("D", 500);
    testar_conversao("M", 1000);
 
    cout << "\n=== TESTES CONCLUÍDOS ===\n" << endl;
    
    return 0;
}