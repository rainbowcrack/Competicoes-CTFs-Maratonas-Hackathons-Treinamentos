#include <bits/stdc++.h>

using namespace std;

int main()
{
    long int n, m, a;
    int ans = 0;
    // n x m: dimensoes da praca
    // a x a: laje
    
    cin >> n >> m >> a;
    
    ans = ((n+a-1)/a) * ((m+a-1)/a);
    
    cout << ans << endl;

    return 0;
}
