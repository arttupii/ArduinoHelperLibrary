#include "Millis.h"
#include "Key.h"

Key::Key(int key) {
  this->key = key;
  last_state = false;
  pinMode(key, INPUT);
}

Key::~Key() {}

bool Key::isPressed(long t = 0) {
  bool c = digitalRead(key);
  bool ret = false;
  if (c == true && last_state == false) {
    if (t > 0) {
      ms.setTime(t);
    } else {
      ret = true;
    }
  }
  if (t > 0 && ms.check() && c) {
    ret = true;
    ms.setTime(t);
  }
  if (t > 0 && c == false) {
    ms.setTime(t);
  }
  last_state = c;
  return ret;
}
