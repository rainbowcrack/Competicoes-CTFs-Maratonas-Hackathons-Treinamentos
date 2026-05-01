| Problema           | Melhor ferramenta |
| ------------------ | ----------------- |
| Detectar duplicata | `unordered_set`   |
| Contar frequência  | `unordered_map`   |
| Majority element   | Boyer-Moore       |
| Par cancelando     | XOR               |
| Comparar vizinhos  | sort              |

## SET
Implementado como árvore balanceada (Red-Black Tree), sempre mantém os elementos ordenados. <br>
**Inserção:** O(log n), **Busca:** O(log n) e **Remove:** O(log n)

## unordered_set
Implementado com hash table, NÃO mantém ordem. <br>
**Inserção:** O(1) médio, **Busca:** O(1) médio, **Remove:** O(1) médio
## unordered_map
hash table sem ordenação, enquanto map é por árvore e possui ordenação

falta boyer-moore, distancia de mannhatan, dijstra, dfs, bfs, floyd-walsshal
