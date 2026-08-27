#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); // rapido cin/cout
    
    int n, mestre, pato;

    cin >> n >> mestre >> pato;

    int criancas[n], index = 0;

    // preenche as crianças
    for (int i = 1; i <= n; i++) {
        criancas[index++] = i;
    }

    // remove o mestre das criancas (shift-1)
    mestre--;
    for (int j = mestre; j < n - 1; j++) {
        criancas[j] = criancas[j + 1];
    }

    // posicao do mestre
    int tam = n - 1;
    int posicao = mestre; 

    // contar a qt de patos circular
    for (int k = 0; k < pato; k++) {
        posicao = (posicao + 1) % tam;
    }

    cout << criancas[posicao] << endl;

    return 0;
}
