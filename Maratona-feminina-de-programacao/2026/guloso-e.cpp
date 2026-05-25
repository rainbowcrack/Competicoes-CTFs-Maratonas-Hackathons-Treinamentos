#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int N; cin >> N; // voltas
    int P; cin >> P; // troca de pneus
    int S; cin >> S; // max de trocas
    
    int t1; cin >> t1; // tempo pneu macio
    int t2; cin >> t2; // tempo pneu medio
    int t3; cin >> t3; // tempo pneu duro
    
    int d1; cin >> d1; // max voltas pneu macio 
    int d2; cin >> d2; // max voltas pneu medio 
    int d3; cin >> d3; // max de voltas pneu duro
    
    ll custo = 0;
    //int aux = N;
    
    // condicao do pneu 1
    custo = d1 * t1;
    N = N - d1;
    
    if(N > 0 && S > 0){ // condicao do pneu 2
        if(N <= d2){ // condicao especifica 
            custo = (custo + P) + (N * t2);
            cout << custo << endl;
        } else{
            custo = (custo + P) + (d2 * t2);
            S--; // trocas permitidas
            N = N - d2;
            //aux = aux - d2;
            
            // condicao pneu 3
            if(N <= d3){ // condicao especifica
                custo = (custo + P) + (N * t3);
                cout << custo << endl;
            } else{
                custo = (custo + P) + (d3 * t3);
                cout << custo << endl;
            }
        }
        
    }else{
        cout << custo << endl;
    }
 
    return 0;
}
