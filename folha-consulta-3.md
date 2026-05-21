### Time (ms)
Juízes online e o BOCA desconsideram **cerr** (character error), para debug, logs e medir erro. Colocar dentro da main():

```c
auto start = chrono::high_resolution_clock::now();
// código
auto end = chrono::high_resolution_clock::now();
cerr << chrono::duration<double, milli>(end - start).count() << " ms\n";
```
**OBS:** não pode inserir a mão, porque o time já considera. Criar um *input.txt* e rodar:
```bash
./a.out < input.txt
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

