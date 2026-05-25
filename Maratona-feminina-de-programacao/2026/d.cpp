#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int N; cin >> N;
    vector<int> paises(N);
    
    ll ans = 0;
    
    for(int i = 0; i < N; i++){
        cin >> paises[i];
    }
    
    // asumindo o mdc total e dividir por cada 
    int g = paises[0];
    for(int i = 1; i < N; i++){
        g = gcd(g, paises[i]);
    }
    
    for(int j = 0; j < N; j++){
        ans += paises[j]/g;
    }
    
    cout << ans << endl;
 
    return 0;
}
