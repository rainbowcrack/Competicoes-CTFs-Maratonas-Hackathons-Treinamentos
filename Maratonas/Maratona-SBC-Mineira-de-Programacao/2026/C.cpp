// Link => https://codeforces.com/group/YgJmumGtHD/contest/106552/problem/C
#include <bits/stdc++.h>
#define endl "\n"
#define pii pair<int, int>
#define mp make_pair

const int MAXN = 2e5 + 2;
using namespace std;

int last_index[MAXN]; // last_index[i] guarda o indice em que a carta com valor i esta

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    priority_queue<pii> pq; // vai guardar o par [valor, index]. Ao extrar, vira o par que contem o maior valor no heap, junto com o indice em que ele ocorre

    int n; cin >> n;
    memset(last_index, -1, sizeof(int)*(n+1)); // setando todos os indices para -1, que vai signifcar que nao existe
    
     // indice de "barreira", qualquer valor extraido que tenha indice menor que a barreira, vai ser ignorado.
     // Isso vai garantir a remocao das cartas, ao encontrar um valor que ja foi visto
     // Seja i, j, k...n os indices de elementos repetidos que apareceram no jogo
     // Eh garantido que ao estabelecer a barreira para max(i, j, k...n), eu garanto que nenhum elemento dentro do conjunto desses indices sera considerado como maximo.
    int barrier_index = -1;
    int ci;
    for(int i = 1; i <= n; i++){
        cin >> ci;
        // o valor da barreira vai ser o maximo entre o valor anterior e o valor do ultimo indice de ci
        barrier_index = max(barrier_index, last_index[ci]);
        // atualizo o last_index de ci
        last_index[ci] = i;
        // insiro ci na pq com indice i
        pq.push(mp(ci, i));

        // enquanto o valor maximo do heap tiver indice menor que last_index, removo ele
        // o valor que sobrar, eh o valor maximo valido atual
        pii tmp = pq.top();
        while(tmp.second <= barrier_index){
            pq.pop();
            tmp = pq.top();
        }

        cout << tmp.first << " " << tmp.second << endl;
    }
    /* 
    O while dentro do for nao faz a complexidade estourar pois para cada elemento, no maximo vamos fazer uma operacao
    de inserir na heap ( O(log n) ) e outra de remover( O(log n) ), ou seja, se temos n elementos, a complexidade seria
    O(2nlog n) = O(nlog n), ou seja, passa nos limites do problema
    */
}