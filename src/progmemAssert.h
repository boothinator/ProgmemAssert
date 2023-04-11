// Copyright (C) 2022  Joshua Booth
// MIT License

#ifndef PROGMEM_ASSERT_H_
#define PROGMEM_ASSERT_H_

#undef assert

#ifdef NDEBUG

#define assert(e)	((void)0)

#else // NDEBUG

#ifndef PGM_ASSERT_PRINT
  #define PGM_ASSERT_PRINT 0
#endif

#include <avr/pgmspace.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Called when assert fails
 *
 * Define this function in your code to respond when an assert fails.
 * Called after interrupts are disabled, but before the message is logged to serial.
 * 
 */
extern void __pgmAssertCallback(PGM_P __file, int __lineno, PGM_P __sexp) __attribute__((weak));

extern void __pgmAssert(PGM_P __file, int __lineno, PGM_P __sexp);

#define assert(e)	((e) ? (void)0 : __pgmAssert(PSTR(__FILE__), __LINE__, PSTR(#e)))

#ifdef __cplusplus
}
#endif

#endif // NDEBUG

#endif // PROGMEM_ASSERT_H_