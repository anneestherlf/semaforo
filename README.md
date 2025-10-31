# Projeto: Semáforo para Controle de Tráfego

Este repositório contém a entrega do desenvolvimento de um protótipo de semáforo para controle de fluxo (ponderada).

O projeto é dividido na montagem física do circuito em protoboard e na programação da lógica de temporização das luzes.

**Aluna Anne Esther Lins Figueirôa - T18.**

# Demonstração (Vídeo)

O vídeo abaixo apresenta a montagem física do semáforo em funcionamento na protoboard. Apareço na gravação para comprovar a autoria, e o ciclo de temporização (vermelho, verde, amarelo) é demonstrado conforme os requisitos da atividade (LEDs acendendo e apagando conforme o código).

**Link para o vídeo:**  
<https://drive.google.com/file/d/1gO_KOI8kHlK7yTHxjkbuD9sJQyMjtKt0/view?usp=sharing>

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
| Jumper Wires       | Macho-Macho         | 4         | Fios para realizar as conexões entre o Arduino e a protoboard.              |

<img src="https://github.com/user-attachments/assets/fd3b0414-e3c5-49b5-9b10-b7cebb7fbf6a" alt="componentess" width="600">

# Tutorial de Montagem e Conexões

1. **Posicionamento dos LEDs:** Os LEDs foram posicionados na protoboard.

<img src="https://github.com/user-attachments/assets/fe499049-13db-452b-b970-f849a9ac12f9" width="600">

3. **Identificação dos Terminais:** Cada LED possui dois terminais: o Anodo (perna mais longa, positiva) e o Catodo (perna mais curta, negativa).
4. **Conexão do Anodo (Positivo):** O terminal Anodo de cada LED foi conectado a um pino de saída digital do Arduino, conforme a tabela:
   - LED Vermelho → Pino Digital 9
   - LED Amarelo → Pino Digital 10
   - LED Verde → Pino Digital 11
5. **Conexão do Catodo (Negativo) e Resistor:** O terminal Catodo de cada LED foi conectado a um resistor.

<img src="https://github.com/user-attachments/assets/be2612de-c6da-452a-8462-04e9784b3edc" width="600">

7. **Conexão ao GND (Terra):** A extremidade dos três resistores foi conectada ao barramento de "Terra" (GND) da protoboard.

<img src="https://github.com/user-attachments/assets/e2d7d9ab-7acd-42f2-8680-f5a6cf624345" width="600">

<img src="https://github.com/user-attachments/assets/bce6adf2-1587-440a-b4fd-15ae071b2275" width="600">

9. **LEDs:** Conecte um fio jumper do Pino Digital 11 do Arduino até a fileira da perna longa (Anodo +) do LED Verde.

<img src="https://github.com/user-attachments/assets/08f47688-ef58-4330-9435-512b870dafb1" width="600">

<img src="https://github.com/user-attachments/assets/ca2c0e74-8b96-461c-b7df-f3fb6b4764b8" width="600">

Faça o mesmo para o LED Vermelho (no Pino Digital 9) e para o LED Amarelo (no Pino Digital 10). 

<img src="https://github.com/user-attachments/assets/406e99d9-fddb-4e3a-b13b-fb41ba15b27a" width="600">

10. **Energia:** Conecte a uma fonte de energia (nesse caso, usei o cabo USB no notebook).

<img src="https://github.com/user-attachments/assets/92962da4-aa5b-448d-83e6-f9ada9f11b1f" width="600">

