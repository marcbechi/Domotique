#include <Metro.h>  // library <return>
#include <math.h> 
Metro ledlightup = Metro(60,true);
Metro processdata = Metro(50,true);
Metro TcsTrigger = Metro(10,true);
 
int s0=8,s1=9,s2=10,s3=11; // port definition of color sensor
int out=2;
int flag=0;  // initialization
int counter=0;
int countR=0,countG=0,countB=0;
void setup()
{
  Serial.begin(115200);
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT); 
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT); 
}
 
void TCS()
{
  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);
  attachInterrupt(0, ISR_INTO, CHANGE);
 
}
 
void ISR_INTO()
{
  counter++;
}
 
int Raverage = 0;
int Baverage = 0;
int Gaverage = 0;
 
void loop()       //   call function
{
  TCS();
  if(TcsTrigger.check()){
    Tcstrigger();
  }
  if(processdata.check()){
    procedata();
  }   
  if(ledlightup.check()){ 
   ledup();
  }
 
}
void Tcstrigger()  //   data acquisition
{
      flag++;
    if(flag==1){
      digitalWrite(s2,LOW);
      digitalWrite(s3,LOW);   
      countR=counter;     
      digitalWrite(s2,HIGH);
      digitalWrite(s3,HIGH);
    }     
    else if(flag==2){
      countG=counter;       
      digitalWrite(s2,LOW);
      digitalWrite(s3,HIGH);  
 
    }
    else if(flag==3){
      countB=counter;    
      digitalWrite(s2,LOW);
      digitalWrite(s3,LOW);   
      flag=0; 
    }
    counter=0; 
}
 
void  procedata()        // data processing
{
      static int Rinput[5] ={
      0,0,0,0,0                }
    ,Binput[5] ={
      0,0,0,0,0                }
    ,Ginput[5] ={
      0,0,0,0,0                };
 
    for(int i = 4;i > 0;i--){
      Rinput[i] = Rinput[i-1];
      Binput[i] = Binput[i-1];
      Ginput[i] = Ginput[i-1];
    }
  
    if(countR < 2500)
      Rinput[0] = countR;
    else
      Rinput[0] = Rinput[1];
 
    if(countB < 2500)
      Binput[0] = countB;
    else
      Binput[0] = Binput[1]; 
 
    if(countG < 2500)
      Ginput[0] = countG;
    else
      Ginput[0] = Ginput[1];    
 
    Raverage = 0;
    Baverage = 0;
    Gaverage = 0;
 
    for(int i = 0;i <= 4;i++){
      Raverage += Rinput[i];
      Baverage += Binput[i];
      Gaverage += Ginput[i];
    }
    Raverage /= 5;
    Baverage /= 5;
    Gaverage /= 5;
       
}
 
void  ledup()     // data output
{
    int ledvalueR = Raverage;
    int ledvalueG = Gaverage;
    int ledvalueB = Baverage;
 
    ledvalueR = constrain(ledvalueR,350,1700);
    ledvalueB = constrain(ledvalueB,350,1500);
    ledvalueG = constrain(ledvalueG,350,1650);
     Serial.print("R:");
    Serial.print(Raverage,DEC); 
    Serial.print(" ");
    Serial.print(ledvalueR,DEC); 
    Serial.print("B:");
    Serial.print(Baverage,DEC);
    Serial.print(" ");
    Serial.print(ledvalueB,DEC);
    Serial.print("G:");
    Serial.print(Gaverage,DEC);
    Serial.print(" ");
    Serial.println(ledvalueG,DEC);       
}
