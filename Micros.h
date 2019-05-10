#ifndef __Micros_hh__
#define __Micros_hh__
#include <Arduino.h>

class Micros {
  public:
    Micros(unsigned long us=0);
    ~Micros();
    void reset(unsigned long us=0);
    void setTime(unsigned long us);
    bool check();
  private:
    unsigned long now, elapsed;
    unsigned long start;
    unsigned long us;
};

#endif