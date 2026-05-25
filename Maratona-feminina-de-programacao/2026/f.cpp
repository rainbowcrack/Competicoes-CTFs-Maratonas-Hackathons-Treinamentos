#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int N; cin >> N; // dados 
    int K; cin >> K; // valor do mestre 
    
    long double r;
    
    vector<int> lados(N);
    for(int i = 0; i < N; i++){
        cin >> lados[i];
    }
    
    // fazer o complemento aq de P(Max >= K) = 1 - P(Max < K)
    long double probabilidade = 1.0;
    
    for(int i = 0; i < N; i++){
        int d = lados[i];
        int valido = min(d, K - 1);
        
        probabilidade *= (long double)valido / d;
    }
    
    r = 1.0 - probabilidade;
    
    cout << fixed << setprecision(10) << r << endl;
    
 
    return 0;
}
