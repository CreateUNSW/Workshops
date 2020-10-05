/* UNSW CREATExGirls in Engineering: Smart Sensing Workshop */


const int buzzer = 9; //buzzer to arduino pin 9
const int Trig = 12; //Trigger connected to PIN 12   
const int Echo = 10; //Echo connected to PIN 10  


void setup(){
  Serial.begin(9600);   
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

}

void loop(){

  long duration, cm;
  pinMode(Trig, OUTPUT);   
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);   
  digitalWrite(Trig, HIGH);   
  delayMicroseconds(5);   
  digitalWrite(Trig, LOW);   
  pinMode(Echo, INPUT);
  duration = pulseIn(Echo, HIGH); 
  cm = microsecondsToCentimeters(duration);   

  if(cm>0 && cm <=100){ 
    tone(buzzer, 10000); // Send 10000Hz sound signal...
    delay(cm*7);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(cm*7);        // ...for 1sec
  }
  
  //Print to Serial output
  Serial.print(cm);    
  Serial.print("cm");   
  Serial.println();   
  delay(100); 
}   

//Converts microseconds to centimeters
long microsecondsToCentimeters(long microseconds){   
  return microseconds / 29 / 2;   
}
