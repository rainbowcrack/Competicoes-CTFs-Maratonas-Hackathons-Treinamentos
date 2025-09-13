# Estruturas de Dados e Algoritmos para a Maratona de Programação da SBC

## Dicas
* Em c++, para chamar as **principais** bibliotecas em C++ e automatizar o **std**, utilize:
```c
#include <bits/stdc++.h>
using namespace std;
```
* Para rodar o I/O de forma mais rápida, utilize:
```c
cin/cout: ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
```
Para ir mais rápido, usar scanf/printf (análogo para cin.tie(0)):

```c
setvbuf(stdin, NULL, _IOFBF, 1<<20); // Aumenta buffer do stdin
setvbuf(stdout, NULL, _IOFBF, 1<<20); // Aumenta buffer do stdout
```
## Arrays (sequenciais e dinâmicos):
```c
    vector<int> v;

    // Inserção de elementos no final
    v.push_back(10); 
    v.push_back(20);

    cout << "v[0]: " << v[0] << endl; // Acesso por índice
 
    cout << "Tamanho: " << v.size() << endl; // Tamanho do vetor
    
    v.insert(v.begin() + 1, 15); // Inserção em posição específica [10, 15, 20]

    v.erase(v.begin()); // Remoção de elemento por posição

    v.pop_back(); // Remoção do último elemento

    if (!v.empty()) {
        cout << "Vetor não está vazio" << endl; // Verificar se está vazio
    }

    v.resize(4); // redimensiona o vetor: [15, 0, 0, 0]

    v.clear(); // limpa o vetor

    vector<int> a(5, 42); // preenche o vetor com elementos iguais [42, 42, 42, 42, 42]
    // dá para fazer isso com "n" elementos chamando a variável a(n, 42) ou elemento preenchido pelo user em a(5, n). Forma genérica a(n,m)

    for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;

    // FOR-EACH (iterar)
    for (int x : a) cout << x << " ";
    cout << endl;

    // SORTING - (ordenar)
    sort(a.begin(), a.end()); // crescente
    reverse(a.begin(), a.end()); // decrescente

    // LOWER_BOUND - (binária em vetor ordenado)
    vector<int> b = {10, 20, 30, 40};
    int pos = lower_bound(b.begin(), b.end(), 25) - b.begin();
    cout << "Lower bound para 25: posição " << pos << endl;
    // como se fosse o "piso"/limite do valor que quero achar
```
## Stack (Pilha)
```c
stack<int> s;

    // Inserir elemento no topo
    s.push(10); // s: [10] (topo)
    s.push(20); // s: [10 (base), 20 (topo)]

    // Acessar elemento do topo
    if (!s.empty()) {
        cout << "Topo: " << s.top() << endl; // 20
    }
```
## Queue (Fila)
```c
   queue<int> q;
   
    q.push(10); // Inserir elemento no final da fila (enqueue)
    q.push(20); 
    q.push(30); 

    // Acessar elemento da frente
        cout << "Frente: " << q.front() << endl; // 10

    // Acessar elemento do final
        cout << "Final: " << q.back() << endl;

    // Remover elemento da frente (dequeue)
        q.pop();
```
## Set (sem repetição)
```c
    set<int> s;

    // Inserção de elementos
    s.insert(30);
    s.insert(10);
    s.insert(10); // Não insere, pois 10 já existe (retorna pair<iterator, bool> onde bool é false)
    s.insert(20)

    for (int x : s) { // itera ordena [10,20,30]
        cout << x << " "; 
    }

    // s.count(value) retorna 1 se existe, 0 caso contrário (O(log N))
    if (s.count(20)) { 
        cout << "20 encontrado no set (usando count)" << endl;
    }

    size_t num_erased = s.erase(10); // Remove o valor 10. Retorna número de elementos removidos (0 ou 1).
```

## Map e HashMap (Dicionário)
```c
    map<string, int> m; // Mapeia string (chave) para int (valor)

    // Inserção ou atualização usando operator[]
    m["banana"] = 5;   
    m["apple"] = 10;  
    m["banana"] = 7;

    // Iterar (ordenado pela chave)
    cout << "Map ordenado por chave:" << endl;
    for (auto const& [chave, valor] : m) {
        cout << chave << " -> " << valor << endl;
    }
  
    cout << "Preço da apple: " << m["apple"] << endl; // Acesso ao valor pela chave: 10

    // m.count(key) retorna 1 se existe, 0 caso contrário (O(log N))
    if (m.count("banana")) { 
        cout << "Banana existe no map, preco: " << m["banana"] << endl;
    }
```

