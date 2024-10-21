int EstadoA = 0;
int EstadoB = 0;

int w = 0;
int x = 0;
int y = 0;
int z = 0;

void setup() {
  // Configuración de pines de entrada para A, B, w, x, y, z
  pinMode(2, INPUT); 
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);

  // Configuración de pines de salida para operaciones
  pinMode(13, OUTPUT);  // Resultado de operación
  pinMode(12, OUTPUT);  // Acarreo
  pinMode(11, OUTPUT);  // Signo
  pinMode(10, OUTPUT);  // Indefinido
  pinMode(9, OUTPUT);   // Infinito
}

void loop() {
  // Lectura de los estados de A, B, w, x, y, z
  EstadoA = digitalRead(2); 
  EstadoB = digitalRead(3); 
  w = digitalRead(4);
  x = digitalRead(5);
  y = digitalRead(6);
  z = digitalRead(7);

  // Operaciones aritméticas
  realizarOperacionesAritmeticas();

  // Operaciones lógicas
  realizarOperacionesLogicas();

  // Restablecer los pines de salida a LOW
  resetearSalidas();
}

void realizarOperacionesAritmeticas() {
  // SUMA: A XOR B cuando w = 1 y z, y, x = 0
  if ((EstadoA ^ EstadoB) && (!z && !y && !x && w)) {
    digitalWrite(13, HIGH);
  }

  // ACARREO: A AND B cuando w = 1 y z, y, x = 0
  if ((EstadoA && EstadoB) && (!z && !y && !x && w)) {
    digitalWrite(12, HIGH);
  }

  // RESTA: A XOR B cuando x = 1, w = 0 y z, y = 0
  if ((EstadoA ^ EstadoB) && (!z && !y && x && !w)) {
    digitalWrite(13, HIGH);
  }

  // SIGNO NEGATIVO: !A AND B cuando x = 1, w = 0 y z, y = 0
  if ((!EstadoA && EstadoB) && (!z && !y && x && !w)) {
    digitalWrite(11, HIGH);
  }

  // MULTIPLICACIÓN: A AND B cuando w = 1, x = 1 y z, y = 0
  if ((EstadoA && EstadoB) && (!z && !y && x && w)) {
    digitalWrite(13, HIGH);
  }

  // DIVISIÓN: A AND B cuando y = 1 y z, x, w = 0
  if ((EstadoA && EstadoB) && (!z && y && !x && !w)) {
    digitalWrite(13, HIGH);
  }

  // INDEFINIDO: !A AND !B cuando y = 1 y z, x, w = 0
  if ((!EstadoA && !EstadoB) && (!z && y && !x && !w)) {
    digitalWrite(10, HIGH);
  }

  // INFINITO: A AND !B cuando y = 1 y z, x, w = 0
  if ((EstadoA && !EstadoB) && (!z && y && !x && !w)) {
    digitalWrite(9, HIGH);
  }
}

void realizarOperacionesLogicas() {
  // AND: A AND B cuando y = 1 y x = 0, w = 1, z = 0
  if ((EstadoA && EstadoB) && (!z && y && !x && w)) {
    digitalWrite(13, HIGH);
  }

  // OR: A OR B cuando y = 1 y x = 1, w = 0, z = 0
  if ((EstadoA || EstadoB) && (!z && y && x && !w)) {
    digitalWrite(13, HIGH);
  }

  // NOT A cuando w = 1, x = 1, y = 1, z = 0
  if (!z && y && x && w) {
    digitalWrite(13, EstadoA ? LOW : HIGH);
  }

  // XOR: A XOR B cuando z = 1 y y, x, w = 0
  if ((EstadoA ^ EstadoB) && (z && !y && !x && !w)) {
    digitalWrite(13, HIGH);
  }

  // XNOR: !(A XOR B) cuando z = 1 y w = 1, y, x = 0
  if (!(EstadoA ^ EstadoB) && (z && !y && !x && w)) {
    digitalWrite(13, HIGH);
  }

  // NAND: !(A AND B) cuando z = 1 y x = 1, y = 0, w = 0
  if (!(EstadoA && EstadoB) && (z && !y && x && !w)) {
    digitalWrite(13, HIGH);
  }

  // NOR: !(A OR B) cuando z = 1 y x = 1, y = 0, w = 1
  if (!(EstadoA || EstadoB) && (z && !y && x && w)) {
    digitalWrite(13, HIGH);
  }
}

// Función para resetear las salidas
void resetearSalidas() {
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
}
