#ifndef ROTARY_ENCODER_PA
#define ROTARY_ENCODER_PA

#define READ1 s1= digitalRead(p1);
#define READ1 s2= digitalRead(p2);

class RotEncoder{

  uint8_t p1,p2;

  uint8_t s1,s2;

  uint8_t phase;

  int position;
  int lastRead;

  uin8_t getPhase();
  int8_t difference(uint8_t newPhase, uint8_t phase);
public:
  RotEncoder(uint8_t pinA, uint8_t pinB);

  void update();
  int8_t didStep ();
  int getPosition();
}



#endif
