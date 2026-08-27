#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int num[4][2];
    
    // Le as coordenas (x,y) em matriz
    for (int i = 0; i < 4; i++) {
        cin >> num[i][0] >> num[i][1];
    }

    int lado = 0;
    
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            
            // distancia entre dois pontos (x1, y1) e (x2, y2)
            int dx = abs(num[i][0] - num[j][0]);
            int dy = abs(num[i][1] - num[j][1]);
            
            // maior lado do quadrado
            lado = max(lado, max(dx, dy));
        }
    }

    cout << lado * lado << endl;

    return 0;
}
