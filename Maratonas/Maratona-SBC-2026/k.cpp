#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    ll n; cin >> n;
    
    vector<ll> c(n);
    vector<ll> k(n);
    
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    
    for(int i = 0; i < n; i++){
        cin >> k[i];
    }
    
    ll menor = c[0] - k[0];
    ll valor1 = c[0];
    ll valor2 = k[0];
    ll sum = 0;
    
    for(int i = 0; i < n; i++){
        if(k[i] > c[i]){
            cout << -1 << "\n";
            return 0;
        }
        else if(menor > c[i] - k[i]){
            valor1 = c[i];
            valor2 = k[i];
            menor = valor1 - k[i];
        }
        sum += c[i];
    }
    
    sum = sum - valor1 + valor2;
    
    cout << sum << "\n";
    
    return 0;
}
