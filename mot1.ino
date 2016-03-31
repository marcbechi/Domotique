const int AIA1 = 2;//B-1A
const int AIB1 = 3;//B-1B
const int BIA1 = 4;//A-1A
const int BIB1 = 5;//A-1B
const int AIA2 = 6;//B-2A
const int AIB2 = 7;//B-2B
const int BIA2 = 8;//A-2A
const int BIB2 = 9;//A-2B
int trig = 12; //variable for ultrason
int echo = 11; // variable for ultrason
long lecture_echo;
long cm;
byte speed1 = 255; //speed of motor

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
  Serial.print("Distance : ");
  Serial.println(cm);
  delay(1000);
}

