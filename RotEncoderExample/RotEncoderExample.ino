
#include "RotEncoder.h"

// Uncomment if you have less or more that 2 encoders, uses more space if more defined that used
#define MAX_INTERRUPT_ENCODERS 1

// init your encoders, the ones with the interrupts first
RotEncoder encoder(2,3);  // 2,3 are inteerupt pins
RotEncoder encoderNoInterrupt(4,5);

void setup() {
  Serial.begin(9600);
  
  // example set start position to 90 ( 0 is default)
  encoder.setPosition(90);
}

void loop() {
  
  // encoder one is with interrupt pins, just check whether it has moved
  int move = encoder.didStep();
  if(move != 0){
    Serial.print("Position E1:");
    Serial.print(encoder.getPosition(),DEC);
    Serial.print(", Move:");
    Serial.println(move,DEC);
  }
  
  // this encoder is not connected with interrupt pins, update him manually as often as you can
  // so you dont miss the steps
  encoderNoInterrupt.update();
  
  // now ceck whether it has moved
  move = encoderNoInterrupt.didStep();
  if(move != 0){
    Serial.print("Position E2:");
    Serial.print(encoderNoInterrupt.getPosition(),DEC);
    Serial.print(", Move:");
    Serial.println(move,DEC);
  }
  
}
