  int EstadoA = 0;
  int EstadoB = 0;

  int w = 0;
  int x = 0;
  int y = 0;
  int z = 0;

void setup() {
  pinMode(2, INPUT);//A
  pinMode(3, INPUT);//B
  pinMode(4, INPUT);//w
  pinMode(5, INPUT);//x
  pinMode(6, INPUT);//y
  pinMode(7, INPUT);//z
  
  pinMode(13, OUTPUT);//SUMA, RESTA, DIVISION, MULTIPLICACION
  pinMode(12, OUTPUT);//ACARREO
  pinMode(11, OUTPUT);//SIGNO
  pinMode(10, OUTPUT);//INDEFINIDO
  pinMode(9, OUTPUT);//INFINITO
}

void loop() {

  EstadoA = digitalRead(2); // Leer valor de A
  EstadoB = digitalRead(3); // Leer valor de B
  w = digitalRead(4);
  x = digitalRead(5);
  y = digitalRead(6);
  z = digitalRead(7);

  // SUMA
  if ((EstadoA ^ EstadoB)&&(!z && !y && !x && w)) {
    digitalWrite(13, HIGH);
    digitalWrite(13, LOW);
  }
  // ACARREO
  if ((EstadoA && EstadoB)&&(!z && !y && !x && w)) {
    digitalWrite(12, HIGH);
    digitalWrite(12, LOW);
  }
  //RESTA
  if ((EstadoA ^ EstadoB)&&(!z && !y && x && !w)) {
    digitalWrite(13, HIGH);
    digitalWrite(13, LOW);
  }
  //SIGNO NEGATIVO DE LA RESTA
  if ((!EstadoA && EstadoB)&&(!z && !y && x && !w)) {
    digitalWrite(11, HIGH);
    digitalWrite(11, LOW);
  }

  //MULTIPLICACION
  if ((EstadoA && EstadoB)&&(!z && !y && x && w)) {
    digitalWrite(13, HIGH);
    digitalWrite(13, LOW);
  }

  //DIVISION
  if ((EstadoA && EstadoB)&&(!z && y && !x && !w)) {
    digitalWrite(13, HIGH);
    digitalWrite(13, LOW);
  }
  //INDEFINIDO
  if ((!EstadoA && !EstadoB)&&(!z && y && !x && !w)) {
    digitalWrite(10, HIGH);
    digitalWrite(10, LOW);
  }
  //INFINITO
  if ((EstadoA && !EstadoB)&&(!z && y && !x && !w)) {
    digitalWrite(9, HIGH);
    digitalWrite(9, LOW);
  }

  // AND
  if ((EstadoA && EstadoB) && (!z && y && !x && w)) {
    digitalWrite(13, HIGH);
    digitalWrite(13, LOW);
  }

  // OR
  if ((EstadoA || EstadoB) && (!z && y && x && !w)) {
    digitalWrite(13, HIGH);
    digitalWrite(13, LOW);
  }

  // NOT
if ((!z && y && x && w)) {
    if (!EstadoA) {
      digitalWrite(13, HIGH);
      digitalWrite(13, LOW);
    } else {
      digitalWrite(13, LOW);
    }
  }

  // XOR
  if ((EstadoA ^ EstadoB) && (z && !y && !x && !w)) {
    digitalWrite(13, HIGH);
    digitalWrite(13, LOW);
  }

  // XNOR
  if (!(EstadoA ^ EstadoB) && (z && !y && !x && w)) {
    digitalWrite(13, HIGH);
    digitalWrite(13, LOW);
  }

  // NAND
  if (!(EstadoA && EstadoB) && (z && !y && x && !w)) {
    digitalWrite(13, HIGH);
    digitalWrite(13, LOW);
  }

  // NOR
  if (!(EstadoA || EstadoB) && (z && !y && x && w)) {
    digitalWrite(13, HIGH);
    digitalWrite(13, LOW);
  }
}
