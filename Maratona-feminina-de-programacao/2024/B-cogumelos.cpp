#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int num[4][2];
    int sub;
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            cin >> num[i][j];
        }
    }
    
    sub = abs(num[0][0] - num[1][0]);
    
    cout << pow(sub, 2) << endl;

    return 0;
}
