# Desafio da Sala 03
## dica.hmtl
* [SYS] Iniciando console do sistema NovaFlux Reactor v2.7.9
* [OK ] Módulo de refrigeração operacional
* [OK ] Setor C - Painel Supervisório Online
* [INFO] Transmissão ativa no barramento ModBus-TCP
* [ALERTA] PLC: 3.92.224.79 PORTA 90**
* [LOG] Requisição GET /status_report de origem externa
* [DICA] Acesse o endpoint do dispositivo para obter respostas da automação. 💡
* Você sabe como descobrir o que roda em uma porta específica, não sabe? 😏
* [SYS] Fim da sessão de diagnóstico. Operador desconectado. 

## Como pegar a FLAG
Use a ferramenta nmap para escanear a porta do ip da maquina fornecida, em seguida use telnet ou netcat para se conectar ao servico pela porta:

* nmap -p 9000-9999 3.92.224.79 -T4
* telnet -4 3.92.224.79 9090
* print(FLAG)

**FLAG{RCE_OWNED_999}**
