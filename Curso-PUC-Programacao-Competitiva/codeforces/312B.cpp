#include <iostream>
using namespace std;

int main()
{
    // para ir mais rapido
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    // entrada e leitura
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    // divisoes de R e Z
    double p1 = (double) a / b;
    double p2 = (double) c / d;
    
    // calculo de pg, a1/(1-r)
    double probabilidade = p1 / (1 - (1 - p1) * (1 - p2));
    
    // indica a precisao
    cout.precision(12);
    cout << fixed << probabilidade << endl;

    return 0;
}
