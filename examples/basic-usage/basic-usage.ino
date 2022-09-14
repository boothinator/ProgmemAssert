#include <Arduino.h>
#include "pgmAssert.h"

void setup()
{
  // You can omit the following line by having pgmAssert start the Serial interface instead.
  // Simply send the -DPGM_ASSERT_SERIAL_BEGIN=1 commandline parameter to the compiler.
  // To change the baud rate, send -DPGM_ASSERT_BAUD=baud to the compiler.
  //
  // To set these options using the Arduino IDE, run the IDE from the command line this way:
  // arduino --pref compiler.cpp.extra_flags="-DPGM_ASSERT_SERIAL_BEGIN=1 -DPGM_ASSERT_BAUD=115200"
  //
  // To set these options using PlatformIO, add the following line to platformio.ini in [env]
  // [env]
  // build_flags = -DPGM_ASSERT_SERIAL_BEGIN=1 -DPGM_ASSERT_BAUD=115200
  Serial.begin(9600);

  assert(false);
}

void loop()
{

}
