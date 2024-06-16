
// turn LED on when light levels drop too low
const int led = 13;
const int sensor_pin = A0;
int motorSpeedPin = 3;
int motorDirection1 = 4;
int motorDirection2 = 5;
int sensor;


const int threshold = 500; // threshold to turn LED on
void setup(){ // setup code that only runs once
pinMode(led, OUTPUT); // set LED pin as output
Serial.begin(9600);


// initialize serial communication
pinMode(motorSpeedPin, OUTPUT);
  pinMode(motorDirection1, OUTPUT);
  pinMode(motorDirection2, OUTPUT);
}


void loop(){ // code that loops forever
sensor= analogRead(sensor_pin);
// read sensor value
Serial.println(sensor);
// print sensor value
if (sensor<threshold){// if sensor reading is less than threshold
digitalWrite(led, HIGH);


  analogWrite(motorSpeedPin,200);
  digitalWrite(motorDirection1, HIGH);
  digitalWrite(motorDirection2, LOW);

} // turn LED on
else{
// else, if sensor reading is greater than threshold
digitalWrite(led, LOW) ; // turn LED off
  analogWrite(motorSpeedPin,200);
  digitalWrite(motorDirection1, LOW);
  digitalWrite(motorDirection2, LOW);

}
}