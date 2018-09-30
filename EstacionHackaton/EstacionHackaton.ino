#define Pecho 6
#define Ptrig 7
long duracion, distancia;
int buzzer = 10;
int LedR = 13;

void setup() {
  Serial.begin (9600);       // inicializa el puerto seria a 9600 baudios
  pinMode(buzzer, OUTPUT);
  pinMode(Pecho, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(Ptrig, OUTPUT);    // define el pin 7 como salida  (triger)
  //pinMode(13, 1);            // Define el pin 13 como salida
  pinMode(8, 1);
  pinMode (LedR, OUTPUT);

}

void loop() {
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
  //tone(buzzer, LOW);

  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion / 2) / 29;          // calcula la distancia en centimetros

  if (distancia >= 500 || distancia <= 0) { // si la distancia es mayor a 500cm o menor a 0cm
    Serial.println("---");                  // no mide nada
    tone(buzzer, LOW);
  }
  else {
    Serial.print(distancia);           // envia el valor de la distancia por el puerto serial
    Serial.println("cm");              // le coloca a la distancia los centimetros "cm"
    //digitalWrite(13, 0);               // en bajo el pin 13
    digitalWrite(8, 0);                // el pin 8 en bajo
  }

  if (distancia <= 20 && distancia >= 10) {
    //digitalWrite(13, 1);     // en alto el pin 13 si la distancia es menor a 10cm
    digitalWrite(8, 1);
    //tone(buzzer, 1000);
    Serial.println("Alarma.......");         // envia la palabra Alarma por el puerto serial
  }
  if (distancia <= 10 && distancia >= 1) {
    digitalWrite(LedR, true);     // en alto el pin 13 si la distancia es menor a 10cm
    digitalWrite(8, 1);
    tone(buzzer, 2000);
    
    Serial.println("Alarma.......");         // envia la palabra Alarma por el puerto serial
  }
  delay(200);                                // espera 400ms para que se logre ver la distancia en la consola

}
