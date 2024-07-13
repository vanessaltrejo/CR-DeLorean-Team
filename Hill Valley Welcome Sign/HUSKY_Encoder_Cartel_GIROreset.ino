#include "HUSKYLENS.h"
#include "SoftwareSerial.h"

HUSKYLENS huskylens;
SoftwareSerial mySerial(10, 11);

int ID1 = 1;
const int C1 = 3; // Entrada de la señal A del encoder.
const int C2 = 2; // Entrada de la señal B del encoder.

int ENA = 8;
int ENB = 9;
int PWM = 13;

volatile int n = 0;
volatile byte ant = 0;
volatile byte act = 0;

unsigned long lastTime = 0;  // Tiempo anterior
unsigned long sampleTime = 100;  // Tiempo de muestreo

bool faceDetected = false; // Variable para rastrear si se ha detectado una cara

// Declaración de funciones antes de usarlas
void encoder(void);
void printResult(HUSKYLENSResult result);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  Serial.println("Iniciando HUSKYLENS...");
  while (!huskylens.begin(mySerial)) {
    Serial.println(F("Begin failed!"));
    Serial.println(F("1. Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings >> Protocol Type >> Serial 9600)"));
    Serial.println(F("2. Please recheck the connection."));
    delay(1000);  // Aumenta el tiempo de espera para dar más tiempo a la inicialización
  }
  Serial.println("HUSKYLENS iniciado correctamente!");

  pinMode(C1, INPUT);
  pinMode(C2, INPUT);
  
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(PWM, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(C1), encoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(C2), encoder, CHANGE);
  
  Serial.println("Numero de conteos");
}

void loop() {
  if (millis() - lastTime >= sampleTime || lastTime == 0) {
    lastTime = millis();
    Serial.print("Numero de cuentas: ");
    Serial.println(n);
  }

  if (huskylens.requestBlocks(ID1)) {
    if (huskylens.isLearned() && huskylens.available()) {
      HUSKYLENSResult result = huskylens.read();
      printResult(result);
      faceDetected = true; // Se ha detectado una cara
    } else {
      Serial.println(F("No object detected or learned!"));
    }
  } else {
    Serial.println(F("Check connection!"));
  }

  // Mover el motor si se ha detectado una cara y n es menor que 1000
  if (faceDetected && n < 5000) {
    digitalWrite(ENA, LOW);
    digitalWrite(ENB, HIGH);
    analogWrite(PWM, 200);
  }

  // Detener el motor si n alcanza 1000
  if (n >= 5000) {
    digitalWrite(ENA, LOW);
    digitalWrite(ENB, LOW);
    analogWrite(PWM, 0);
    Serial.println("Motor detenido al alcanzar 1000 conteos.");
    
    // Reiniciar variables para permitir futuras detecciones
    n = 0; 
    faceDetected = false; 
  }
}

void printResult(HUSKYLENSResult result) {
  if (result.command == COMMAND_RETURN_BLOCK) {
    Serial.println(String() + F("Block: xCenter=") + result.xCenter + F(", yCenter=") + result.yCenter + F(", width=") + result.width + F(", height=") + result.height + F(", ID=") + result.ID);
  } else if (result.command == COMMAND_RETURN_ARROW) {
    Serial.println(String() + F("Arrow: xOrigin=") + result.xOrigin + F(", yOrigin=") + result.yOrigin + F(", xTarget=") + result.xTarget + F(", yTarget=") + result.yTarget + F(", ID=") + result.ID);
  } else {
    Serial.println("Object unknown!");
  }
}

// Encoder precisión cuádruple.
void encoder(void) {
  ant = act;

  if (digitalRead(C1)) bitSet(act, 1); else bitClear(act, 1);
  if (digitalRead(C2)) bitSet(act, 0); else bitClear(act, 0);

  if (ant == 2 && act == 0) n++;
  if (ant == 0 && act == 1) n++;
  if (ant == 3 && act == 2) n++;
  if (ant == 1 && act == 3) n++;

  if (ant == 1 && act == 0) n--;
  if (ant == 3 && act == 1) n--;
  if (ant == 0 && act == 2) n--;
  if (ant == 2 && act == 3) n--;
}
