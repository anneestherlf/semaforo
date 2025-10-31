// --- Classe (Molde) para um LED ---
class Led {
  public:
    int pino; // Propriedade

    // Construtor
    Led(int p) {
      pino = p;
      pinMode(pino, OUTPUT); // Configuração já acontece aqui!
    }

    // Métodos
    void acender() {
      digitalWrite(pino, HIGH);
    }
    void apagar() {
      digitalWrite(pino, LOW);
    }
};

// --- Classe (Molde) para o Semáforo ---
class Semaforo {
  public:
    // Propriedades: Ponteiros para os LEDs
    Led* verde;
    Led* amarelo;
    Led* vermelho;

    // Construtor: Recebe os endereços dos objetos Led
    Semaforo(Led* v, Led* a, Led* r) {
      verde = v;
      amarelo = a;
      vermelho = r;
    }

    // Métodos: As ações do semáforo
    void acenderVerde(int tempo) {
      verde->acender();   // Usa '->' pois 'verde' é um ponteiro
      amarelo->apagar();
      vermelho->apagar();
      delay(tempo);
    }

    void acenderVermelho(int tempo) {
      verde->apagar();
      amarelo->apagar();
      vermelho->acender();
      delay(tempo);
    }

    void acenderAmarelo(int tempo) {
      verde->apagar();
      amarelo->acender();
      vermelho->apagar();
      delay(tempo);
    }
};

// Configuração Principal (setup e loop)


// 1. Criamos os OBJETOS LED "reais" a partir do molde (Classe Led)
//    O construtor (Led(pino)) é chamado automaticamente
Led ledVerde(11);     // Cria um objeto Led para o pino 11
Led ledAmarelo(10);   // Cria um objeto Led para o pino 10
Led ledVermelho(9);   // Cria um objeto Led para o pino 9

// 2. Criamos o OBJETO SEMÁFORO
//    Passamos os ENDEREÇOS (&) dos objetos LED para o construtor do Semáforo.
//    É aqui que usamos os ponteiros!
Semaforo meuSemaforo(&ledVerde, &ledAmarelo, &ledVermelho);

void setup() {
  // Não precisamos de NADA aqui!
  // Os construtores dos LEDs já chamaram o pinMode() para nós.
}

void loop() {
  // O loop fica muito mais limpo e legível!
  // Estamos chamando os métodos do *nosso objeto* meuSemaforo.
  
  meuSemaforo.acenderVermelho(6000);
  meuSemaforo.acenderVerde(4000);
  meuSemaforo.acenderAmarelo(2000);
}