## Pair 
```c 
    pair<int, string> p1 = {1, "hello"};
    pair<int, string> p2 = make_pair(2, "world"); // Alternativa de criação

    cout << "P1: (" << p1.first << ", " << p1.second << ")" << endl; // P1: (1, hello)
    p1.first = 100; // Modificável

    // Vetor de pares
    vector<pair<int, char>> vp;
    vp.push_back({3, 'c'});
    vp.push_back({1, 'a'});
    vp.push_back({2, 'b'});

    // Ordenar vetor de pares (ordena primeiro pelo .first, depois pelo .second como desempate)
    sort(vp.begin(), vp.end());
    cout << "Vetor de pares ordenado: ";
    for(const auto& par : vp) {
        cout << "(" << par.first << "," << par.second << ") "; // (1,a) (2,b) (3,c)
    }
    cout << endl;

    // Pares como chaves de map (precisam de ordenação, padrão funciona para tipos básicos)
    map<pair<int, int>, string> m_pair_key;
    m_pair_key[{1, 2}] = "Ponto A";
    m_pair_key[make_pair(0, 5)] = "Ponto B";

    cout << "Map com pair como chave para (1,2): " << m_pair_key[{1,2}] << endl;
    return 0;
}
```
## Tuple
```c
    tuple<int, char, double> t1 = {1, 'a', 3.14};
    auto t2 = make_tuple(2, 'b', 2.71);

    // Acesso aos elementos por índice (constante em tempo de compilação)
    cout << "Elemento 0 do tuple t1: " << get<0>(t1) << endl; // 1
    get<1>(t1) = 'z'; // Modificando um elemento
    cout << "Elemento 1 do tuple t1 (modificado): " << get<1>(t1) << endl; // z
    cout << "Elemento 2 do tuple t1: " << get<2>(t1) << endl; // 3.14

    // C++17 structured binding (desestruturação)
    auto [id_val, status_char, valor_double] = t2; // id_val=2, status_char='b', valor_double=2.71
    cout << "Tuple t2 (desestruturado): " << id_val << ", " << status_char << ", " << valor_double << endl;

    // Comparação de tuples (lexicográfica, elemento a elemento da esquerda para direita)
    tuple<int, int, int> tp1 = {1, 20, 5};
    tuple<int, int, int> tp2 = {1, 10, 100};
    if (tp1 > tp2) { // (1,20,5) > (1,10,100) é true porque 20 > 10
        cout << "tp1 > tp2" << endl;
    }
    
    // Vetor de tuples e ordenação
    vector<tuple<int, string, double>> vt;
    vt.emplace_back(2, "banana", 1.99);
    vt.emplace_back(1, "apple", 2.50);
    vt.emplace_back(2, "apricot", 3.10);

    sort(vt.begin(), vt.end()); // Ordena lexicograficamente
    cout << "Vetor de tuples ordenado:" << endl;
    for(const auto& t : vt) {
        cout << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")" << endl;
    }
```
## Queue de Prioridade (Fila de Prioridade)
```c
priority_queue<int> pq;

    // Insercao - O(1)
    pq.push(5);
    pq.push(10);
    pq.push(1);

    // Acesso ao maior elemento (topo) - O(1)
    cout << "Maior: " << pq.top() << "\n"; // 10

    // Remocao do maior
    pq.pop();

    cout << "Proximo maior: " << pq.top() << "\n"; // 5
```
**Menor** no topo:
```c
priority_queue<int, vector<int>, greater<int>> pq;
```
Usando **pair**:
```c
// Min-heap: menor prioridade no topo
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> fila;
    fila.push({2, "Carlos"});
    fila.push({1, "Ana"});
    fila.push({3, "Bruno"});

// Max-heap: maior prioridade no topo
priority_queue<pair<int, string>> fila;
```
## Grafos (python)
**Lista de Adjacência**:
```python
from collections import defaultdict, deque
import heapq

grafo = defaultdict(list)

# Adicionando arestas: grafo[u].append((v, peso))
grafo[0].append((1, 4))
grafo[0].append((2, 1))
grafo[1].append((3, 1))
grafo[2].append((1, 2))
grafo[2].append((3, 5))
```
**Matriz de Adjacência**:
```python
# Criando matriz de adjacência com dicionarios
matriz = dict()

# Adicionando vértices manualmente
vertices = ['A', 'B', 'C']
for u in vertices:
    matriz[u] = dict()
    for v in vertices:
        matriz[u][v] = float('inf')  # ou 0 para grafos não ponderados

# Adicionando arestas
matriz['A']['B'] = 5
matriz['B']['C'] = 3
matriz['C']['A'] = 2

print(matriz['A']['B'])  # 5
matriz['A']['B'] = 1     # muda o peso da aresta A->B
```
diskrja
**DFS**:
```python
def dfs(u, visitado):
    visitado.add(u)
    print(u, end=' ')
    for v in matriz[u]:
        if matriz[u][v] != float('inf') and v not in visitado:
            dfs(v, visitado)

dfs('A', set())
```
**BFS**:
```python
from collections import deque

def bfs(origem):
    visitado = set([origem])
    fila = deque([origem])

    while fila:
        u = fila.popleft()
        print(u, end=' ')
        for v in matriz[u]:
            if matriz[u][v] != float('inf') and v not in visitado:
                visitado.add(v)
                fila.append(v)

bfs('A')
```
**Dijkstra**:
```python
import heapq

def dijkstra(origem):
    dist = {v: float('inf') for v in matriz}
    dist[origem] = 0
    heap = [(0, origem)]

    while heap:
        d, u = heapq.heappop(heap)
        if d > dist[u]:
            continue
        for v in matriz[u]:
            peso = matriz[u][v]
            if peso != float('inf') and dist[u] + peso < dist[v]:
                dist[v] = dist[u] + peso
                heapq.heappush(heap, (dist[v], v))

    return dist

print(dijkstra('A'))
```
**Algoritmo de Kruskal com Union-Find, Árvores Geradoras Mínimas**
* Use Kruskal se o grafo vem com lista de arestas.
* Use Prim se o grafo vem com lista de adjacência.

