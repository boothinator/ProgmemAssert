// Copyright (C) 2023  Joshua Booth
// MIT License

#include <Arduino.h>
#include <unity.h>

#include "PROGMEMAssert.h"

bool callbackCalled = false;

bool __pgmAssertCallback(PGM_P __file, int __lineno, PGM_P __sexp)
{
  callbackCalled = true;
  return true;
}

void test_callback()
{
  assert(false);
  interrupts();

  TEST_ASSERT_TRUE(callbackCalled);
}

void setup() {
  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  delay(2000);

  UNITY_BEGIN();    // IMPORTANT LINE!

  RUN_TEST(test_callback);

  UNITY_END(); // stop unit testing
}

void loop() {
}