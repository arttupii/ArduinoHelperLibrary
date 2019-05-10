#include "millis.h"
#include <Arduino.h>

Millis::Millis(unsigned long us = 0) {
  if (us != 0) {
    setTime(us);
  }
}

Millis::~Millis() {}

void Millis::setTime(unsigned long us) {
  reset(millis());
  this->us = us;
}

void Millis::reset(unsigned long us = 0) {
  if (us != 0) {
    start = us;
  } else {
    start = millis();
  }
}

bool Millis::check() {
  now = millis();
  elapsed = now - start;
  return (elapsed >= us);
}
