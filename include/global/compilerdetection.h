#ifndef _COMPILERDETECTION_H_2020018_
#define _COMPILERDETECTION_H_2020018_

#if defined(__GNUC__)
#  define LIKELY(expr)    __builtin_expect(!!(expr), true)
#  define UNLIKELY(expr)  __builtin_expect(!!(expr), false)
#else
#  define LIKELY(expr) (expr)
#  define UNLIKELY(expr) (expr)
#endif


#endif