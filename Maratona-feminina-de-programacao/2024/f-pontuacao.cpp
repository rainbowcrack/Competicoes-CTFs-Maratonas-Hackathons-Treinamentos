#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int num, count = 0;
    cin >> num;

    // programacao: 8 pontos
    // volei: 4 pontos
    // futebol: 2 pontos
    // corrida: 1 ponto
    
    for (int i = 3; i >= 0; i--) {
        int power = 1 << i; // 2^i
        while (num >= power) {
            num -= power;
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
