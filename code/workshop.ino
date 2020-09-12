// Code for Arduino Uno

int trig = 11;
int echo = 12;

int motorLeft1 = 2;
int motorLeft2 = 3;
int motorRight1 = 4;
int motorRight2 = 5;

void forward() {
  digitalWrite(motorLeft1, HIGH);
  digitalWrite(motorLeft2, LOW);
  digitalWrite(motorRight1, HIGH);
  digitalWrite(motorRight2, LOW);
}

void backward() {
  digitalWrite(motorLeft1, LOW);
  digitalWrite(motorLeft2, HIGH);
  digitalWrite(motorRight1, LOW);
  digitalWrite(motorRight2, HIGH);
}

void left() {
  digitalWrite(motorLeft1, HIGH);
  digitalWrite(motorLeft2, LOW);
  digitalWrite(motorRight1, LOW);
  digitalWrite(motorRight2, HIGH);
}

void right() {
  digitalWrite(motorLeft1, LOW);
  digitalWrite(motorLeft2, HIGH);
  digitalWrite(motorRight1, HIGH);
  digitalWrite(motorRight2, LOW);
}

void setup() {
  // begin serial, 9600 is the standard baudrate (speed of communication)
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  forward();
  // pulse the Ultrasonic Sensor for 10 microseconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // wait until the echo pin has a response
  int duration = pulseIn(echo, HIGH);

  
  Serial.println(duration);

  
}
