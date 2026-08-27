# Introdução à Teoria de Jogos
"Von Neumann iniciou os estudos da teoria dos jogos para dois jogadores, jogos de soma zero e equilíbrios, mais tarde John Nash trabalhou com mais de dois jogadores, estratégias mistas e aprimorou o equilíbrio."

## Sumário
- Matrizes de Payoff
- Jogos de soma zero
- Ponto de sela
- Maximin/Minimax de Von Neumann
- Equilíbrio de Nash
- Estratégias Mistas
- Dominância
- Dilema do Prisioneiro

---

## Matrizes de Payoff

Em jogos estratégicos, as decisões dos jogadores são simuladas por uma **matriz de payoff**, onde:

- As **linhas** representam as estratégias do Jogador 1.
- As **colunas** representam as estratégias do Jogador 2.
- Cada célula da matriz indica o resultado (payoff) para os jogadores quando combinam suas estratégias.

Por exemplo, para dois jogadores, uma matriz 2x2 pode ser:

|       | C1      | C2      |
|-------|---------|---------|
| **L1**| (3, 2)  | (1, 4)  |
| **L2**| (0, 0)  | (2, 1)  |

Aqui (3,2) indica payoff 3 para jogador 1 e 2 para jogador 2 quando jogam L1 e C1 respectivamente.

---

## Jogos de Soma Zero

Jogos de soma zero são um tipo especial de jogos em que o ganho de um jogador é exatamente a perda do outro. Ou seja, a soma dos payoffs dos jogadores é sempre zero!
Um exemplo é o xadrez, em que se o jogador de peças brancas ganhar resulta em derrota imediata para o jogador peças pretas.

### Características:

- Dois jogadores (tipicamente).
- Os interesses são estritamente opostos.
- O que um ganha, o outro perde.

### Exemplo clássico:

|          | Jogador 2: Esquerda | Jogador 2: Direita |
|----------|---------------------|--------------------|
| **Jogador 1: Cima**   | (1, -1)             | (-1, 1)            |
| **Jogador 1: Baixo**  | (-1, 1)             | (1, -1)            |

Nesse jogo:

- Se o Jogador 1 ganha 1 ponto, o Jogador 2 perde 1 ponto, e vice-versa.
- O objetivo é maximizar o ganho próprio, minimizando o do adversário.

Para qualquer caso das células, a soma será (+1) e (-1) que resulta em 0.

### Teorema fundamental (von Neumann):

Para jogos de soma zero com estratégias finitas, existe um par de estratégias mistas que formam um **equilíbrio de Nash** e garantem um valor do jogo para cada jogador.

---

## Maximin/Minimax de Von Neumann

- **Maximin:** O jogador busca a estratégia que maximize seu ganho mínimo possível (mais seguro).
- **Minimax:** O jogador busca minimizar a perda máxima possível.

No caso de jogos de soma zero, Von Neumann provou que existe um valor de jogo onde maximin = minimax, garantindo um **equilíbrio ótimo** para ambos os jogadores.

---
## Ponto de Sela

O **ponto de sela** é um conceito fundamental em jogos de matriz (jogos de soma zero e jogos em geral).

### Definição

- É um elemento da matriz de payoff que é **o menor valor da sua linha** e **o maior valor da sua coluna**.
- Representa uma situação estável onde nenhum jogador tem incentivo para mudar sua estratégia unilateralmente.

### Interpretação

- Para o jogador das linhas (Jogador 1), o ponto de sela é o melhor que ele pode garantir, assumindo o pior cenário (maximin - maximize o mínimo ganho).
- Para o jogador das colunas (Jogador 2), é o pior que ele pode receber, assumindo que o adversário escolherá o que lhe causa maior prejuízo (minimax - minimize a perda).

### Consequência

- Se existir um ponto de sela, ele representa um **equilíbrio em estratégias puras**.
- Ou seja, ambos os jogadores escolhem suas estratégias correspondentes ao ponto de sela e nenhum deles pode melhorar seu resultado mudando apenas sua própria estratégia.

### Exemplo simples:

|       | C1 | C2 | C3 |
|-------|----|----|----|
| **L1**| 3  | 2  | 4  |
| **L2**| 1  | 5  | 0  |
| **L3**| 2  | 4  | 3  |

- Menores valores por linha:  
  - L1: 2  
  - L2: 0  
  - L3: 2  
- Maiores valores por coluna:  
  - C1: 3  
  - C2: 5  
  - C3: 4  

Aqui, o valor **2** na posição (L3, C2) não é ponto de sela, porque 2 não é o maior da coluna 2 (que é 5).

Se acharmos uma célula que seja o menor da linha e maior da coluna simultaneamente, esse é o **ponto de sela**.

---

## Equilíbrio de Nash

O conceito de **Equilíbrio de Nash** é central na teoria dos jogos:

- É um perfil de estratégias onde **nenhum jogador tem incentivo em mudar sua estratégia unilateralmente**, dado que os outros jogadores não mudam as suas.
- Em outras palavras, é uma situação estável onde todos fazem o melhor possível considerando as escolhas dos outros.

---

## Estratégias Mistas

- Em vez de escolher uma única estratégia pura, um jogador pode escolher uma **distribuição de probabilidades** sobre suas estratégias possíveis — isso é uma **estratégia mista**.
- Estratégias mistas permitem:
  - Evitar previsibilidade.
  - Possibilidade de existência de equilíbrio quando nenhum equilíbrio puro existe.
- O equilíbrio de Nash sempre existe em estratégias mistas (Teorema de Nash).

---

## Dominância

- Uma estratégia **domina** outra se sempre resulta em payoff melhor ou igual para o jogador, **independentemente da estratégia do oponente**.
- Eliminar estratégias dominadas simplifica o jogo, reduzindo a matriz e facilitando a análise.
- Existem dois tipos:
  - **Dominância estrita:** Sempre estritamente melhor.
  - **Dominância fraca:** Melhor ou igual, e em algum caso estritamente melhor.

---

## Dilema do Prisioneiro

Um clássico jogo que ilustra conflito entre interesse individual e coletivo:

|           | Cooperar | Tramar |
|-----------|----------|--------|
| **Cooperar** | (3,3)    | (0,5)  |
| **Tramar**   | (5,0)    | (1,1)  |

- Se ambos cooperam, ganham 3 cada (melhor para o coletivo).
- Mas a estratégia dominante para cada um é tramar (maximizar benefício individual).
- Resultado: ambos traem e ficam com payoff menor (1,1) — **equilíbrio de Nash**, porém não ótimo socialmente.

---

## Referências

- Vicente, R. "Introdução à Teoria dos Jogos" - https://www.ime.usp.br/~rvicente/IntroTeoriaDosJogos.pdf  
- Osborne, M. "An Introduction to Game Theory"  
- Myerson, R. "Game Theory: Analysis of Conflict"  

---
