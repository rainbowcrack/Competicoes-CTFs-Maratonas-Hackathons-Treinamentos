## Exemplo de Template
Pode tirar o solve() e colocar tudo na main()
```cpp
#include <bits/stdc++.h>
using namespace std;

// Atalhos de tipos
using ll = long long;
using ull = 
using vi = vector<int>;
using pii = pair<int, int>;

// Macros úteis
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

void solve() {
    // Código da solução aqui
}

int main() {
    fast_io;
    int t = 1;
    // cin >> t; // Descomente se houver múltiplos casos de teste
    while(t--) solve();
    return 0;
}
```
### N-templates (Criar um template para todos os problemas)
```bash
for c in {a..n}; do cp template.cpp "$c.cpp"; done
```
**ALERTA:** só se você não conseguir usar esse comando, trago 2 alternativos:
```bash
for c in a b c d e f g h i j k l m n; do cp template.cpp "$c.cpp"; done
```
Ou
```bash
for i in $(seq 1 14); do cp template.cpp "prob$i.cpp"; done
```
Ou (pior caso, útlima opção)
```bash
cp template.cpp a.cpp && cp template.cpp b.cpp && cp template.cpp c.cpp && cp template.cpp d.cpp && cp template.cpp e.cpp && cp template.cpp f.cpp && cp template.cpp g.cpp && cp template.cpp h.cpp && cp template.cpp i.cpp && cp template.cpp j.cpp && cp template.cpp k.cpp && cp template.cpp l.cpp && cp template.cpp m.cpp && cp template.cpp n.cpp
```
### Copia de Template
Cria o template:
```bash
touch template.cpp
vim template.cpp
```
Faz cópia do template:
```bash
cp template.cpp a.cpp
```
Mostrar a numeração de linhas no vim **:set number**

## Alerta: não use endl
endl quebra a linha, força o SO para limpar o buffer (flush) e pode dar TLE
```cpp
cout << ans << "\n"
```
## Grafos
### BFS (Busca em Largura) - Menor caminho em grafos sem peso
```cpp
vi dist(n, INF);
queue<int> q;

dist[origem] = 0;
q.push(origem);

while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int v : adj[u]) {
        if(dist[v] == INF) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}
```
### Dijkstra - Menor caminho com pesos positivos O(M log N)
```cpp
vi dist(n, INF);
priority_queue<pii, vector<pii>, greater<pii>> pq; // {distancia, vertice}

dist[origem] = 0;
pq.push({0, origem});

while(!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if(d > dist[u]) continue;
    
    for(auto [v, peso] : adj[u]) {
        if(dist[u] + peso < dist[v]) {
            dist[v] = dist[u] + peso;
            pq.push({dist[v], v});
        }
    }
}
```
## Matemática e Teoria dos Números
### Máximo Divisor Comum (GCD)
Da lib **#include <numeric>**.
```cpp
ll g = v[0];
for (int i = 1; i < n; i++) {
    g = gcd(g, v[i]);
}
```
Caso queira fazer *na mão* (não recomendo)
```cpp
ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
```
### Mínimo Múltiplo Comum (LCM) 
Da lib **#include <numeric>**. Problema da acumulada, pode dar overflow 
```cpp
ll g = v[0];
for (int i = 1; i < n; i++) {
    g = lcm(g, v[i]); // Atualiza 'g' com o MMC acumulado
}
```
Caso queira fazer *na mão* (não recomendo)
```cpp
ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}
```
### Exponenciação Rápida (Sem Módulo)
```cpp
ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
```
### Aritmética Modular
```cpp
const int MOD = 1e9 + 7; // Modulo padrão da maioria dos problemas

// Soma modular: (a + b) % MOD
ll mod_add(ll a, ll b, ll m = MOD) {
    return (a % m + b % m) % m;
}

// Multiplicação modular: (a * b) % MOD
ll mod_mul(ll a, ll b, ll m = MOD) {
    return ((a % m) * (b % m)) % m;
}

// Subtração modular: (a - b) % MOD (Trata o caso do resultado ser negativo no C++)
ll mod_sub(ll a, ll b, ll m = MOD) {
    return ((a % m - b % m) % m + m) % m;
}

// Divisão modular: (a / b) % MOD
// Só funciona se 'm' for um número primo (como 1e9+7). Usa o Pequeno Teorema de Fermat.
ll mod_div(ll a, ll b, ll m = MOD) {
    // b^(-1) % m é igual a binpow(b, m - 2, m)
    ll inv = binpow(b, m - 2, m); 
    return mod_mul(a, inv, m);
}
```
### Crivo de Eratóstenes
```cpp
// vector<bool> global para evitar estouro de memória
const int MAXN = 1e7; 
vector<bool> is_prime(MAXN + 1, true);

void crivo(int n) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
```
## BÔNUS
### Maratona Feminina de Programação
```cpp
// asumindo o mdc total e dividir por cada 
    int g = paises[0];
    for(int i = 1; i < N; i++){
        g = gcd(g, paises[i]);
    }

    for(int j = 0; j < N; j++){
        ans += paises[j]/g;
    }
```



