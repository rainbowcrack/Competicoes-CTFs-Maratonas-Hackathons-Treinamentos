// 20 minutos cromometrado
#include <iostream>

using namespace std;

// Maratona de Programacao da SBC - ICPC - 2024
// Problema A, Atencao a Reuniao

int main()
{
    int N, K;
    int intervalo = 0, resultado = 0;

    cin >> N;
    cin >> K;

    // intervalo de N termos eh N-1, subtrair dos diretores K

    if(1 <= N && N <= 100){
        if(1 <= K && K <= 1000 && K >= N){
            intervalo = N-1;
            K -= intervalo;
            resultado = K/N;
        }
    }

    cout << resultado << endl;

    return 0;
}
