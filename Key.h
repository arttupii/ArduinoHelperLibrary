#ifndef __Key_h__
#define __Key_h__
#include "Millis.h"

class Key {
  public:
    Key(int key);
    ~Key();
    bool isPressed(long t = 0);
  private:
    int key;
    bool last_state;
    //long tick;
    Millis ms;
};
#endif