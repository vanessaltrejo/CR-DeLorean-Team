#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

SoftwareSerial BluetoothMaster(10, 11); // Configura el puerto serie para el módulo Bluetooth
Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

int RED1 = 2;
int GREEN1 = 3;
int BLUE1 = 4;

int RED2 = 5;
int GREEN2 = 6;
int BLUE2 = 7;

int RED3 = 8;
int GREEN3 = 9;
int BLUE3 = 13;

int pos0 = 102;
int pos180 = 512;

void setup() {
  Serial.begin(38400); // Inicializa la comunicación serie con la velocidad deseada para la cámara OpenMV
  BluetoothMaster.begin(38400); // Inicializa el módulo Bluetooth
  servos.begin();
  servos.setPWMFreq(50);
  PINSOUTPUT();
}

void loop() {
 // Leer señales de la cámara OpenMV
  if (Serial.available()) {
    char signal = Serial.read();
    BluetoothMaster.print(signal); // Envía el caracter recibido por Bluetooth
     // Leer el caracter recibido de la cámara OpenMV
    Serial.print("Received option: ");
    Serial.println(signal);
    Serial.print("Sent via Bluetooth: ");
    Serial.println(signal);
    // Tu lógica de control de servos aquí
    switch(signal) {
      case 'H':
      YELLOW();
        VolanteDerDer();
        MangoAtrasAtras();
        VolanteDerIzq();
        YELLOWOFF();
        break;
      case 'I':
      AQUA();
        MangoAtrasAdelante();
        VolanteDerIzq();
        MangoAdelanteAdelante();
        VolanteIzqDer();
        MangoAdelanteAtras();
      AQUAOFF();
        break;
      case 'J':
      GREEN();
        MangoAtrasAtras();
        GREENOFF();
        break;
      case 'K':
      PURPLE();
        MangoAtrasAdelante();
        VolanteIzqIzq();
        MangoAdelanteAdelante();
        VolanteIzqDer();
        MangoAdelanteAtras();
      PURPLEOFF();
        break;
      case 'L':
      YELLOW();
        VolanteIzqIzq();
        MangoAtrasAtras();
        VolanteIzqDer();
        YELLOWOFF();
        break;
      case 'M':
      PURPLE();
        MangoAtrasAdelante();
        VolanteIzqIzq();
        MangoAdelanteAdelante();
        VolanteIzqDer();
        MangoAdelanteAtras();
      PURPLEOFF();
        break;
      case 'N':
      GREEN();
        MangoAtrasAtras();
        GREENOFF();
        break;
      case 'O':
      AQUA();
        MangoAtrasAdelante();
        VolanteDerDer();
        MangoAdelanteAdelante();
        VolanteDerIzq();
        MangoAdelanteAtras();
        AQUAOFF();
        break;
      case 'P':
      RED();
        MangoAtrasAtras();
        VolanteDerDer();
        REDOFF();
        break;
      case 'Q':
      AQUA();
        MangoAtrasAdelante();
        VolanteIzqIzq();
        MangoAdelanteAdelante();
        VolanteIzqDer();
        MangoAdelanteAtras();
        AQUAOFF();
        break;
      default:
        // BLUE();
        // VolanteN();
        // MangoN();
        // BLUEOFF();
        break;
    }
  } 
}

// Definiciones de las funciones Volante y Mango...

void Servo(uint8_t n_servo, int angulo){
  int duty;
  duty=map(angulo,0,180,pos0, pos180);
  servos.setPWM(n_servo,0,duty);
}

void PINSOUTPUT(){
  pinMode(RED1, OUTPUT);
  pinMode(GREEN1, OUTPUT);
  pinMode(BLUE1, OUTPUT);

  pinMode(RED2, OUTPUT);
  pinMode(GREEN2, OUTPUT);
  pinMode(BLUE2, OUTPUT);

  pinMode(RED3, OUTPUT);
  pinMode(GREEN3, OUTPUT);
  pinMode(BLUE3, OUTPUT);
}

void RED(){
  digitalWrite(RED1, HIGH);
  digitalWrite(RED2, HIGH);
  digitalWrite(RED3, HIGH);
}

void REDOFF(){
  digitalWrite(RED1, LOW);
  digitalWrite(RED2, LOW);
  digitalWrite(RED3, LOW);
}

void GREEN(){
  digitalWrite(GREEN1, HIGH);
  digitalWrite(GREEN2, HIGH);
  digitalWrite(GREEN3, HIGH);
}

void GREENOFF(){
  digitalWrite(GREEN1, LOW);
  digitalWrite(GREEN2, LOW);
  digitalWrite(GREEN3, LOW);
}

