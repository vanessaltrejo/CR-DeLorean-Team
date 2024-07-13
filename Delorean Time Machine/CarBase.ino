//
//Declare pins fir the IBT drivers

int ENALft = 37;
int ENARht = 45;

int PWMleftL = 4;
int PWMrightL = 3;

int PWMleftR = 6;
int PWMrightR = 5;


void setup() {
  // Start serial communication with the OAK-D true PyCharm
Serial.begin(9600);
 // Pin modes for the arduino
pinesOUT();
}

void loop() {
//if serial is available and greater than 0
if(Serial.available() > 0){ 
  char option = Serial.read(); // define option as a character read in serial monitor
  switch(option){  //switch from the characters send b the OAK-D Camera
case 'A':
Left();
break;

case 'B': 
Stop();
break;

case 'C':
Right();
break;

case 'F':
Backwards();
break;

case 'D':
Forward();
break;

case 'W':
Stop();
break;

default:
Stop();
break;
  }
 }
}

void pinesOUT(){
  pinMode(ENALft, OUTPUT);
  pinMode(ENARht, OUTPUT);

  pinMode(PWMleftL, OUTPUT);
  pinMode(PWMrightL, OUTPUT);

  pinMode(PWMleftR, OUTPUT);
  pinMode(PWMrightR, OUTPUT);

digitalWrite(ENALft, HIGH);
digitalWrite(ENARht, HIGH);

}

void Forward(){
  analogWrite(PWMleftL, 140);
  analogWrite(PWMrightL, 0);

  analogWrite(PWMleftR, 140);
  analogWrite(PWMrightR, 0);
}

void Backwards(){
   analogWrite(PWMleftL, 0);
  analogWrite(PWMrightL, 140);

  analogWrite(PWMleftR, 0);
  analogWrite(PWMrightR, 140);
}

void Left(){
  analogWrite(PWMleftL, 100);
  analogWrite(PWMrightL, 00);

  analogWrite(PWMleftR, 00);
  analogWrite(PWMrightR, 100);
}

void Right(){
   analogWrite(PWMleftL, 00);
  analogWrite(PWMrightL, 100);

  analogWrite(PWMleftR, 100);
  analogWrite(PWMrightR, 00);
}

void Stop(){
  analogWrite(PWMleftL, 0);
  analogWrite(PWMrightL, 0);

  analogWrite(PWMleftR, 0);
  analogWrite(PWMrightR, 0);
}