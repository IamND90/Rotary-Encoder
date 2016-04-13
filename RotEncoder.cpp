#include "RotEncoder.h"

#define PHASES 4



RotEncoder::RotEncoder(uint8_t pinA, uint8_t pinB){
  p1= pinA;
  p2 = pinB;
  READ1
  READ2
  position =0;
  lastRead =0;
  phase = getPhase();
}


void RotEncoder::update(){
  uint8_t old1 = s1;
  uint8_t old2 = s2;
  READ1
  READ2
  uint8_t newPhase = getPhase();


  if(old1 == p1 && old2 == p2){
    return;
  }

  int8_t diff = difference(newPhase, phase);

  position += diff;

}


int8_t RotEncoder::didStep (){
  update();
  return lastRead = (position - lastRead);
}


int RotEncoder::getPosition(){
  return position;
}


uin8_t RotEncoder::getPhase(){
    return (!s1 && !s2 ? 0 : (!s1 && !s2) ? 1: ( s1 && !s2) ? 2 : 3);
}
int8_t RotEncoder::difference(uint8_t newPhase, uint8_t phase){
  if(phase == 3){
    if(newPhase == 0)return 1;
    else return -1;
  }
  if(phase == 0){
    if(newPhase == 3) return -1;
    else return 1;
  }
  return newPhase -phase;

}
