const int AIA1 = 2;
const int AIB1 = 3;
const int BIA1 = 4;
const int BIB1 = 5;
const int AIA2 = 6;
const int AIB2 = 7;
const int BIA2 = 8;
const int BIB2 = 9;
int trig = 12;
int echo = 11;
long lecture_echo;
long cm;
byte speed1 = 255;

void setup() {
  Serial.begin(9600);
  //PWM Moteur
  pinMode(AIA1, OUTPUT);
  pinMode(AIB1, OUTPUT);
  pinMode(BIA1, OUTPUT);
  pinMode(BIB1, OUTPUT);
  pinMode(AIA2, OUTPUT);
  pinMode(AIB2, OUTPUT);
  pinMode(BIA2, OUTPUT);
  pinMode(BIB2, OUTPUT);
  //Ultrasons
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);

}

void loop() {
  forward();
}

void forward()
{
  analogWrite(AIA1, speed1);
  analogWrite(AIB1, 0);
  analogWrite(BIA1, speed1);
  analogWrite(BIB1, 0);
  analogWrite(AIA2, speed1);
  analogWrite(AIB2, 0);
  analogWrite(BIA2, speed1);
  analogWrite(BIB2, 0);
}



void ultrason ()
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  lecture_echo = pulseIn(echo, HIGH);
  cm = lecture_echo / 58;
  Serial.print("Distancem : ");
  Serial.println(cm);
  delay(1000);
}