```python
def find(pai, u):
    if pai[u] != u:
        pai[u] = find(pai, pai[u])  # path compression
    return pai[u]

def union(pai, rank, u, v):
    ru, rv = find(pai, u), find(pai, v)
    if ru == rv:
        return False
    if rank[ru] < rank[rv]:
        pai[ru] = rv
    else:
        pai[rv] = ru
        if rank[ru] == rank[rv]:
            rank[ru] += 1
    return True

def kruskal(n, arestas):
    arestas.sort(key=lambda x: x[2])  # ordena por peso
    pai = list(range(n))
    rank = [0]*n
    custo_total = 0
    mst = []

    for u, v, peso in arestas:
        if union(pai, rank, u, v):
            mst.append((u, v))
            custo_total += peso

    return custo_total, mst
```
## Programação Dinâmica (python)
* Problema da Mochila e da Tora de Madeira
Usar matriz para ver melhor, pegando o cache do cálculo anterior para o atual. Ex.: recursão, fatorial e fibonacci
```python
def mochila(n, W, pesos, valores):
    dp = [[0] * (W + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(W + 1):
            if pesos[i - 1] <= w:
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - pesos[i - 1]] + valores[i - 1])
            else:
                dp[i][w] = dp[i - 1][w]

    return dp[n][W]
```
Exemplo de uso:
```python
valores = [60, 100, 120]
pesos = [10, 20, 30]
W = 50
n = len(valores)

print(mochila(n, W, pesos, valores))  # Saída esperada: 220
```
## Teoria de Jogos
* Nim Game
" Você tem várias pilhas com pedras. Dois jogadores jogam alternadamente. Em cada jogada, um jogador pode remover qualquer quantidade de pedras de uma única pilha."
Se o XOR de todas as pilhas é 0, o jogador atual está perdendo se ambos jogam perfeitamente
```c
 int n;
    cin >> n;  // número de pilhas

    int xor_total = 0;
    for (int i = 0; i < n; ++i) {
        int pedras;
        cin >> pedras;
        xor_total ^= pedras;
    }

    if (xor_total == 0)
        cout << "Jogador 2 vence (posição perdedora)\n";
    else
        cout << "Jogador 1 vence (posição vencedora)\n";
```
**Grundy Numbers (Números de Grundy)**: Usados para resolver jogos combinatórios imparciais — onde:
Dois jogadores jogam alternadamente, Ambos têm as mesmas opções de jogada, E quem não pode jogar perde.
**Teorema de Sprague-Grundy: Todo jogo imparcial com posições finitas pode ser reduzido a um jogo de Nim. Cada posição do jogo tem um número de Grundy (também chamado de nimber), e:
```c
Se Grundy(position) == 0, é posição perdedora

Se Grundy(position) != 0, é posição vencedora
```
Lógica: **int xor_total = grundy[pilha1] ^ grundy[pilha2] ^ grundy[pilha3];**

