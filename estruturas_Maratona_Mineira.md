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
## Arrays (sequenciais e dinâmicos):
```c
    vector<int> v;

    // Inserção de elementos no final
    v.push_back(10); // [10]
    v.push_back(20); // [10, 20]

    // Acesso por índice
    cout << "v[0]: " << v[0] << endl; // 10

    // Tamanho do vetor
    cout << "Tamanho: " << v.size() << endl; // 2

    // Inserção em posição específica
    v.insert(v.begin() + 1, 15); // [10, 15, 20]

    // Remoção de elemento por posição
    v.erase(v.begin()); // remove o 10 → [15, 20]

    // Remoção do último elemento
    v.pop_back(); // remove 20 → [15]

    // Verificar se está vazio
    if (!v.empty()) {
        cout << "Vetor não está vazio" << endl;
    }

    // Redimensionar o vetor (aumenta ou reduz o tamanho)
    v.resize(4); // agora tem 4 elementos: [15, 0, 0, 0]

    // Limpar todos os elementos
    v.clear(); // agora está vazio

    // Preencher vetor com n elementos iguais
    vector<int> a(5, 42); // [42, 42, 42, 42, 42]

    // Iterar com for tradicional
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

## Queue (Fila)

## Set

## Map e HashMap

## Árvore Binária (BTS) e Busca Binária
