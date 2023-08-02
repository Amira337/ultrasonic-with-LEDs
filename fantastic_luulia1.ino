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
 
  
 if (distance>10&&distance<=85)
 {
      OUT1 =map(distance,10,85,0,255);
   analogWrite(led1,OUT1);
        digitalWrite(led2,0);

 }
  else if (distance>85&&distance<=160)
 {
      OUT2 =map(distance,85,160,0,255);
   analogWrite(led2,OUT2);
      digitalWrite(led3,0);
 }
else if (distance>160&&distance<=235)
 {
      OUT3 =map(distance,160,235,0,255);
   analogWrite(led3,OUT3);
      digitalWrite(led4,0);
}
 else if (distance>235&&distance<=300)
 {
      OUT4 =map(distance,235,300,0,255);
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