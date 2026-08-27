#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int N; cin >> N; // voltas
    int P; cin >> P; // troca de pneus
    int S; cin >> S; // max trocas
 
    int t1, t2, t3; // tempo pneu macio, medio, duro
    cin >> t1 >> t2 >> t3;
 
    int d1, d2, d3; // max voltas pneu macio, medio, duro
    cin >> d1 >> d2 >> d3;
 
    ll dp[1005][10];
 
    const ll INF = 1e18;
 
    // nao descoberto ehh INF
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= S + 1; j++){
            dp[i][j] = INF;
        }
    }
 
    dp[0][0] = 0;
 
    for(int voltas = 0; voltas <= N; voltas++){
 
        for(int trocas = 0; trocas <= S; trocas++){
 
            if(dp[voltas][trocas] == INF) continue;
 
            // pneu macio
            for(int k = 1; k <= d1; k++){
 
                if(voltas + k > N) break;
 
                dp[voltas + k][trocas + 1] = min(dp[voltas + k][trocas + 1], dp[voltas][trocas] + P + 1LL * k * t1);
            }
 
            // pneu medio
            for(int k = 1; k <= d2; k++){
 
                if(voltas + k > N) break;
 
                dp[voltas + k][trocas + 1] = min(dp[voltas + k][trocas + 1], dp[voltas][trocas] + P + 1LL * k * t2);
            }
 
            // pneu duro
            for(int k = 1; k <= d3; k++){
 
                if(voltas + k > N) break;
 
                dp[voltas + k][trocas + 1] = min(dp[voltas + k][trocas + 1], dp[voltas][trocas] + P + 1LL * k * t3);
            }
        }
    }
 
    ll ans = INF;
 
    for(int i = 1; i <= S + 1; i++){
        ans = min(ans, dp[N][i]);
    }
 
    ans -= P;
 
    cout << ans << endl;
 
    return 0;
}
