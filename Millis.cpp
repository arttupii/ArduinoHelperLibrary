#include "Millis.h"
#include <Arduino.h>

Millis::Millis(unsigned long us = 0) {
  if (us != 0) {
    setTime(us);
  }
}

Millis::~Millis() {}

void Millis::setTime(unsigned long us) {
  start = millis();
  this->us = us;
}

void Millis::reset() {
  start = millis();
}

bool Millis::check() {
  now = millis();
  elapsed = now - start;
  return (elapsed >= us);
}
