const int trigger = 9; //Trigger pin of 1st Sensor
const int echo = A3; //Echo pin of 1st Sensor
const int Buzz = 13; //Echo pin of 1st Sensor
const int Remote = A0; //Echo pin of 1st Sensor
const int Light = A1; //Echo pin of 1st Sensor

long time_taken;
long dist;
int Signal;
int Intens;
int similar_count;

void setup() {
Serial.begin(9600); 

pinMode(Buzz,OUTPUT);
pinMode(trigger, OUTPUT); 
pinMode(echo, INPUT); 

}

/*###Function to calculate distance###*/
/*void calculate_distance(int trigger, int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);

time_taken = pulseIn(echo, HIGH);
dist= time_taken*0.034/2;
if (dist>300)
dist=300;
}*/

void loop() { //infinite loopy
  digitalWrite(Buzz,LOW);
  digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
time_taken = pulseIn(echo, HIGH);
dist= (time_taken/2)/29.1;

Signal = digitalRead(Remote);
//Intens = analogRead(Light);

//Check if Remote is pressed
int temp = analogRead(Remote);
/*if(temp)
{
  Serial.print("yes i am pressed  ");

}*/
similar_count=0;
while (Signal==temp)
{
 Signal = analogRead(Remote);
 similar_count++;
 Serial.print(similar_count);
}

//If remote pressed
if (similar_count<50)
{
  Serial.println("Remote Pressed");
  digitalWrite(Buzz,HIGH);
  delay(3000);
  digitalWrite(Buzz,LOW);
}
else
{
 Serial.print("remote not pressed");
 digitalWrite(Buzz,LOW);
 return;
 
}
if (dist < 50)
{
  Serial.println(dist);
  Serial.println("Object Alert");
    digitalWrite(Buzz,HIGH);
    delay(1000);

  digitalWrite(Buzz,LOW);
 
    delay(1000);
    
}
else
{
  return;
}
/*
Serial.println(Intens);
//If very dark
if(Light)
{
  
}
if (Intens<200)
{
  Serial.print(Intens); 
  Serial.println("Low Light");
  digitalWrite(Buzz,HIGH);
  delay(2000);
  digitalWrite(Buzz,LOW);
  delay(2000);
  digitalWrite(Buzz,HIGH);
  delay(2000);
  digitalWrite(Buzz,LOW);
  delay(2000);
  delay(5000);
}

//If very bright
if (Intens>800)
{
  Serial.print(Intens); 
  Serial.println("Bright Light");
  digitalWrite(Buzz,HIGH);
  delay(5000);
  digitalWrite(Buzz,LOW);
  delay(5000);
  digitalWrite(Buzz,HIGH);
  delay(5000);
  digitalWrite(Buzz,LOW);
  delay(5000);
}
*/


//Serial.print("dist=");
//Serial.println(dist);
//Serial.print("Similar_count=");
//Serial.println(similar_count);
//Serial.print("Intens=");
//Serial.println(Intens);
}

