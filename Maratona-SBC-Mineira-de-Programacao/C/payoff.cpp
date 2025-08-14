#include <bits/stdc++.h>
using namespace std;

// converte cartas
int cartaParaValor(const string &c) {
    string tipo = c.substr(0, c.size() - 1); 
    char naipe = c.back(); 

    if (c == "4P") return 14;
    if (c == "7C") return 13;
    if (c == "AE") return 12;
    if (c == "7O") return 11;
    if (tipo == "3") return 10;
    if (tipo == "2") return 9;
    if (tipo == "A") return 8;
    if (tipo == "K") return 7;
    if (tipo == "J") return 6;
    if (tipo == "Q") return 5;
    if (tipo == "7") return 4;
    if (tipo == "6") return 3;
    if (tipo == "5") return 2;
    if (tipo == "4") return 1;
    return 0; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // vetor de maos e vetor de duplas
    vector<string> maoA(3), maoB(3), maoC(3), maoD(3);
    vector<int> dupla1(3), dupla2(3);

    // ler xartas
    for (int i = 0; i < 3; i++) cin >> maoA[i];
    for (int i = 0; i < 3; i++) cin >> maoB[i];
    for (int i = 0; i < 3; i++) cin >> maoC[i];
    for (int i = 0; i < 3; i++) cin >> maoD[i];

    // junta duplas
    for (int i = 0; i < 3; i++) dupla1[i] = cartaParaValor(maoA[i]);
    for (int i = 0; i < 3; i++) dupla2[i] = cartaParaValor(maoB[i]);

    // matriz de payoff 3x3
    int M[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (dupla1[i] > dupla2[j]) M[i][j] = 1;
            else if (dupla1[i] < dupla2[j]) M[i][j] = -1;
            else M[i][j] = 0;
        }
    }

    // debug -- ex.
    cout << "Matriz de Payoff (Dupla1 linhas x Dupla2 colunas):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(2) << M[i][j] << " ";
        }
        cout << "\n";
    }

    // Maximin (Dupla 1)
    int maximin = -2, linhaMax = -1;
    for (int i = 0; i < 3; i++) {
        int minimoLinha = 2;
        for (int j = 0; j < 3; j++) {
            minimoLinha = min(minimoLinha, M[i][j]);
        }
        if (minimoLinha > maximin) {
            maximin = minimoLinha;
            linhaMax = i;
        }
    }

    // Minimax (Dupla 2)
    int minimax = 2, colunaMin = -1;
    for (int j = 0; j < 3; j++) {
        int maxColuna = -2;
        for (int i = 0; i < 3; i++) {
            maxColuna = max(maxColuna, M[i][j]);
        }
        if (maxColuna < minimax) {
            minimax = maxColuna;
            colunaMin = j;
        }
    }

    cout << "\nMaximin (Dupla 1): " << maximin << " na linha " << linhaMax << "\n";
    cout << "Minimax (Dupla 2): " << minimax << " na coluna " << colunaMin << "\n";

    if (maximin == minimax) {
        if (maximin == 1) cout << "Dupla 1 vence o turno\n";
        else if (maximin == -1) cout << "Dupla 2 vence o turno\n";
        else cout << "Empate no turno\n";
    } else {
        cout << "Sem equilibrio.";
    }

    return 0;
}