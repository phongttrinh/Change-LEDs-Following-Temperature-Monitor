//Phong Thanh Trinh
int const greenPin = 8;
int const yellowPin = 9;
int const redPin = 10;
int const sensorPin = A5;
float sensorOutput = 0.0;
float voltage;
float initialT;
float actualT;
float dT;


void setup(){
pinMode(greenPin,OUTPUT);
pinMode(redPin,OUTPUT);
pinMode(yellowPin,OUTPUT);
pinMode(sensorPin,INPUT);
Serial.begin(9600);
}


void loop(){
  
if (sensorOutput = 0){

sensorOutput = analogRead(sensorPin);
voltage = sensorOutput * 5.0/ 1023.0;
initialT = (voltage - 0.5652)/0.008696;// Need a line to Transform voltage[V] into initialT here
Serial.print("Initial temperature is: \t ");
Serial.print(initialT);
Serial.println("\t C"); }

else{  
sensorOutput = analogRead(sensorPin);
voltage = sensorOutput * 5.0/ 1023.0;
actualT = (voltage - 0.5652)/0.008696;// Need a line to Transform voltage[V] into actualT here
dT = max(initialT, actualT) - min(initialT, actualT);

  if (dT < 20) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, LOW);}
  else if (dT >=20&& dT < 40){
    digitalWrite(greenPin, HIGH);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(redPin, LOW);}
  else {
    digitalWrite(greenPin,LOW);
    digitalWrite(yellowPin,LOW);
    digitalWrite(redPin,HIGH);}
  
Serial.print("Initial temperature is: \t ");
Serial.print(actualT);
Serial.println("\t C"); }
}
