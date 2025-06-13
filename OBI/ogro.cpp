#include <bits/stdc++.h>

using namespace std;

int main()
{
    int D, E;
    int sum = 0;
    
    cin >> E >> D;
    
    if(E > D){
        sum = E + D;
    } else{
        sum = 2 * (E - D);
    }
    
    cout << abs(sum) << endl;

    return 0;
}