## Somatórios
- Soma dos n primeiros inteiros:  
  S = n * (n + 1) / 2

- Soma dos quadrados:  
  S = n * (n + 1) * (2n + 1) / 6

- Soma dos cubos:  
  S = [n * (n + 1) / 2]²
---
## Progressões
### PA – Progressão Aritmética
- Termo geral:  
  an = a1 + (n - 1) * r

- Soma dos n primeiros termos:  
  S = n * (a1 + an) / 2
---
### PG – Progressão Geométrica

- Termo geral:  
  an = a1 * r^(n - 1)

- Soma dos n primeiros termos (r ≠ 1):  
  S = a1 * (r^n - 1) / (r - 1)

- Soma da PG infinita (|r| < 1):  
  S = a1 / (1 - r)
---
## Geometria Analítica
- Distância entre dois pontos (x1, y1) e (x2, y2):  
  d = sqrt((x2 - x1)² + (y2 - y1)²)

- Ponto médio entre dois pontos:  
  M = ((x1 + x2) / 2, (y1 + y2) / 2)

- Coeficiente angular da reta (m):  
  m = (y2 - y1) / (x2 - x1)

- Equação da reta:  
  y = mx + b  ou  ax + by + c = 0

- Área de um triângulo dados 3 pontos:  
  A = 1/2 * |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)|
---
## Teoria dos Jogos
### Jogo de Nim:
- XOR de todas as pilhas:
  - Se XOR == 0: posição perdedora
  - Se XOR != 0: posição vencedora
    
### Grundy Numbers:
- Grundy(state) = menor número inteiro não presente nos grundies dos estados alcançáveis
- Posição perdedora → Grundy = 0
---
## 🔣 Análise Combinatória
- Fatorial:  
  n! = n * (n - 1) * (n - 2) * ... * 1
  
- Permutação simples:  
  P(n) = n!

- Permutação com repetição:  
  P(n; a, b, ...) = n! / (a! * b! * ...)

- Arranjo (ordem importa):  
  A(n, k) = n! / (n - k)!

- Combinação (ordem não importa):  
  C(n, k) = n! / (k! * (n - k)!)
---
## 🔁 Séries
- Série harmônica (diverge):  
  Hn = 1 + 1/2 + 1/3 + ... + 1/n ≈ ln(n)

- Série p:
  - Converge se p > 1
  - Diverge se p ≤ 1

---

## ∑ Convergência / Divergência
- Soma infinita de 1/n diverge  
- Soma infinita de 1/n^p:
  - Converge se p > 1
  - Diverge se p ≤ 1

---
### Derivadas
- d/dx (x^n) = n * x^(n - 1)
- d/dx (sen x) = cos x
- d/dx (cos x) = -sen x
- d/dx (e^x) = e^x
- d/dx (ln x) = 1/x
- 
### Integrais
- ∫ x^n dx = x^(n + 1) / (n + 1) + C  (n ≠ -1)
- ∫ 1/x dx = ln|x| + C
- ∫ e^x dx = e^x + C
- ∫ sen x dx = -cos x + C
- ∫ cos x dx = sen x + C
---
- Máximo divisor comum (MDC):  
  gcd(a, b) = gcd(b, a % b)

- Mínimo múltiplo comum (MMC):  
  lcm(a, b) = (a * b) / gcd(a, b)

- Número de divisores de n:
  - Se n = p1^a1 * p2^a2 * ... * pk^ak  
  - Então: total = (a1 + 1)(a2 + 1)...(ak + 1)

- Número de dígitos de um número n na base 10:  
  floor(log10(n)) + 1
  
- Use XOR para jogos como Nim.
- Em problemas de DP, busque subproblemas e recursões.
- Em análise combinatória, defina se ordem importa e se há repetição.
- Use séries para estimar crescimento (ex: log(n), n log n, n²).

