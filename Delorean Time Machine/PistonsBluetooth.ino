#include <SoftwareSerial.h>

//Declare SoftwareSerial as BluetoothSlave and give pins 10, 11 RX and TX for communication
SoftwareSerial BluetoothSlave(10, 11); 

int PWMR1 = 2;
int PWML1 = 3;
int ENAB1 = 45;

int PWMR2 = 5;
int PWML2 = 6;
int ENAB2 = 37;

int PWMR3 = 7;
int PWML3 = 8;
int ENAB3 = 31;


void setup() {
  Serial.begin(38400); // Start serial communication with serial monitor
  BluetoothSlave.begin(38400); // Start bluetooth communication
  Serial.println("Esperando señal de Bluetooth...");
  //functions to declare pins and what will do 
    PINS();
  ONDRIVERS();
}

void loop() {
  if (BluetoothSlave.available()) {
    char signal = BluetoothSlave.read();
    Serial.write(signal); 
    switch(signal) {
      case 'H':
        UP1_2_3();
        delay(1500);
        STOP();
        break;

      case 'I':
        DOWN1_2_3();
        delay(1500);
        STOP();
        break;

      case 'J':
        UP1_0_0();
        delay(1000);
        STOP();
        break;

      case 'K':
        DOWN1_0_0();
        delay(1000);
        STOP();
        break;

      case 'L':
        UP0_2_0();
        delay(1000);
        STOP();
        break;

      case 'M':
        DOWN0_2_0();
        delay(1000);
        STOP();
        break;

      case 'N':
        UP0_0_3();
        delay(1000);
        STOP();
        break;

      case 'O':
        DOWN0_0_3();
        delay(1000);
        STOP();
        break;

      case 'P':
        UP0_2_3();
        delay(1000);
        STOP();
        break;

      case 'Q':
        DOWN0_2_3();
        delay(1000);
        STOP();
        break;

      default:
        STOP();
        break;
    }
  }
}

// Function to facilitate the code
void PINS(){
  pinMode(PWMR1, OUTPUT);
  pinMode(PWML1, OUTPUT);
  pinMode(ENAB1, OUTPUT);

  pinMode(PWMR2, OUTPUT);
  pinMode(PWML2, OUTPUT);
  pinMode(ENAB2, OUTPUT);

  pinMode(PWMR3, OUTPUT);
  pinMode(PWML3, OUTPUT);
  pinMode(ENAB3, OUTPUT);
}

void ONDRIVERS(){
  digitalWrite(ENAB1, HIGH);
  digitalWrite(ENAB2, HIGH);
  digitalWrite(ENAB3, HIGH);
}

void STOP(){
  analogWrite(PWMR1, 0);
  analogWrite(PWML1, 0);
  analogWrite(PWMR2, 0);
  analogWrite(PWML2, 0);
  analogWrite(PWMR3, 0);
  analogWrite(PWML3, 0);
  //all pistons turn off
}

void UP1_2_3(){ //H
  analogWrite(PWMR1, 0);
  analogWrite(PWML1, 200);
  analogWrite(PWMR2, 0);
  analogWrite(PWML2, 200);
  analogWrite(PWMR3, 0);
  analogWrite(PWML3, 200);
  //All pistons go up with "L"
}

void DOWN1_2_3(){ //I
  analogWrite(PWMR1, 200);
  analogWrite(PWML1, 0);
  analogWrite(PWMR2, 200);
  analogWrite(PWML2, 0);
  analogWrite(PWMR3, 200);
  analogWrite(PWML3, 0);
  //All pistons go down with "R"
}

void UP1_0_0(){ //J
  analogWrite(PWMR1, 0);
  analogWrite(PWML1, 120);
  analogWrite(PWMR2, 0);
  analogWrite(PWML2, 0);
  analogWrite(PWMR3, 0);
  analogWrite(PWML3, 0);
  //Piston 1 go up with "L"
}

void DOWN1_0_0(){ //K
  analogWrite(PWMR1, 120);
  analogWrite(PWML1, 0);
  analogWrite(PWMR2, 0);
  analogWrite(PWML2, 0);
  analogWrite(PWMR3, 0);
  analogWrite(PWML3, 0);
  //Piston 1 go down with "R"
}

void UP0_2_0(){ //L
  analogWrite(PWMR1, 0);
  analogWrite(PWML1, 0);
  analogWrite(PWMR2, 0);
  analogWrite(PWML2, 120);
  analogWrite(PWMR3, 0);
  analogWrite(PWML3, 0);
  //Piston 2 go up with "L"
}

void DOWN0_2_0(){ //M
  analogWrite(PWMR1, 0);
  analogWrite(PWML1, 0);
  analogWrite(PWMR2, 120);
  analogWrite(PWML2, 0);
  analogWrite(PWMR3, 0);
  analogWrite(PWML3, 0);
  //Piston 2 go down with "R"
}

void UP0_0_3(){ //N
  analogWrite(PWMR1, 0);
  analogWrite(PWML1, 0);
  analogWrite(PWMR2, 0);
  analogWrite(PWML2, 0);
  analogWrite(PWMR3, 0);
  analogWrite(PWML3, 120);
  //Piston 3 go up with "L"
}

void DOWN0_0_3(){ //O
  analogWrite(PWMR1, 0);
  analogWrite(PWML1, 0);
  analogWrite(PWMR2, 0);
  analogWrite(PWML2, 0);
  analogWrite(PWMR3, 120);
  analogWrite(PWML3, 0);
  //Piston 3 go down with "R"
}

void UP1_2_0(){
  analogWrite(PWMR1, 0);
  analogWrite(PWML1, 120);
  analogWrite(PWMR2, 0);
  analogWrite(PWML2, 120);
  analogWrite(PWMR3, 0);
  analogWrite(PWML3, 0);
}

void DOWN1_2_0(){
  analogWrite(PWMR1, 120);
  analogWrite(PWML1, 0);
  analogWrite(PWMR2, 120);
  analogWrite(PWML2, 0);
  analogWrite(PWMR3, 0);
  analogWrite(PWML3, 0);
}

void UP1_0_3(){
  analogWrite(PWMR1, 0);
  analogWrite(PWML1, 120);
  analogWrite(PWMR2, 0);
  analogWrite(PWML2, 0);
  analogWrite(PWMR3, 0);
  analogWrite(PWML3, 120);
}

void DOWN1_0_3(){
  analogWrite(PWMR1, 120);
  analogWrite(PWML1, 0);
  analogWrite(PWMR2, 0);
  analogWrite(PWML2, 0);
  analogWrite(PWMR3, 120);
  analogWrite(PWML3, 0);
}

void UP0_2_3(){ //P
  analogWrite(PWMR1, 0);
  analogWrite(PWML1, 0);
  analogWrite(PWMR2, 0);
  analogWrite(PWML2, 120);
  analogWrite(PWMR3, 0);
  analogWrite(PWML3, 120);
}

void DOWN0_2_3(){ //Q
  analogWrite(PWMR1, 0);
  analogWrite(PWML1, 0);
  analogWrite(PWMR2, 120);
  analogWrite(PWML2, 0);
  analogWrite(PWMR3, 120);
  analogWrite(PWML3, 0);
}
