/*
Adafruit Arduino - Lesson 15. Bi-directional Motor */
#include <IRremote.h>
# define IDLE 0
# define FORWARD 1
# define BACKWARD 2
int state;
int cont_state;

int enablePin = 11;
int in1Pin = 10;
int in2Pin = 9;
int potPin = 0;

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(in1Pin, OUTPUT); 
  pinMode(in2Pin, OUTPUT); 
  pinMode(enablePin, OUTPUT); 
  pinMode(switchPin, INPUT_PULLUP);
  state = 0;
  cont_state;
}
void loop() {
  if (irrecv.decode(&results)){
        int remote_val = results.value;
        Serial.println(results.value, HEX);
        irrecv.resume();
  } else {
    state = IDLE;
  }
  
  switch(state){
    case(IDLE):
      if(remote_val == 0xFFA857){
        state = FORWARD;
        cont_state = FORWARD;
      }
      if(remote_val == 0xFFE01F){
        state = BACKWARD;
        cont_state = BACKWARD;
      }
      break;
    case(FORWARD):
      //Put code to go forward here
      if(remote_val == 0xFFFFFF && cont_val == FORWARD){
        //continue to go forward
      }
      if(remote_val == 0xFFE01F){
        state = BACKWARD;
        cont_state == BACKWARD;
      }
      break;
    case(BACKWARD):
      //Put code to go backward here
      if(remote_val == 0xFFFFFF && cont_val == BACKWARD){
        //continue to go backward
      }
      if(remote_val == 0xFFA857){
        state = FORWARD;
        cont_state == FORWARD;
      }
      break;
  }
  int speed = analogRead(potPin) / 4; 
  boolean reverse = digitalRead(switchPin); 
  setMotor(speed, reverse);
}
void setMotor(int speed, boolean reverse) {
analogWrite(enablePin, speed); digitalWrite(in1Pin, ! reverse); digitalWrite(in2Pin, reverse);
}