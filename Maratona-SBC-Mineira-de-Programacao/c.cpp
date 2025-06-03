#include <bits/stdc++.h>
#define MAX_LIN 4
#define MAX_COL 3

using namespace std;

int main()
{
    // para ir mais rapido
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    // leitura das maos dos jogadores
    string maos[MAX_LIN][MAX_COL];
    
    for(int i = 0; i < MAX_LIN; i++){
        for(int j = 0; j < MAX_COL; j++){
            cin >> maos[i][j]; 
        }
        
    }
    
    // transformando cartas de força em array de inteiros
    // usar pair ou hashmap
    vector<string> forca = {4P,7C,AE,7O,3,2,A,K,J,Q,7,6,5,4};
    
    // olhar maior carta da duplas fazer um sort
    for(int i = 0; i < MAX_LIN; i++){
        int maiorA = 
        int maiorB = 
        int maiorC = 
        int maiorD = 
    }
    
    // simular os jogos 
    
    // criar uma funcao para simular 3x
    
    return 0;
}
