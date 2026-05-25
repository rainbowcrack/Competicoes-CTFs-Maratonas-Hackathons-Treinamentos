#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    ll N; cin >> N;
        
    if(N % 3 == 0){ // ciclos de 3
        cout << "PERDE" << endl;
    } else{
        cout << "GANHA" << endl;
    }
    
 
    return 0;
}