void BLUE(){
  digitalWrite(BLUE1, HIGH);
  digitalWrite(BLUE2, HIGH);
  digitalWrite(BLUE3, HIGH);
}

void BLUEOFF(){
  digitalWrite(BLUE1, LOW);
  digitalWrite(BLUE2, LOW);
  digitalWrite(BLUE3, LOW);
}

void PURPLE(){
  BLUE();
  RED();
}

void PURPLEOFF(){
  BLUEOFF();
  REDOFF();
}

void AQUA(){
  BLUE();
  GREEN();
}

void AQUAOFF(){
  BLUEOFF();
  GREENOFF();
}

void YELLOW(){
  RED();
  GREEN();
}

void YELLOWOFF(){
  REDOFF();
  GREENOFF();
}
void VolanteDerIzq(){
  Servo(1, 15);
  delay(70);
  Servo(1, 25);
  delay(70);
  Servo(1, 35);
  delay(70);
  Servo(1, 45);
  delay(70);
  Servo(1, 55);
  delay(70);
  Servo(1, 65);
  delay(70);
  Servo(1, 75);
  delay(70);
  Servo(1, 90);
  delay(70);
}

void VolanteDerDer(){
  Servo(1, 90);
  delay(70);
  Servo(1, 75);
  delay(70);
  Servo(1, 65);
  delay(70);
  Servo(1, 55);
  delay(70);
  Servo(1, 45);
  delay(70);
  Servo(1, 35);
  delay(70);
  Servo(1, 25);
  delay(70);
  Servo(1, 15);
  delay(70);
}

void VolanteIzqDer(){
  Servo(1, 165);
  delay(70);
  Servo(1, 155);
  delay(70);
  Servo(1, 145);
  delay(70);
  Servo(1, 135);
  delay(70);
  Servo(1, 125);
  delay(70);
  Servo(1, 115);
  delay(70);
  Servo(1, 105);
  delay(70);
  Servo(1, 90);
  delay(70);
}

void VolanteIzqIzq(){
  Servo(1, 90);
  delay(70);
  Servo(1, 105);
  delay(70);
  Servo(1, 115);
  delay(70);
  Servo(1, 125);
  delay(70);
  Servo(1, 135);
  delay(70);
  Servo(1, 145);
  delay(70);
  Servo(1, 155);
  delay(70);
  Servo(1, 165);
  delay(70);
}

void VolanteN(){
  Servo(1, 90);
}

void MangoAtrasAdelante(){
  Servo(4, 45);
  delay(70);  
  Servo(4, 50);
  delay(70);
  Servo(4, 55);
  delay(70);
  Servo(4, 60);
  delay(70);
  Servo(4, 65);
  delay(70);
  Servo(4, 70);
  delay(70);
  Servo(4, 75);
  delay(70);
  Servo(4, 80);
  delay(70);
  Servo(4, 85);
  delay(70);
  Servo(4, 90);
  delay(70);
}

void MangoAtrasAtras(){
  Servo(4, 90);
  delay(70);
  Servo(4, 85);
  delay(70);
  Servo(4, 80);
  delay(70);
  Servo(4, 75);
  delay(70);
  Servo(4, 70);
  delay(70);
  Servo(4, 65);
  delay(70);
  Servo(4, 60);
  delay(70);
  Servo(4, 55);
  delay(70);
  Servo(4, 50);
  delay(70);
  Servo(4, 45);
  delay(70);
}

void MangoAdelanteAdelante(){
  Servo(4, 130);
  delay(70);
  Servo(4, 135);
  delay(70);
  Servo(4, 140);
  delay(70);
  Servo(4, 145);
  delay(70);
  Servo(4, 150);
  delay(70);
  Servo(4, 155);
  delay(70);
  Servo(4, 160);
  delay(70);
  Servo(4, 165);
  delay(70);
  Servo(4, 170);
  delay(70);
  Servo(4, 175);
  delay(70);
}

void MangoAdelanteAtras(){
  Servo(4, 175);
  delay(70);
  Servo(4, 170);
  delay(70);
  Servo(4, 165);
  delay(70);
  Servo(4, 160);
  delay(70);
  Servo(4, 155);
  delay(70);
  Servo(4, 150);
  delay(70);
  Servo(4, 145);
  delay(70);
  Servo(4, 140);
  delay(70);
  Servo(4, 135);
  delay(70);
  Servo(4, 130);
  delay(70);
}

void MangoN(){
  // Servo(4, 130); // bailan si lo pongo 130 y 45
  // delay(100);
  Servo(4, 90);
  delay(100);
}
