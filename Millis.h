#ifndef __Millis_h__
#define __Millis_h__
#include <Arduino.h>

class Millis {
  public:
    Millis(unsigned long us = 0);
    ~Millis();
    void setTime(unsigned long us);
    void reset();
    bool check();
  private:
    unsigned long now, elapsed;
    unsigned long start;
    unsigned long us;
};
#endif