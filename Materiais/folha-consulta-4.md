### Fluxo de Dinic
```cpp
struct Dinic {
    struct Edge {
        int to, rev, cap;
    };

    int n;
    vector<vector<Edge>> g;
    vector<int> level, ptr;

    Dinic(int n) : n(n), g(n), level(n), ptr(n) {}

    void addEdge(int v, int u, int cap) {
        Edge a{u, (int)g[u].size(), cap};
        Edge b{v, (int)g[v].size(), 0};
        g[v].push_back(a);
        g[u].push_back(b);
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (auto &e : g[v]) {
                if (e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }

    int dfs(int v, int t, int pushed) {
        if (!pushed) return 0;
        if (v == t) return pushed;

        for (int &cid = ptr[v]; cid < (int)g[v].size(); cid++) {
            Edge &e = g[v][cid];

            if (e.cap > 0 && level[e.to] == level[v] + 1) {
                int tr = dfs(e.to, t, min(pushed, e.cap));

                if (tr) {
                    e.cap -= tr;
                    g[e.to][e.rev].cap += tr;
                    return tr;
                }
            }
        }
        return 0;
    }

    int maxflow(int s, int t) {
        int flow = 0;

        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);

            while (int pushed = dfs(s, t, INT_MAX))
                flow += pushed;
        }

        return flow;
    }
};
```
**Uso:**
```cpp
Dinic d(n);

d.addEdge(u, v, capacidade);

cout << d.maxflow(s, t) << '\n';

```
---
### DSU (Disjoint Set Union)
```cpp
struct DSU {
    vector<int> p, sz;

    DSU(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (sz[a] < sz[b]) swap(a, b);

        p[b] = a;
        sz[a] += sz[b];

        return true;
    }
};
```
**Uso:**
```cpp
DSU dsu(n);

dsu.unite(a, b);

if (dsu.find(a) == dsu.find(b))
    cout << "mesmo componente\n";
```
---
### SCC (Strongly Connected Components) - Kosaraju (O(V + E))
```cpp
vector<vector<int>> g, gr;
vector<int> vis, ordem, comp;

void dfs1(int v) {
    vis[v] = 1;
    for (int u : g[v])
        if (!vis[u])
            dfs1(u);
    ordem.push_back(v);
}

void dfs2(int v, int c) {
    comp[v] = c;
    for (int u : gr[v])
        if (comp[u] == -1)
            dfs2(u, c);
}

void kosaraju(int n) {
    vis.assign(n, 0);
    comp.assign(n, -1);

    for (int v = 0; v < n; v++)
        if (!vis[v])
            dfs1(v);

    reverse(ordem.begin(), ordem.end());

    int c = 0;
    for (int v : ordem)
        if (comp[v] == -1)
            dfs2(v, c++);
}
```
**Uso:**
```cpp
// primeiro
g[u].push_back(v);
gr[v].push_back(u);
// comp[u] == comp[v] significa que u e v pertencem a mesma SCC
kosaraju(n);
```
## Complexidade
| Algoritmo / Estrutura | Complexidade |
|---|---:|
| BFS | `O(N + M)` |
| DFS | `O(N + M)` |
| Dijkstra | `O((N + M) log N)` |
| Floyd-Warshall | `O(N³)` |
| Kosaraju | `O(N + M)` |
| Dinic | `O(N² M)` |
| DSU | `O(α(N))` amortizado |
| GCD | `O(log min(a,b))` |
| Fast Power | `O(log B)` |
| Crivo | `O(N log log N)` |
| Binary Search | `O(log N)` |
| Sort | `O(N log N)` |
| Vector acesso | `O(1)` |
| Vector `push_back` | `O(1)` amortizado |
| Vector `insert/erase` | `O(N)` |
| Set/Map | `O(log N)` |
| Unordered Map/Set | `O(1)` médio |

Fenwick:
    Mais simples
    Menos memória
    Soma/prefixo + update
    O(log N)

Segment Tree:
    Mais geral
    Soma/min/max/gcd/etc.
    Range query + update
    Lazy propagation
    O(log N)

