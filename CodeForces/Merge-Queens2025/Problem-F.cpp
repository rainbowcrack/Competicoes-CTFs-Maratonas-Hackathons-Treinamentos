#include <iostream>
#include <cmath>

using namespace std;

int main(){
    
    int A, B, C, D;
    int soma, area1, area2, raiz;
    
    // dimensoes do quadro A x B
    cin >> A >> B;
    area1 = A * B;
    
    // dimensoes do quadro C x D 
    cin >> C >> D;
    area2 = C * D;
    
    // soma os quadros
    soma = area1 + area2;
    
    // define a raiz
    raiz = (int) sqrt(soma);
    
    cout << ((raiz * raiz == soma)? "SIM" : "NAO") << endl;
    
    return 0;
}
