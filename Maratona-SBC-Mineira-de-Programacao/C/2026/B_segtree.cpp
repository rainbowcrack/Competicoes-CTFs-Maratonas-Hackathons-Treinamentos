#include <bits/stdc++.h>
#define ll long long

using namespace std;

int const MAXN = 5e5 + 5;
ll const INF   = 0x3f3f3f3f3f3f3f3f;
int const INFI = 0x3f3f3f3f;

char arr[MAXN];
ll dp[4*MAXN];

ll N, T;

/*
    Seja dp[i] = Quantidade minima de pulos que precisei dar para chegar at√©a posi√√o i 
    A solucao consiste em, sabendo onde estou e quantos pulos tenho carregados, sei qual range posso alcan√ar.
    Ent√o, posso atualizar o range [i+1, i+pulos] com dp[i] + 1, essa atualiza√√o ser√° feita utilizando uma
    Segment Tree com Lazy Propagation modificada.
    No entanto os valores no range j√° podem ser menores que dp[i] + 1, ent√o quem vai garantir que os valores persistidos ser√o
    sempre os m√nimos √© a pr√pria Seg Tree modificada.
*/
void propagate(int node, int l, int r) {
    if (dp[node] == INF) return;

    // So vai propagar se nao for uma folha, isso garante que os valores vao escorregando ate parar nas folhas
    if (l != r) {
        // Filho a esquerda
        // Se o que esta no no atual for menor que o que esta no filho, propaga
        if(dp[node] < dp[node*2]) {
            dp[node*2] = dp[node];
        } 
        // Filho a direita
        // Se o que esta no no atual for menor que o que esta no filho, propaga
        if(dp[node] < dp[node*2 + 1]) {
            dp[node*2 + 1] = dp[node];
        }
        // Ja passou ou nao para os filhos, entao reseta o atual
        dp[node] = INF;
    }

}
ll query(int node, int L, int R, int l) {
    propagate(node, L, R);
    if (L > l || R < l) return INF;
    if (L >= l && R <= l) return dp[node];
    int mid = (L + R) / 2;

    if (mid >= l) {
        return query(node*2, L, mid, l);
    } else {
        return query(node*2 + 1, mid+1, R, l);
    }
}
void update(int node, int L, int R, int l, int r, ll value){
    propagate(node, L, R);
    if (L > r || R < l) return;
    if (L >= l && R <= r){
        if (value < dp[node]) {
            dp[node] = value;
        }
        //propagate(node, L, R);
        return;
    }
    int mid = (L + R) / 2;
    update(node*2, L, mid, l, r, value);
    update(node*2 + 1, mid+1, R, l, r, value);
}


void solve() {
    cin >> N;

    memset(dp, INFI, 4 * N * sizeof(ll));
    memset(arr, 0, (N+1) * sizeof(char));

    for( int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    ll pulos = 0;
    update(1, 1, N, 1, 1, 0); // dp[1] = 0;

    for( ll i = 1; i <= N; i++) {
        if ( arr[i] == '.'){
            pulos = 0;
            //cout << "Atual " << arr[i] << "=> " << pulos << "\n";
            continue;
        };

        pulos++;
        //cout << "Atual " << arr[i] << "=> " << pulos << "\n";
        ll atual = query(1, 1, N, i);

        // Se atual for INF, ent√o n√o posso chegar aqui, nem continuo
        if (atual == INF) continue;

        if (i < N && arr[i+1] == 'x') {
            update(1, 1, N, i+1, i+1, atual); 
        }
        // atualizar o range, somente se eu estiver n√o puder mais continuar caminhando, e precisar pular
        if ( i < N && arr[i+1] == '.') {
            update(1, 1, N, min(i+1, N), min(i+pulos, N), atual+1);
        }
    }

    ll ans = query(1, 1, N, N);
    if ( ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while(T--) {
        solve();
    }

}
