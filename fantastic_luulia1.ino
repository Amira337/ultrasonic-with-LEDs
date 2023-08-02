// C++ code
//
int led1=3;
int led2=5;
int led3=6;
int led4=9;
int trig= 13;
int echo= 11;
long duration,distance;

int OUT1;
int OUT2;
int OUT3;
int OUT4;

void setup()
{
    Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(trig, OUTPUT);
 pinMode(echo, INPUT);
}
void ultrasonic()
{
digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
   duration = pulseIn(echo,HIGH);
   distance = (duration/2)*0.0343;
  Serial.println(distance);
  delay(5);
}

void loop()
{
 ultrasonic();
 
  
 if (distance<=100)
 {
      OUT1 =map(distance,0,100,0,255);
   analogWrite(led1,OUT1);
        digitalWrite(led2,0);

 }
  else if (distance>100&&distance<=200)
 {
      OUT2 =map(distance,100,200,0,255);
   analogWrite(led2,OUT2);
      digitalWrite(led3,0);
 }
else if (distance>200&&distance<=300)
 {
      OUT3 =map(distance,200,300,0,255);
   analogWrite(led3,OUT3);
      digitalWrite(led4,0);
}
 else if (distance>300)
 {
      OUT4 =map(distance,300,400,0,255);
   analogWrite(led4,OUT4);
  }
 
  else
  {
    digitalWrite(led1,0);
    digitalWrite(led2,0);
     digitalWrite(led3,0);
    digitalWrite(led4,0);
  }

   
  
}