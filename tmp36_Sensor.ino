const int TempPin = A0;
const int Rpin = 6;
const int Gpin = 7;
const int Buzzpin = 5;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(TempPin,INPUT);
pinMode(Rpin,OUTPUT);
pinMode(Gpin,OUTPUT);
pinMode(Buzzpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
float temp = getTemp();
Serial.print("Temperature = ");
Serial.print(temp);
Serial.println("°C");
if(temp>33.00)
{
  digitalWrite(Rpin,HIGH);
  digitalWrite(Buzzpin,HIGH);
  Serial.println("Temperature is Critical");
  digitalWrite(Gpin,LOW);
}
else
{
  digitalWrite(Rpin,LOW);
  digitalWrite(Buzzpin,LOW);
  Serial.println("Temperature is Normal");
  digitalWrite(Gpin,HIGH);
}
delay(10000);
}
double getTemp()
{
  float tmp = analogRead(TempPin);
  float val;
  float dtemp;
  val=(tmp*5)/1024;
  dtemp=(val*100);
  return dtemp;
}
