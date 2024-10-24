#include <iostream>
#include <string>

using namespace std;

bool ehpalindromo(const string& str) {
    // cria vetores vazios para strings
    string ida = ""; 
    string volta = "";
    
    // vetor volta com a string invertida
    for (int i = str.length() - 1; i >= 0; i--) {
        volta += str[i];
    }
    
    // vetor ida com a string original
    for (int i = 0; i < str.length(); i++) {
        ida += str[i];
    }
    
    // verificar palindromo de vogal
    return (ida == volta);
}

int main() {
    string palavra, vogais = "aeiou";
    
    cin >> palavra;
    
    // cria um vetor vogal vazio
    string vetorVogal = "";
    
    for (char c : palavra) {
        // filtragem de vogais em palavras
        if (vogais.find(c) != string::npos) {
            // acumulador de vetor
            vetorVogal += c;
        }
    }
    
    // verifica palindromos de vogaus
    if (ehpalindromo(vetorVogal)) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }
    
    return 0;
}
