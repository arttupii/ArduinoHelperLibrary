#include "Micros.h"


Micros::Micros(unsigned long  us) {
  if (us != 0) {
    setTime(us);
  }
}

Micros::~Micros() {}

void Micros::setTime(unsigned long  us) {
  reset(micros());
  this->us = us;
}

void Micros::reset(unsigned long  us) {
  if (us != 0) {
    start = us;
  } else {
    start = micros();
  }
}

bool Micros::check() {
  now = micros();
  elapsed = now - start;
  return (elapsed >= us);
}