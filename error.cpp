#include <bits/stdc++.h>
using namespace std;

// Converte carta do Truco Mineiro para valor
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

// Escolha para dupla 1 (A/C) — usa maximin
string escolherCartaDupla1(vector<string> &mao, const vector<string> &cartasOponente) {
    int n = mao.size(), m = cartasOponente.size();
    vector<int> valMao(n), valOpo(m);

    for (int i = 0; i < n; i++) valMao[i] = cartaParaValor(mao[i]);
    for (int j = 0; j < m; j++) valOpo[j] = cartaParaValor(cartasOponente[j]);

    int maximin = -2, idxEscolha = 0;
    for (int i = 0; i < n; i++) {
        int minimoLinha = 2;
        for (int j = 0; j < m; j++) {
            int payoff = (valMao[i] > valOpo[j]) ? 1 : (valMao[i] < valOpo[j] ? -1 : 0);
            minimoLinha = min(minimoLinha, payoff);
        }
        if (minimoLinha > maximin) {
            maximin = minimoLinha;
            idxEscolha = i;
        }
    }
    string carta = mao[idxEscolha];
    mao.erase(mao.begin() + idxEscolha);
    return carta;
}

// Escolha para dupla 2 (B/D) — usa minimax
string escolherCartaDupla2(vector<string> &mao, const vector<string> &cartasOponente) {
    int n = mao.size(), m = cartasOponente.size();
    vector<int> valMao(n), valOpo(m);

    for (int i = 0; i < n; i++) valMao[i] = cartaParaValor(mao[i]);
    for (int j = 0; j < m; j++) valOpo[j] = cartaParaValor(cartasOponente[j]);

    int minimax = 2, idxEscolha = 0;
    for (int j = 0; j < n; j++) {
        int maxColuna = -2;
        for (int i = 0; i < m; i++) {
            int payoff = (valOpo[i] > valMao[j]) ? 1 : (valOpo[i] < valMao[j] ? -1 : 0);
            maxColuna = max(maxColuna, payoff);
        }
        if (maxColuna < minimax) {
            minimax = maxColuna;
            idxEscolha = j;
        }
    }
    string carta = mao[idxEscolha];
    mao.erase(mao.begin() + idxEscolha);
    return carta;
}

// Determina resultado do turno
int resultadoTurno(const vector<pair<string,int>> &jogadas) {
    int maiorValor = -1;
    vector<int> vencedores;

    for (int i = 0; i < 4; i++) {
        if (jogadas[i].second > maiorValor) {
            maiorValor = jogadas[i].second;
            vencedores.clear();
            vencedores.push_back(i);
        } else if (jogadas[i].second == maiorValor) {
            vencedores.push_back(i);
        }
    }

    bool dupla1 = false, dupla2 = false;
    for (int v : vencedores) {
        if (v == 0 || v == 2) dupla1 = true;
        else dupla2 = true;
    }
    if (dupla1 && dupla2) return 0;
    if (dupla1) return 1;
    return 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> maoA(3), maoB(3), maoC(3), maoD(3);
    for (int i = 0; i < 3; i++) cin >> maoA[i];
    for (int i = 0; i < 3; i++) cin >> maoB[i];
    for (int i = 0; i < 3; i++) cin >> maoC[i];
    for (int i = 0; i < 3; i++) cin >> maoD[i];

    vector<int> resultados;

    for (int turno = 0; turno < 3; turno++) {
        vector<pair<string,int>> jogadas(4);

        // A joga
        {
            vector<string> cartasOpo;
            cartasOpo.insert(cartasOpo.end(), maoB.begin(), maoB.end());
            cartasOpo.insert(cartasOpo.end(), maoD.begin(), maoD.end());
            string carta = escolherCartaDupla1(maoA, cartasOpo);
            jogadas[0] = {carta, cartaParaValor(carta)};
        }
        // B joga
        {
            vector<string> cartasOpo;
            cartasOpo.insert(cartasOpo.end(), maoA.begin(), maoA.end());
            cartasOpo.insert(cartasOpo.end(), maoC.begin(), maoC.end());
            string carta = escolherCartaDupla2(maoB, cartasOpo);
            jogadas[1] = {carta, cartaParaValor(carta)};
        }
        // C joga
        {
            vector<string> cartasOpo;
            cartasOpo.insert(cartasOpo.end(), maoB.begin(), maoB.end());
            cartasOpo.insert(cartasOpo.end(), maoD.begin(), maoD.end());
            string carta = escolherCartaDupla1(maoC, cartasOpo);
            jogadas[2] = {carta, cartaParaValor(carta)};
        }
        // D joga
        {
            vector<string> cartasOpo;
            cartasOpo.insert(cartasOpo.end(), maoA.begin(), maoA.end());
            cartasOpo.insert(cartasOpo.end(), maoC.begin(), maoC.end());
            string carta = escolherCartaDupla2(maoD, cartasOpo);
            jogadas[3] = {carta, cartaParaValor(carta)};
        }

        int res = resultadoTurno(jogadas);
        resultados.push_back(res);
    }

    for (int i = 0; i < 3; i++) {
        cout << resultados[i] << (i == 2 ? "\n" : " ");
    }

    return 0;
}
