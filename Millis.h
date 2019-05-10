#ifndef __Millis_h__
#define __Millis_h__
#include <Arduino.h>

class Millis {
  public:
    Millis(unsigned us = 0) {
      if (us != 0) {
        setTime(us);
      }
    }
    ~Millis() {}
    setTime(unsigned long us) {
      reset(millis());
      this->us = us;
    }
    reset(unsigned long us = 0) {
      if (us != 0) {
        start = us;
      } else {
        start = millis();
      }
    }
    bool check() {
      now = millis();
      elapsed = now - start;
      return (elapsed >= us);
    }
  private:
    unsigned long now, elapsed;
    unsigned long start;
    unsigned long us;
};
#endif