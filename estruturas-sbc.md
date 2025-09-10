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
<img width="700" height="513" alt="image" src="https://github.com/user-attachments/assets/b16d5dea-eaa4-4e6f-aa5f-ac5dc2e8d929" />

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
