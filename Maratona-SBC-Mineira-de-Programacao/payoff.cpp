#include <bits/stdc++.h>
using namespace std;

// Função para converter carta para valor conforme problema
int cartaParaValor(string c) {
    string tipo = c.substr(0, c.size()-1);
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
    cin.tie(NULL);

    vector<int> dupla1(3), dupla2(3);
    vector<string> d1str(3), d2str(3);

    // Ler mãos
    for(int i=0;i<3;i++){
        string c; cin >> c;
        d1str[i] = c;
        dupla1[i] = cartaParaValor(c);
    }
    for(int i=0;i<3;i++){
        string c; cin >> c;
        d2str[i] = c;
        dupla2[i] = cartaParaValor(c);
    }
    for(int i=0;i<3;i++){
        string c; cin >> c; // cartas dos jogadores C e D (não usadas no payoff direto)
    }
    for(int i=0;i<3;i++){
        string c; cin >> c;
    }

    // Montar matriz de payoff 3x3
    // +1 se dupla 1 ganha (carta mais forte)
    // -1 se dupla 2 ganha
    // 0 empate (mesma força)

    int M[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(dupla1[i] > dupla2[j]) M[i][j] = 1;
            else if(dupla1[i] < dupla2[j]) M[i][j] = -1;
            else M[i][j] = 0;
        }
    }

    // Exibir matriz para debug
    cout << "Matriz de Payoff (Dupla1 linhas x Dupla2 colunas):\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }

    // Aplicar maximin para a dupla 1
    // maximin = max das linhas dos mínimos das linhas
    int maximin = -2;
    int linhaMaximin = -1;
    for(int i=0;i<3;i++){
        int minimoLinha = 2;
        for(int j=0;j<3;j++){
            minimoLinha = min(minimoLinha, M[i][j]);
        }
        if(minimoLinha > maximin){
            maximin = minimoLinha;
            linhaMaximin = i;
        }
    }

    // Aplicar minimax para a dupla 2
    // minimax = min das colunas dos máximos das colunas
    int minimax = 2;
    int colunaMinimax = -1;
    for(int j=0;j<3;j++){
        int maxColuna = -2;
        for(int i=0;i<3;i++){
            maxColuna = max(maxColuna, M[i][j]);
        }
        if(maxColuna < minimax){
            minimax = maxColuna;
            colunaMinimax = j;
        }
    }

    cout << "\nMaximin (Dupla1): " << maximin << " na linha " << linhaMaximin << "\n";
    cout << "Minimax (Dupla2): " << minimax << " na coluna " << colunaMinimax << "\n";

    // Decidir resultado do turno
    if(maximin == minimax){
        if(maximin == 1){
            cout << "Dupla 1 vence o turno\n";
        } else if(maximin == -1){
            cout << "Dupla 2 vence o turno\n";
        } else {
            cout << "Empate no turno\n";
        }
    } else {
        cout << "Não existe equilíbrio puro, jogo pode ser misto\n";
    }

    return 0;
}
