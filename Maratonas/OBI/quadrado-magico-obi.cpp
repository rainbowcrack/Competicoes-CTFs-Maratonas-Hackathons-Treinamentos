#include <iostream>

using namespace std;

int main(){
    // Lendo a entrada do exercicio
    int N;
    cin >> N;
    int quadrado[N][N];
    
    // sentinela
    int linhaZero = -1, colunaZero = -1;
    
    // leitura do quadrado magico
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> quadrado[i][j];
            
            // verifica se tem '0'
            if(quadrado[i][j] == 0){
                linhaZero = i;
                colunaZero = j;
            }
        }
    }
    
    // calculo da soma
    int linhaComparar = (linhaZero == 0)? 1:0;
    int somaMagica = 0; // acumular
    int somaTotal = 0; 
    
    for(int i = 0; i < N; i++){
        somaMagica += quadrado[linhaComparar][i];
        somaTotal += quadrado[linhaZero][i];
    }
    
    // substitui o valor na posicao l,c
    int falta = somaMagica - somaTotal;
    quadrado[linhaZero][colunaZero] = falta;
    
    // verifica linha e coluna
    bool valido = true;
    
    for(int i = 0; i < N; i++){
        int somaLinha = 0;
        int somaColuna = 0;
        
        for(int j = 0; j < N; j++){
            somaLinha += quadrado[i][j];
            somaColuna += quadrado[j][i];
        }
        
        if(somaLinha != somaMagica || somaColuna != somaMagica){
            valido = false;
            break;
        }
    }
    
    // verifica diagonais
    int diagonal1 = 0, diagonal2 = 0;
    for(int i = 0; i < N; i++){
        diagonal1 += quadrado[i][i];
        diagonal2 += quadrado[i][N - 1 - i];
    }
    
    if(diagonal1 != somaMagica || diagonal2 != somaMagica){
        valido = false;
    }
    
    // valores
    if(!valido){
        cout << -1 << endl;
    }else{
        cout << falta << endl;
        cout << linhaZero + 1 << endl;
        cout << colunaZero + 1 << endl;
    }
    
    return 0;
}
