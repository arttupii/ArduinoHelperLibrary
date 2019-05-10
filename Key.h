#ifndef __Micros_h__
#define __Micros_h__
#include "Millis.h"

class Key {
  public:
    Key(int key) {
      this->key = key;
      last_state = false;
    }
    ~Key() {}
    bool isPressed(long t = 0) {
      bool c = !digitalRead(key);
      bool ret = false;
      if (c == true && last_state == false) {
        if (t > 0) {
          //tick = millis();
          ms.setTime(t);
        } else {
          ret = true;
        }
      }
      if (t > 0 && /*(millis() - tick) > t*/ ms.check() && c) {
        ret = true;
        //tick = millis();
        ms.setTime(t);
      }
      if (t > 0 && c == false) {
        //tick = millis();
        ms.setTime(t);
      }
      last_state = c;
      return ret;
    }
  private:
    int key;
    bool last_state;
    //long tick;
    Millis = ms;
};
#endif