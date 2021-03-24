// CREATE Amazing Race code
// Uses an ultrasonic sensor to turn on a leds based on distance
// By Jack Robbers
// Based on code by Jeremy

#include <CircularBuffer.h>

#define TRIG 9
#define ECHO 10
#define GREEN 2
#define YELLOW 3
#define RED 4
#define BUFFER_LENGTH 5

int duration;
CircularBuffer<int, BUFFER_LENGTH> buffer;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Clear
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  buffer.push(pulseIn(ECHO, HIGH));

  duration = 0;
  for (int i = 0; i < buffer.size(); i++) {
    if (buffer[i] > 3000 || buffer[i] < 0) {
       duration += 50000;
    } else {
       duration += buffer[i];
    }
    
  }
  duration /= buffer.size();

  Serial.print(duration);
  Serial.print(" ");
  Serial.println(buffer[0]);

  if (duration < 2000) {
    digitalWrite(GREEN, HIGH);
  } else {
    digitalWrite(GREEN, LOW);
  }

  if (duration < 1250) {
    digitalWrite(YELLOW, HIGH);
  } else {
    digitalWrite(YELLOW, LOW);
  }

  if (duration < 500) {
    digitalWrite(RED, HIGH);
  } else {
    digitalWrite(RED, LOW);
  }
}