### Coloração por BFS (verificação de bipartidos) - O(N + M)
```cpp
vector<int> color(n, -1);

bool bipartite = true;

for (int s = 0; s < n; s++) {
    if (color[s] != -1) continue;

    queue<int> q;
    q.push(s);
    color[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = color[u] ^ 1;
                q.push(v);
            }
            else if (color[v] == color[u]) {
                bipartite = false;
            }
        }
    }
}
```
### Soma Segment-tree
```cpp
struct SegTree {
    int n;
    vector<ll> st;

    SegTree(vector<ll>& a) {
        n = a.size();
        st.resize(4 * n);
        build(a, 1, 0, n - 1);
    }

    void build(vector<ll>& a, int p, int l, int r) {
        if (l == r) {
            st[p] = a[l];
            return;
        }

        int m = (l + r) / 2;

        build(a, 2*p, l, m);
        build(a, 2*p+1, m+1, r);

        st[p] = st[2*p] + st[2*p+1];
    }

    void update(int p, int l, int r, int idx, ll val) {
        if (l == r) {
            st[p] = val;
            return;
        }

        int m = (l + r) / 2;

        if (idx <= m)
            update(2*p, l, m, idx, val);
        else
            update(2*p+1, m+1, r, idx, val);

        st[p] = st[2*p] + st[2*p+1];
    }

    ll query(int p, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
            return st[p];

        int m = (l + r) / 2;

        return query(2*p, l, m, ql, qr)
             + query(2*p+1, m+1, r, ql, qr);
    }

    void update(int idx, ll val) {
        update(1, 0, n-1, idx, val);
    }

    ll query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};
```
### Fenwick Tree
```cpp
struct Fenwick {
    int n;
    vector<ll> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, ll val) {
        for (++idx; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    ll sum(int idx) {
        ll res = 0;

        for (++idx; idx > 0; idx -= idx & -idx)
            res += bit[idx];

        return res;
    }

    ll query(int l, int r) {
        if (l > r) return 0;
        return sum(r) - (l ? sum(l - 1) : 0);
    }
};
````
**Uso:**
```cpp
Fenwick fw(n);

fw.add(3, 10); // a[3] += 10
fw.add(5, 7);  // a[5] += 7

cout << fw.sum(5) << '\n';      // soma [0..5]
cout << fw.query(2, 5) << '\n'; // soma [2..5]
```
### DFS - O(N + M)
```cpp
void dfs(int u) {
    vis[u] = 1;

    for (int v : adj[u]) {
        if (!vis[v])
            dfs(v);
    }
}
```
**Uso:**
```cpp
vector<vector<int>> adj(n);
vector<int> vis(n, 0);

dfs(0);
```
### BFS - O(N + M)
```cpp
void bfs(int s) {
    queue<int> q;

    vis[s] = 1;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}
```
**Uso:**
```cpp
vector<vector<int>> adj(n);
vector<int> vis(n, 0);

bfs(0);
```
### Floyd-Warshall - O(N³)
```cpp
vector<vector<ll>> dist(n, vector<ll>(n, INF));

for (int i = 0; i < n; i++)
    dist[i][i] = 0;

for (auto [u, v, w] : edges)
    dist[u][v] = min(dist[u][v], (ll)w);

for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dist[i][k] != INF && dist[k][j] != INF)
                dist[i][j] = min(dist[i][j],
                                 dist[i][k] + dist[k][j]);
```
### KMP - O(N + M)
```cpp
vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n);

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            j++;

        pi[i] = j;
    }

    return pi;
}
```
### LCA - O(log N)
encontrar o nó mais profundo que é ancestral comum a dois nós especificados
```cpp
const int LOG = 20;

vector<vector<int>> adj;
vector<array<int, LOG>> up;
vector<int> depth;

void dfs(int u, int p) {
    up[u][0] = p;

    for (int j = 1; j < LOG; j++)
        up[u][j] = up[up[u][j-1]][j-1];

    for (int v : adj[u]) {
        if (v == p) continue;

        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);

    int diff = depth[u] - depth[v];

    for (int j = 0; j < LOG; j++)
        if (diff & (1 << j))
            u = up[u][j];

    if (u == v) return u;

    for (int j = LOG - 1; j >= 0; j--) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0];
}
```
### Bellman-Ford - O(NM)
```cpp
vector<ll> dist(n, INF);
dist[s] = 0;

for (int i = 0; i < n - 1; i++) {
    bool changed = false;

    for (auto [u, v, w] : edges) {
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            changed = true;
        }
    }

    if (!changed) break;
}
```
### Topological Sort (Kahn com BFS) - O(N + M)
```cpp
vector<int> indeg(n);

for (int u = 0; u < n; u++)
    for (int v : adj[u])
        indeg[v]++;

queue<int> q;

for (int i = 0; i < n; i++)
    if (indeg[i] == 0)
        q.push(i);

vector<int> topo;

while (!q.empty()) {
    int u = q.front();
    q.pop();

    topo.push_back(u);

    for (int v : adj[u]) {
        if (--indeg[v] == 0)
            q.push(v);
    }
}

// se topo.size() < n, existe ciclo
```
