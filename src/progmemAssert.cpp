// Copyright (C) 2022  Joshua Booth
// MIT License

#include "progmemAssert.h"

#ifndef NDEBUG

#ifndef PGM_ASSERT_NOIMPL

#ifndef PGM_ASSERT_SERIAL_BEGIN
  #define PGM_ASSERT_SERIAL_BEGIN 0
#endif // PGM_ASSERT_SERIAL_BEGIN

#ifndef PGM_ASSERT_BAUD
  #define PGM_ASSERT_BAUD (9600)
#endif // PGM_ASSERT_BAUD

#include <Arduino.h>

bool __pgmAssertCallback(PGM_P __file, int __lineno, PGM_P __sexp) {
  return false;
}

void __pgmAssert(PGM_P __file, int __lineno, PGM_P __sexp) {
  
#if PGM_ASSERT_SERIAL_BEGIN
  Serial.begin(PGM_ASSERT_BAUD);
#endif

  // abort program execution.

  noInterrupts();

  if (__pgmAssertCallback(__file, __lineno, __sexp))
  {
    return;
  }

  pinMode(LED_BUILTIN, OUTPUT);

  for(;;)
  {
    
    Serial.print(reinterpret_cast<const __FlashStringHelper *>(__file));
    Serial.print(F(", line "));
    Serial.print(__lineno, DEC);
    Serial.print(F(", expr: "));
    Serial.println(reinterpret_cast<const __FlashStringHelper *>(__sexp));
    Serial.flush();

    digitalWrite(LED_BUILTIN, LOW);
    _delay_ms(100);
    digitalWrite(LED_BUILTIN, HIGH);
    _delay_ms(100);
    digitalWrite(LED_BUILTIN, LOW);
    _delay_ms(100);
    digitalWrite(LED_BUILTIN, HIGH);
    _delay_ms(100);
    digitalWrite(LED_BUILTIN, LOW);
    _delay_ms(100);
    digitalWrite(LED_BUILTIN, HIGH);
    _delay_ms(100);
    digitalWrite(LED_BUILTIN, LOW);
    _delay_ms(2000);
  }
}

#endif // PGM_ASSERT_NOIMPL

#endif // NDEBUG