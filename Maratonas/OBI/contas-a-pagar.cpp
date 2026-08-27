#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V; // valor na conta 
    int A, F, P; // contas a pagar
    
    cin >> V >> A >> F >> P;
    
    if((A + F + P) <= V){
        cout << 3 << endl;
        
    } else{
        if((A + F) <= V || (A + P) <= V || (P + F) <= V){
            cout << 2 << endl;
        }
        else if(A <= V || F <= V || P <= V){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }

    return 0;
}
