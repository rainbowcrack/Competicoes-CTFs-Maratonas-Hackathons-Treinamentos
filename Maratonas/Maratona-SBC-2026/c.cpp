#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    ll t, c, k; cin >> t >> c >> k;
    
    ll cambio = t * k;
    
    if(cambio < c) cout << cambio << "\n";
    else cout << c << "\n";
    
    return 0;
}
