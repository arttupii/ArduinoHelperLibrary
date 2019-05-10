#ifndef __Micros_h__
#define __Micros_h__
#include <Arduino.h>

class Micros {
  public:
    Micros(unsigned us = 0) {
      if (us != 0) {
        setTime(us);
      }
    }
    ~Micros() {}
    setTime(unsigned long us) {
      reset(micros());
      this->us = us;
    }
    reset(unsigned long us = 0) {
      if (us != 0) {
        start = us;
      } else {
        start = micros();
      }
    }
    bool check() {
      now = micros();
      elapsed = now - start;
      return (elapsed >= us);
    }
  private:
    unsigned long now, elapsed;
    unsigned long start;
    unsigned long us;
};
#endif