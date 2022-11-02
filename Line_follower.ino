//#include <NewPing.h>

int rightmotor1=12;
int leftmotor1=10;
int rightmotor2=13;
int leftmotor2=11;

#define trigPin 7
#define echoPin 6
//#define MAX_DISTANCE 60 
//NewPing sonar(trigPin, echoPin , MAX_DISTANCE);

int sensorleft=2;
int sensorcenter=3;
int sensorright=4;


int l1=1;
int l2=1;
int l3=1;

int f1=0;
int f2=0;
int f3=0;
int servo=9;
//int pulse=4000;
//float dist;
//////////////////////////////////////

void setup()
{

 pinMode(rightmotor1,OUTPUT);
 pinMode(leftmotor1,OUTPUT);
 pinMode(rightmotor2,OUTPUT);
 pinMode(leftmotor2,OUTPUT);

 pinMode(sensorleft,INPUT);
 pinMode(sensorcenter,INPUT);
 pinMode(sensorright,INPUT);
 pinMode(servo,OUTPUT);

Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


}
///////////////////////////////////////////////////

void loop()
{
l1=digitalRead(sensorleft);
l2=digitalRead(sensorcenter);
l3=digitalRead(sensorright);

 // dist= sonar.ping_cm();
  //Serial.print(dist);

int duration, dist;
digitalWrite(trigPin,HIGH);
delayMicroseconds(1000);
digitalWrite(trigPin,LOW);
duration= pulseIn(echoPin,HIGH);
dist= (duration/2)/29.1;
/////////////////////////////////////////////////////////////////////
if (dist<20)
{
    digitalWrite(rightmotor1,0);
  digitalWrite(rightmotor2,0);
  digitalWrite(leftmotor1,0);
  digitalWrite(leftmotor2,0);
}
else 
{
if(l1==1&&l2==1&&l3==1)   //feedback when comes all sensor on white
{
l1=f1;
l2=f2;
l3=f3;
}

////////////////////////////////////////////////////////////////////////////
if(l1==0&&l2==1&&l3==1||l1==0&&l2==0&&l3==1)   //left turn
{
  digitalWrite(rightmotor1,1);
  digitalWrite(rightmotor2,0);
  digitalWrite(leftmotor1,1);
  digitalWrite(leftmotor2,0);
}
else if(l1==1&&l2==1&&l3==0||l1==1&&l2==0&&l3==0)  //right turn
{
  digitalWrite(rightmotor1,0);
  digitalWrite(rightmotor2,1);
  digitalWrite(leftmotor1,0);
  digitalWrite(leftmotor2,1);
}
else if(l1==1&&l2==0&&l3==1)  //go forward straight
{
  digitalWrite(rightmotor1,1);
  digitalWrite(rightmotor2,0);
  digitalWrite(leftmotor1,0);
  digitalWrite(leftmotor2,1);
}
else if(l1==0&&l2==0&&l3==0) //stop
{
  digitalWrite(rightmotor1,0);
  digitalWrite(rightmotor2,0);
  digitalWrite(leftmotor1,0);
  digitalWrite(leftmotor2,0);
  digitalWrite(servo,HIGH);
  delayMicroseconds(4000);
    digitalWrite(servo,LOW);
    delay(20);   
}
///////////////////////////////////////////////////////////////////
f1=l1;
f2=l2;
f3=l3;        //memory variables
////////////////////////////////////////////////////////////////////

}}
