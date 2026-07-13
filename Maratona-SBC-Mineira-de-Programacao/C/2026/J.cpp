// Link => https://codeforces.com/group/YgJmumGtHD/contest/106552/problem/J
#include <bits/stdc++.h>

const int MAXP = 1e6 + 1; // Primo maximo
using namespace std;

int freq[MAXP]; // freq[i] representa em quantos players apareceu o primo i

void primos(int x) {

    for(int i = 2; i*i <= x; i++) { // itera ate a raiz de x, pior caso sqtr(x).
        if(x % i == 0) freq[i]++; // achou fator primo i, incrementa freq
        while(x % i == 0) {
            x /= i; // divide n por i ate o nao existir mais fatores i no numero
        }
    }

    // se cair nesse if significa que o numero x inicial contem um fator primo i
    // tal que i > sqrt(x), sendo exatamente o x residual.
    if(x > 1) freq[x]++;

}
int main() {
    // O problema se resume em encontrar qual eh o numero primo i que aparece em mais players
    // Ou seja, que possui maior freq[i]
    // Para calcular freq[i], vamos pegar cada numero e fatorar em fatores primos
    // para cada fator primo j (distinto na representacao daquele numero) encontrado,
    // adicionamos 1 a freq[j] 

    int n; cin >> n;
    int pi;
    for(int i = 0; i < n; i++) {
        cin >> pi;
        primos(pi);
    }

    int ans = 2;
    for(int i = 2; i <= MAXP; i++){
        if(freq[ans] <= freq[i]) {
            ans = i;
        }
    }

    cout << ans << endl;
}