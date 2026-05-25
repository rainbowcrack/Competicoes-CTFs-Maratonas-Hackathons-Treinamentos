#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int X; cin >> X; // largura
    int Y; cin >> Y; // comprimento
    
    ll ans1 = 0;
    ll ans2 = 0;
    
    ans1 = (Y/7) * X;
    ans2 = (X/7) * Y;
    
    if(ans1 > ans2){
        cout << ans1 << endl;
    } else{
        cout << ans2 << endl;
    }
 
    return 0;
}
