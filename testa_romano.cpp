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

    testar_conversao("VII", 7);
    testar_conversao("XII", 12);     
    testar_conversao("MMXXIII", 2023); 
 
    testar_conversao("IV", 4);        
    testar_conversao("IX", 9);        
    testar_conversao("XL", 40);       
    testar_conversao("CM", 900);
    
    testar_conversao("MCMXCIV", 1994);    
    testar_conversao("MMCDXLIV", 2444);   
    testar_conversao("MMMCMXCIX", 3999);  

    testar_conversao("XI", 11);
testar_conversao("XIV", 14);
testar_conversao("XV", 15);
testar_conversao("XIX", 19);
testar_conversao("XX", 20);
testar_conversao("XXX", 30);
testar_conversao("XL", 40);
testar_conversao("L", 50);
testar_conversao("LX", 60);
testar_conversao("LXX", 70);
testar_conversao("LXXX", 80);
testar_conversao("XC", 90);
testar_conversao("XCIX", 99);

testar_conversao("C", 100);
testar_conversao("CI", 101);
testar_conversao("CIV", 104);
testar_conversao("CXL", 140);
testar_conversao("CL", 150);
testar_conversao("CXC", 190);
testar_conversao("CC", 200);
testar_conversao("CCC", 300);
testar_conversao("CD", 400);
testar_conversao("D", 500);
testar_conversao("DC", 600);
testar_conversao("DCC", 700);
testar_conversao("DCCC", 800);
testar_conversao("CM", 900);
testar_conversao("CMXC", 990);
testar_conversao("CMXCIX", 999);

    cout << "\n=== TESTES CONCLUÍDOS ===\n" << endl;
    
    return 0;
}