11. Conecte e execute o código no Arduino IDE (<https://www.arduino.cc/en/software>, ou outra ferramenta de sua preferência). O código pode ser encontrado na seção "Código-fonte".

<img src="https://github.com/user-attachments/assets/b268a0c2-1a4d-4465-befa-690ba07942da" width="600">

Resultado:

<img src="https://github.com/user-attachments/assets/f94aac18-8eea-48ac-9abf-e57594e7c24b" width="600">

**Por que usar resistores?** O resistor é essencial para limitar a corrente que flui do pino digital do Arduino (que opera a 5V) para o LED. Sem ele, o LED receberia uma corrente excessiva e queimaria instantaneamente.

# Parte 2: Programação e Lógica do Semáforo

O código-fonte foi desenvolvido na IDE do Arduino (baseado em C++) e segue a lógica de temporização exigida.
1. **Luz Vermelha:** Acesa por 6 segundos (Verde e Amarelo apagados).
2. **Luz Verde:** Acesa por 4 segundos (Vermelho e Amarelo apagados).
3. **Luz Amarela:** Acesa por 2 segundos (Vermelho e Verde apagados).

## Código-Fonte

O código completo pode ser encontrado neste repositório no arquivo `semaforo.ino`.

Abaixo está o trecho principal da lógica (loop), que garante a sequência e temporização:

```cpp
// O #define é uma diretiva de pré-processador que substitui um texto por outro.
// Aqui, estamos associando nomes (verde, amarelo, vermelho) aos números das portas digitais do Arduino.
#define verde 11      // Define 'verde' como um apelido para a porta digital 11
#define amarelo 10    // Define 'amarelo' como um apelido para a porta digital 10
#define vermelho 9    // Define 'vermelho' como um apelido para a porta digital 9

// A função setup() é executada uma vez quando o Arduino é ligado ou resetado.
// É usada para inicializar configurações.
void setup() {
  // pinMode() configura uma porta digital específica para funcionar como entrada (INPUT) ou saída (OUTPUT).
  pinMode(verde, OUTPUT);    // Configura a porta 'verde' (11) como saída digital
  pinMode(amarelo, OUTPUT);  // Configura a porta 'amarelo' (10) como saída digital
  pinMode(vermelho, OUTPUT); // Configura a porta 'vermelho' (9) como saída digital
}

// Declaração de uma função personalizada chamada 'acendeVerde'.
// 'void' significa que a função não retorna nenhum valor.
// '(int tempo)' significa que ela aceita um argumento (um número inteiro) chamado 'tempo'.
void acendeVerde(int tempo) {
  // digitalWrite() escreve um valor HIGH (ligado, 5V) ou LOW (desligado, 0V) em uma porta digital.
  digitalWrite(verde, HIGH);    // Liga o LED conectado à porta 'verde'
  digitalWrite(amarelo, LOW);   // Desliga o LED conectado à porta 'amarelo'
  digitalWrite(vermelho, LOW);  // Desliga o LED conectado à porta 'vermelho'
  
  // delay() pausa a execução do programa pelo número de milissegundos especificado.
  delay(tempo);                 // Mantém o LED verde aceso pelo 'tempo' recebido (em milissegundos)
}

// Declaração da função 'acendeVermelho'.
// Funciona de forma similar à 'acendeVerde', mas acende o LED vermelho.
void acendeVermelho(int tempo) {
  digitalWrite(verde, LOW);     // Desliga o LED 'verde'
  digitalWrite(amarelo, LOW);    // Desliga o LED 'amarelo'
  digitalWrite(vermelho, HIGH); // Liga o LED 'vermelho'
  delay(tempo);                  // Mantém o LED vermelho aceso pelo 'tempo' especificado
}

// Declaração da função 'acendeAmarelo'.
// Acende o LED amarelo e apaga os outros.
void acendeAmarelo(int tempo) {
  digitalWrite(verde, LOW);     // Desliga o LED 'verde'
  digitalWrite(amarelo, HIGH);   // Liga o LED 'amarelo'
  digitalWrite(vermelho, LOW);  // Desliga o LED 'vermelho'
  delay(tempo);                  // Mantém o LED amarelo aceso pelo 'tempo' especificado
}

// A função loop() é executada continuamente após a função setup() terminar.
// É o corpo principal do programa.
void loop() {
  // Chama a função 'acendeVermelho' e passa o valor 6000 como argumento 'tempo'.
  acendeVermelho(6000); // Mantém o sinal vermelho aceso por 6000 milissegundos (6 segundos)
  
  // Chama a função 'acendeVerde' e passa o valor 4000.
  acendeVerde(4000);    // Mantém o sinal verde aceso por 4000 milissegundos (4 segundos)
  
  // Chama a função 'acendeAmarelo' e passa o valor 2000.
  acendeAmarelo(2000);  // Mantém o sinal amarelo aceso por 2000 milissegundos (2 segundos)
  
  // Após o amarelo, o loop() recomeça, voltando para 'acendeVermelho(6000)'.
}
```
## Parte 3: Avaliação de Pares
Conforme os critérios da atividade, o projeto foi avaliado por, no mínimo, dois colegas. Seguem os resultados das avaliações.

### Avaliador 1
- **Nome completo:**
- **Feedback/notas:**

- ### Avaliador 2
- **Nome completo:**
- **Feedback/notas:**
