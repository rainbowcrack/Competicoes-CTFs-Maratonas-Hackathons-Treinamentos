
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // para o cin e cout ir mais rapido
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    // leituras
    int qt;
    cin >> qt;
    
    for(int i = 0; i < qt; i++){
	// leitura dos sensores
        int num1, num2, num3; 
        cin >> num1 >> num2 >> num3;
        
	// condicoes de diferente
        if(num1 != num2 && num1 != num3){
            cout << num1 << '\n';
        } else if(num2 != num1 && num2 != num3){
            cout << num2 << '\n';
        } else{
            cout << num3 << '\n';
        }
    }

    return 0;
}
