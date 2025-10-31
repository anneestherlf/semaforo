# Projeto: Semáforo para Controle de Tráfego

Este repositório contém a entrega do desenvolvimento de um protótipo de semáforo para controle de fluxo (ponderada).

O projeto é dividido na montagem física do circuito em protoboard e na programação da lógica de temporização das luzes.

**Aluna Anne Esther Lins Figueirôa - T18.**

# Demonstração (Vídeo)

O vídeo abaixo apresenta a montagem física do semáforo em funcionamento na protoboard. Apareço na gravação para comprovar a autoria, e o ciclo de temporização (vermelho, verde, amarelo) é demonstrado conforme os requisitos da atividade (LEDs acendendo e apagando conforme o código).

**Link para o vídeo:**  
- LINK DO VIDEO

# Parte 1: Montagem Física do Semáforo

A montagem foi realizada buscando simular um semáforo veicular padrão (vermelho, amarelo, verde).

## Componentes Utilizados

| Componente         | Especificação       | Quantidade | Justificativa                                                               |
|--------------------|---------------------|------------|-----------------------------------------------------------------------------|
| Microcontrolador   | Arduino Uno  | 1          | Responsável por executar o código e controlar os pinos digitais.            |
| LED Vermelho       | Difuso       | 1          | Representa a fase "PARE" do semáforo.                                       |
| LED Amarelo        | Difuso         | 1          | Representa a fase "ATENÇÃO" do semáforo.                                    |
| LED Verde          | Difuso        | 1          | Representa a fase "SIGA" do semáforo.                                       |
| Resistores         | -          | 3          | Protege cada LED limitando a corrente elétrica vinda dos pinos do Arduino.  |
| Protoboard         | - | 1        | Placa de ensaio para montar o circuito sem necessidade de solda.            |
| Jumper Wires       | Macho-Macho         | ~6         | Fios para realizar as conexões entre o Arduino e a protoboard.              |

# Tutorial de Montagem e Conexões

O circuito foi montado de forma a garantir a clareza das conexões, com os LEDs organizados na ordem correta (vermelho no topo, verde na base).

**Justificativa e Passo a Passo:**

- IMAGENS DO ESQUEMA DE MONTAGEM EM CADA PASSO, passo a passo (1 imagem pra cada passo)

1. **Posicionamento dos LEDs:** Os LEDs foram posicionados na protoboard, respeitando a ordem (Vermelho, Amarelo, Verde).
2. **Identificação dos Terminais:** Cada LED possui dois terminais: o Anodo (perna mais longa, positiva) e o Catodo (perna mais curta, negativa).
3. **Conexão do Anodo (Positivo):** O terminal Anodo de cada LED foi conectado a um pino de saída digital do Arduino, conforme a tabela:
   - LED Vermelho → Pino Digital 13
   - LED Amarelo → Pino Digital 12
   - LED Verde → Pino Digital 11
4. **Conexão do Catodo (Negativo) e Resistor:** O terminal Catodo de cada LED foi conectado a um resistor.
5. **Conexão ao GND (Terra):** A outra extremidade de cada um dos três resistores foi conectada ao barramento de "Terra" (GND) da protoboard.
6. **Alimentação GND:** O pino GND do Arduino foi conectado ao barramento de "Terra" da protoboard para fechar o circuito.

**Por que usar resistores?** O resistor é essencial para limitar a corrente que flui do pino digital do Arduino (que opera a 5V) para o LED. Sem ele, o LED receberia uma corrente excessiva e queimaria instantaneamente.

# Parte 2: Programação e Lógica do Semáforo

O código-fonte foi desenvolvido na IDE do Arduino (baseado em C++) e segue a lógica de temporização exigida.
1. **Luz Vermelha:** Acesa por 6 segundos (Verde e Amarelo apagados).
2. **Luz Verde:** Acesa por 4 segundos (Vermelho e Amarelo apagados).
3. **Luz Amarela:** Acesa por 2 segundos (Vermelho e Verde apagados).

## Código-Fonte

O código completo pode ser encontrado neste repositório no arquivo:  
- LINK AQUI PRO ARQUIVO OU APONTAR PRA RAIZ

Abaixo está o trecho principal da lógica (loop), que garante a sequência e temporização:

```cpp
COLOCAR TRECHO AQUI
```
## Parte 3: Avaliação de Pares
Conforme os critérios da atividade, o projeto foi avaliado por, no mínimo, dois colegas. Seguem os resultados das avaliações.

### Avaliador 1
- **Nome completo:**
- **Feedback/notas:**

- ### Avaliador 2
- **Nome completo:**
- **Feedback/notas:**
