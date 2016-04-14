# Rotary-Encoder
Library for a digital rotary encoder for the arduino

Library for simple digital rotary encoder.

Easy to use:

RotEncoder encoder = RotEncoder(2,3); // pins, can be interupt pins

Main public functions:

  encoder.update();   //  Needed to update encoder manually, only needed if the pins arent interrupt pins
  
  int move = encoder.didStep();   // Returns value the encoder moved since last read
  
  encoder.getPosition();    //  Returns position
