#define Pecho 3
#define Ptrig 2
#define Pecho2 6
#define Ptrig2 7
long duracion, distancia, duracion2, distancia2;
int buzzer = 10, c1=0, c2=0, c3=0, c4=0, c5=0, c6=0;
const int ledPinR = 8;
const int ledPinA = 4;
const int ledPinV = 5;

void setup() {
  Serial.begin (9600);       
  pinMode(buzzer, OUTPUT);
  pinMode(Pecho, INPUT);     
  pinMode(Ptrig, OUTPUT);
  pinMode(Pecho2, INPUT);     
  pinMode(Ptrig2, OUTPUT);    
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinA, OUTPUT);
  pinMode(ledPinV, OUTPUT);

}

void loop() {
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);   
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
  tone(buzzer, LOW);

  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion / 2) / 29; 

  digitalWrite(Ptrig2, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig2, HIGH);   
  delayMicroseconds(10);
  digitalWrite(Ptrig2, LOW);
 
  duracion2 = pulseIn(Pecho2, HIGH);
  distancia2 = (duracion2 / 2) / 29; 

  c1=0;
  c2=0;
  c3=0;
  c4=0;
  c5=0;
  c6=0;

  if (distancia >= 20 && distancia <= 500 && distancia2 >=4.5 && distancia2 <=50 && c1==0 ) 
  {   
    Serial.println("Distancia 1");
    Serial.println("CASO 1");
    Serial.println(distancia); 
    Serial.println("Distancia 2");
    Serial.println(distancia2);                  
    tone(buzzer, LOW);
    digitalWrite(ledPinR, false);
    digitalWrite(ledPinV, true);
    digitalWrite(ledPinA, false);
     delay(500);
    c1==1;
  }
    
    if ( distancia >= 20 && distancia <= 500 && distancia2 >=0 && distancia2 < 4.5 && c2==0)
    {
    Serial.println("CASO 2");
    Serial.println("Distancia 1");
    Serial.println(distancia); 
    Serial.println("Distancia 2");
    Serial.println(distancia2);                  
    tone(buzzer, LOW);
    digitalWrite(ledPinR, true);
    digitalWrite(ledPinV, false);
    digitalWrite(ledPinA, false);
    delay(500);
    c2=1;
    }
  

  if (distancia2 >=4.4 && distancia2 <=50 && distancia < 20 && distancia >= 10 && c3==0) 
  {
    Serial.println("CASO 3");
    Serial.println("Distancia 1");
    Serial.println(distancia); 
    Serial.println("Distancia 2");
    Serial.println(distancia2);                  
    tone(buzzer, LOW);
    digitalWrite(ledPinR, false);
    digitalWrite(ledPinV, false);
    digitalWrite(ledPinA, true);
     delay(500);
    c3=1;
  }
    if (distancia2 >=0 && distancia2 < 4.5 && distancia < 20 && distancia >= 10 && c4==0)
    {
    Serial.println("CASO 4");
    Serial.println("Distancia 1");
    Serial.println(distancia); 
    Serial.println("Distancia 2");
    Serial.println(distancia2);                  
    tone(buzzer, LOW);
    digitalWrite(ledPinR, true);
    digitalWrite(ledPinV, false);
    digitalWrite(ledPinA, false);
     delay(500);
    c4=0;
    }       
  
  if (distancia < 10 && distancia >= 1 && distancia2 >=4.5 && distancia2 <=50 && c5==0) 
  {
    Serial.println("CASO 5");
    Serial.println("Distancia 1");
    Serial.println(distancia); 
    Serial.println("Distancia 2");
    Serial.println(distancia2);                  
    tone(buzzer, LOW);
    digitalWrite(ledPinR, true);
    digitalWrite(ledPinV, false);
    digitalWrite(ledPinA, false);
     delay(500);
    c5=1;
  }
    if (distancia2 >=0 && distancia2 < 4.5 && distancia < 10 && distancia >= 1 && c6==0)
    {
      Serial.println("CASO 6");
    Serial.println("Distancia 1");
    Serial.println(distancia); 
    Serial.println("Distancia 2");
    Serial.println(distancia2);                  
    tone(buzzer, LOW);
    digitalWrite(ledPinR, true);
    digitalWrite(ledPinV, false);
    digitalWrite(ledPinA, false);
    delay(500);
    c6=1;
    }         
  
  delay(200);  
  Serial.println("----------------------");
    //Serial.println(distancia); 
    //Serial.println("Distancia 2");
    //Serial.println(distancia2);                                 

}
