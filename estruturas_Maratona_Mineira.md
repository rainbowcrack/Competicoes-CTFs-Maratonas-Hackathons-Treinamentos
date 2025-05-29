# Estruturas de Dados em C++ para a Maratona Mineira de Programação - 2025
## Dicas
* Para chamar as **principais** bibliotecas em C++ e automatizar o **std**, utilize:
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

    for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;

    // Iterar com for-each
    for (int x : a) cout << x << " ";
    cout << endl;

    // Ordenar
    sort(a.begin(), a.end()); // crescente
    reverse(a.begin(), a.end()); // decrescente

    // Buscar com lower_bound (binária em vetor ordenado)
    vector<int> b = {10, 20, 30, 40};
    int pos = lower_bound(b.begin(), b.end(), 25) - b.begin();
    cout << "Lower bound para 25: posição " << pos << endl;
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

## Set
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

## Map e HashMap
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
    // Output: (1,apple,2.5) (2,apricot,3.1) (2,banana,1.99)
    return 0;
}
