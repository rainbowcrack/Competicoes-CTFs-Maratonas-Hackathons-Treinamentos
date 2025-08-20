#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x; // n: num de criancas e x: peso de criancas
    
    cin >> n >> x;
    
    vector<int> criancas(n); // leitura
    for(int i = 0; i < n; i++){
        cin >> criancas[i];
    }
    
    sort(criancas.begin(), criancas.end()); // sort
    
    int gondola = 0;
    int i = 0; int j = n-1;
    
    // logica de ponteiros
    while(i <= j){
        if(criancas[i] + criancas[j] <= x){
            i++;
        }
        j--;
        
        gondola++;
    }
    
    cout << gondola << endl;
    
    return 0;
}
