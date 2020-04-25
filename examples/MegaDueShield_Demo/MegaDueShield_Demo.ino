#include <MegaDueShield.h>




void setup() {
  MegaDueShield shield {};
  DC_Motor* m8 = shield.getDCMotor(8);

  m8->cw();
  delay(2000);
  //m8->stop();
}

void loop() {
  // put your main code here, to run repeatedly:

}
