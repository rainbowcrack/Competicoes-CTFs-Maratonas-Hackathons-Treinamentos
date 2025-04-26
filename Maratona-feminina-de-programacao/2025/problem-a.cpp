#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); // cin/cout rapido
    
    int TAM, K;
    cin >> TAM >> K;   
    
    int amplitudes[TAM];
    
    // Ler as amplitudes ordenadas com O(nlogn)
    for (int i = 0; i < TAM; i++) {
        cin >> amplitudes[i];
    }
    
    sort(amplitudes, amplitudes + TAM);
    
    // k ate M, valores >= ks com O(n)
    int index = 0;
    for (int k = 1; k <= K; k++) {
        
        while (index < TAM && amplitudes[index] < k) {
            index++;
        }
        
        // maior que k, amplitude maxima
        cout << TAM - index << " ";
    }
    
    cout << endl; // endl
    return 0;
}
