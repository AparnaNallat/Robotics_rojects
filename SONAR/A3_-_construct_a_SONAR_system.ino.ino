#include <Servo.h>

const int trigPin=10;
const int echoPin=11;

long duration;
int distance;

Servo servo;

void setup() {
  
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  servo.attach(12);
}

void loop()
{
    for(int i=15;i<=180;i++){            // rotates the servo motor from 15 to 180 degrees
    servo.write(i);
    delay(30);
    distance = Distance();

    Serial.print(i);                      // Sends the current angle into the Serial Port
    Serial.print(",");                 
    Serial.print(distance);                // Sends the value of distance the Serial Port
    Serial.print(".");                  
      }

    for(int i=180;i>15;i--){  
    servo.write(i);
    delay(30);
    distance = Distance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
    }

}

int Distance()
{
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
                                                                // Sets the trigPin to HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 
                                                              // Reads the echoPin, stores the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
                                                              // Calculating the distance
  distance= duration*0.034/2;                                // Range : 2cm to 400 cm

  return distance;
}
