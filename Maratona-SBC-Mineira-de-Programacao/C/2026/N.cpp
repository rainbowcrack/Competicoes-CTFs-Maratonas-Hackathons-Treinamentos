// Link => https://codeforces.com/group/YgJmumGtHD/contest/106552/problem/N
#include <bits/stdc++.h>
#define pii pair<int, int>
const int MAXN = 14;
using namespace std;

char grid[MAXN][MAXN];
int n;
long long ans;

vector<pii> dirs = {{1, -1}, {-1, 1}, {1, 1}, {-1, -1}}; // as direcoes das quatro diagonais

bool val(int i, int j){
    if(i < 0 || i == n || j < 0 || j == n) return false;

    return true;
}
void play(int i, int j, long long c){
    ans = max(ans, c);
    grid[i][j] = '.'; // marco a posicao atual como vazia
    // Tento ir comer alguma peca em alguma das 4 diagonais
    for(auto [x, y] : dirs){
        // Se a casa na diagonal for uma posicao valida do tabuleiro
        //, e a casa onde minha peca vai ficar apos a captura tambem
        if(val(i+x, j+y) && val(i+x+x, j+y+y)){
            // Se a casa na diagonal for uma peca 'P'
            // e a casa onde vou ficar apos a captura for vazia
            if(grid[i+x][j+y] == 'P' && grid[i+x+x][j+y+y] == '.'){
                grid[i+x][j+y] = '.'; // marco que esta vazio, efetuei a captura
                grid[i+x+x][j+y+y] = 'B'; // marco que agora ha uma peca B onde fico apos a captura
                play(i+x+x, j+y+y, c+1); // comeco uma nova jogada somando 1 em c e comecando da nova posicao
                grid[i+x][j+y] = 'P'; // desfaco ( backtracking )
                grid[i+x+x][j+y+y] = '.'; // backtracking
            }
        }
    }
    grid[i][j] = 'B';
} 
int main () {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> grid[i][j];

    ans = 0;
    // Comeca uma nova jogada para cada peca B que encontrar
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) if(grid[i][j] == 'B') play(i, j, 0);

    cout << ans << endl;
}