# PROGMEM Assert

*Assert for Arduino that saves RAM by storing assert strings in PROGMEM and prints to Serial.*

Implementing a standard C assert eats up your RAM because it doesn't know anywhere else to store the debugging strings. This version stores the strings in program memory (PROGMEM) and uses no extra RAM to do so. File name and line number are printed to Serial, and the built-in LED is flashed three times about every 2 seconds.

## Usage

To use, simply add the following lines to your code:

```C
#include <progmemAssert.h>

...

assert(condition);

...
```

If the condition is true, nothing happens. If the condition is false, the assert routine stops your program, flashes the built-in LED three times, and prints the file, line number, and assert condition inside the parenthesis. This process repeats about every 2.6 seconds.

PROGMEM Assert assumes that you've already called Serial.begin(). If you don't want to, you can
have PROGMEM Assert start the Serial interface instead when the assert condition fails.
Simply send the -DPGM_ASSERT_SERIAL_BEGIN=1 commandline parameter to the compiler.
To change the baud rate, send -DPGM_ASSERT_BAUD=baud to the compiler.

To set these options using the Arduino IDE, run the IDE from the command line this way:
```
arduino --pref compiler.cpp.extra_flags="-DPGM_ASSERT_SERIAL_BEGIN=1 -DPGM_ASSERT_BAUD=115200"
```

To set these options using PlatformIO, add the following line to platformio.ini in [env]
```
[env]
build_flags = -DPGM_ASSERT_SERIAL_BEGIN=1 -DPGM_ASSERT_BAUD=115200
```