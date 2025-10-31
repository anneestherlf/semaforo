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