## Sort em arrays dinâmicos usando funções customizadas:
```cpp
    bool comp (int a, int b) {
        // comp deve retornar true caso a deva vir antes de b
        return a < b;
    }
    vector<int> v;
    sort(v.begin(), v.end(), comp);

    //usando lambda function
    sort(v.begin(), v.end(), [](auto &a, auto &b){
        return a < b;
    });
```
## Sort em priority queue
```cpp
    // Maior primeiro
    priority_queue<int, vector<int>> pq;
    // Menor primeiro
    priority_queue<int, vector<int>, greater<int>> pq;

    // Customizada
    auto cmp = [](const int& a, const int& b) {
        return a.custo > b.custo; // > = Menor no topo ; < = Maior no topo
    };

    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    
```
## GCD e LCM (MDC e MMC) em C++:
```cpp
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
```

## Encontrar os N primeiros primos em O(N log log N):
```cpp
vector<bool> prime(N+1, true);
prime[0] = prime[1] = false;
for (int i=2; i*i<=N; i++)
    if (prime[i])
        for (int j=i*i; j<=N; j+=i)
            prime[j] = false;
```
# Estruturas de dados em C++:
## Union-Find
```cpp
int parent[N], sz[N]; // parent[i] comeca com i

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}
void unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
}
```
## Binary Indexed Tree (BIT) 1-indexada
```cpp
int bit[N+1];

void add(int i, int v) {
    for (; i <= N; i += i & -i) bit[i] += v;
}

int sum(int i) {
    int s = 0;
    for (; i > 0; i -= i & -i) s += bit[i];
    return s;
}
```
## Segment Tree (Soma de intervalos)
```cpp
int st[4*N], a[N];
// para minimo em intervalos, trocar onde tem + por min
// para minimo em intervalos, trocar onde tem + por max
void build(int p,int l,int r){
    if(l==r) st[p]=a[l];
    else{
        int m=(l+r)/2;
        build(2*p,l,m);
        build(2*p+1,m+1,r);
        st[p]=st[2*p]+st[2*p+1];
    }
}
int query(int p,int l,int r,int i,int j){
    if(j<l||r<i) return 0;
    if(i<=l&&r<=j) return st[p];
    int m=(l+r)/2;
    return query(2*p,l,m,i,j)+query(2*p+1,m+1,r,i,j);
}
void update(int p,int l,int r,int idx,int val){
    if(l==r) st[p]=val;
    else{
        int m=(l+r)/2;
        if(idx<=m) update(2*p,l,m,idx,val);
        else update(2*p+1,m+1,r,idx,val);
        st[p]=st[2*p]+st[2*p+1];
    }
}
```
## Grafos:
## DFS
```cpp
void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u])
        if (!vis[v]) dfs(v);
}
```
## BFS
```cpp
void bfs(int s) {
    queue<int> q; q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u])
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
}
```
## Dijkstra
```cpp
void dijkstra(int s) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[s] = 0; pq.push({0,s});
    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v,w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d+w;
                pq.push({dist[v],v});
            }
        }
    }
}
```
## Tempo de entrada e saída (Árvores)
```cpp
int tin[N], tout[N], timer=0;
void dfs(int u,int p){
    tin[u]=++timer;
    for(int v:adj[u]) if(v!=p) dfs(v,u);
    tout[u]=++timer;
}
bool is_ancestor(int u,int v){ 
    return tin[u]<=tin[v] && tout[u]>=tout[v]; 
}
```
## Conjuntos (Bitmask)
```cpp
int mask = 0;           // conjunto vazio
mask |= (1<<i);         // adiciona elemento i
mask &= ~(1<<i);        // remove elemento i
if(mask & (1<<i)) ...   // checa se i pertence
int size = __builtin_popcount(mask); // tamanho do conjunto
int lsb = mask & -mask; // bit menos significativo (último inserido)
int idx = __builtin_ctz(mask); // posição do bit menos significativo

// subconjuntos de n elementos
for(int mask=0; mask<(1<<n); mask++) {
    // processar subconjunto mask
}

// subconjuntos do cojunto mask
for(int sub=mask; sub; sub=(sub-1)&mask){
    // sub é subconjunto de mask
}

#include <bitset>
bitset<1000> b;   // conjunto com até 1000 elementos
b.set(i);         // adiciona i
b.reset(i);       // remove i
b.flip(i);        // inverte i
b[i];             // acessa i (0 ou 1)
b.count();        // quantidade de elementos
b.any();          // existe algum elemento?
b.none();         // conjunto vazio?

bitset<1000> a, c;
c = a & b;   // interseção
c = a | b;   // união
c = a ^ b;   // diferença simétrica

```
## Backtracking
```cpp
vector<int> cur;
vector<int> usado(n+1,0);
// permutacao de 1 ate n
void backtrack(int n){
    if((int)cur.size()==n){
        // solução encontrada
        for(int x:cur) cout<<x<<" ";
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(!usado[i]){
            usado[i]=1;
            cur.push_back(i);
            backtrack(n);
            cur.pop_back();
            usado[i]=0;
        }
    }
}
```
# Multiset
```cpp
// Multiset – STL
#include <set>
multiset<int> ms;

// Inserir elementos
ms.insert(5);
ms.insert(3);
ms.insert(5); // permite duplicatas

// Remover um elemento (apenas uma ocorrência)
ms.erase(ms.find(5)); 

// Contar ocorrências de um valor
int count5 = ms.count(5);

// Iterar
for(auto x : ms) { 
    cout << x << " "; 
}

// Acessar menor/maior elemento
int menor = *ms.begin();
int maior = *ms.rbegin();

// Encontrar um elemento
auto it = ms.find(3); // retorna iterator ou ms.end() se não existir

// Lower bound / Upper bound
auto it_lower = ms.lower_bound(3); // >= 3
auto it_upper = ms.upper_bound(3); // > 3
```
## Matematica <cmath>
```cpp
// Constantes
M_PI      // π (3.14159...)
M_E       // e (2.71828...)
const double EPS = 1e-9; // precisão para comparações de double

// Potência, raiz e logaritmos
pow(x, y);   // x^y
sqrt(x);     // raiz quadrada
cbrt(x);     // raiz cúbica
hypot(x,y);  // sqrt(x^2 + y^2)
log(x);      // log_e(x)
log10(x);    // log_10(x)
log2(x);     // log_2(x)
exp(x);      // e^x

// Trigonometria
sin(x); cos(x); tan(x);        // radianos
asin(x); acos(x); atan(x);      // arco-seno/cosseno/tangente
atan2(y,x);                     // trata quadrante correto

// Conversão graus ↔ radianos
double toRad(double deg) { return deg * M_PI / 180.0; }
double toDeg(double rad) { return rad * 180.0 / M_PI; }

// Arredondamento
floor(x); ceil(x); round(x); trunc(x);

// Valor absoluto e sinal
abs(x);      // inteiro
fabs(x);     // double
copysign(x,y); // valor |x| com sinal de y

// Mínimo e Máximo
min(a,b); max(a,b);
fmin(a,b); fmax(a,b); // versão double

// Resto
fmod(a,b);       // resto de divisão decimal
remainder(a,b);  // resto arredondado

// Comparação de doubles
bool igual(double a, double b) { return fabs(a - b) < EPS; }
bool menor(double a, double b) { return a < b - EPS; }
bool maior(double a, double b) { return a > b + EPS; }

// Distância entre dois pontos
struct Point { double x, y; };
double dist(Point a, Point b) { return hypot(a.x - b.x, a.y - b.y); }

// Produto escalar e ângulo entre vetores
double dot(Point a, Point b) { return a.x*b.x + a.y*b.y; }
double angle(Point a, Point b) { return acos(dot(a,b)/(hypot(a.x,a.y)*hypot(b.x,b.y))); } // rad

// Produto vetorial (2D)
double cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
// sinais: >0 -> b à esquerda, <0 -> b à direita, =0 -> colinear

// Colinearidade de 3 pontos
bool colinear(Point a, Point b, Point c) {
    return fabs(cross(b-a, c-a)) < EPS;
}

// Normalizar ângulo [0,2π)
double normAngle(double ang) {
    ang = fmod(ang, 2*M_PI);
    if(ang < 0) ang += 2*M_PI;
    return ang;
}
```

| Complexidade | Máximo `n` aproximado | Observações |
|--------------|----------------------|-------------|
| O(1)         | qualquer             | Operação simples, constante |
| O(log n)     | 10^18                | Logaritmo cresce muito devagar |
| O(n)         | 10^8                 | Linear, 1 segundo ≈ 10^8 operações |
| O(n log n)   | 2×10^6               | Ex.: sorting 2 milhões de elementos |
| O(n^2)       | 10^4                 | Quadrático, cuidado com loops aninhados |
| O(n^3)       | 400                  | Cúbico, só para n pequeno |
| O(n^4)       | 50                   | Muito pesado, raramente usado |
| O(2^n)       | 20                   | Ex.: backtracking / subsets |
| O(3^n)       | 15                   | Problemas de recursão com 3 escolhas |
| O(n!)        | 10                   | Fatorial, só para casos muito pequenos |
