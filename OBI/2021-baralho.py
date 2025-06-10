# faz a leitura
s = input()

# seta o baralho
baralho{
    'C': set(),
    'E': set(),
    'U': set(),
    'P': set()
}

duplicata{
    'C': False;
    'E': False;
    'U': False;
    'P': False;
}

for i in range(0, len(s), 3):
    carta = s[i:i+3]
    naipe = carta[2]
    valor = int(carta[:2])
    
    # ve se esta duplicado
    if naipe in baralho[naipe] naipe++;
    
def resultado(naipe_char):
    total_cartas = 13 - naipe
    

