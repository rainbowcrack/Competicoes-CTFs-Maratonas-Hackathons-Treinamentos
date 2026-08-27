// Link => https://codeforces.com/group/YgJmumGtHD/contest/106552/problem/I
#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f


const int MAXN = 1e4 + 1;
const int MAXM = 31;

using namespace std;

int arr[MAXN]; // linguas do diplomata i em representacao binaria de int de 32 bits 
int dist[MAXM][MAXM]; // distancia (em trocas de lingua necessarias) da lingua i para a lingua j
int lang[MAXM]; // linguas em representacao binaria que a lingua i consegue acessar com custo de troca 1

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N, M, Q; cin >> N >> M >> Q;
    
    memset(dist, INF, sizeof dist);

    for(int i = 0; i < N; i++) {
        int tam; cin >> tam;
        for(int j = 0; j < tam; j++) {
            int l; cin >> l;
            arr[i] = arr[i] | (1 << (l-1));
        }

        for(int j = 0; j < M; j++) {
            if(arr[i] & (1 << j)) {
                lang[j] = lang[j] | arr[i];
            }
        }
    }

    // Pre processar as distancias 1 entre as linguas
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            if( i == j ) {
                dist[i][j] = 0;
            }else if(( lang[i] & (1 << j))) {
                dist[i][j] = 1;
            }
        }
    }

    // Pre processar menor distancia de todos para todos
    for(int k = 0; k < M; k++) {
       for(int i = 0; i < M; i++) {
           for(int j = 0 ; j < M ; j++) {
               dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
           }
       }
    }


    for(int q = 0; q < Q; q++) {
        int a, b; cin >> a >> b;
        a--; b--;

        int la, lb; la = arr[a]; lb = arr[b];
        int ans = INF;
        for( int i = 0; i < M; i++) {
            for( int j = 0; j < M; j++) {
                if ( (la & (1 << i)) && (lb & (1 << j)) ) {
                    ans = min(ans, dist[i][j]);    
                }
            }
        }
        
        cout << (ans == INF ? -1 : ans) << endl;
    }


}
