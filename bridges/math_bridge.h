#ifndef __FLOAT_BRIDGE_H__
#define __FLOAT_BRIDGE_H__
// Convert from softfp to hardfp

#include "platform.h"

#include <math.h>
#include <complex.h>

#define MATH_BRIDGE_DEFS \
    FB_DECL_FWD(lrand48,     long int,      (),     ())                         \
    FB_DECL_FWD(srand48,     void,          (x),    (long int    x))            \
    FB_DECL_FWD(acosf,       float,         (x),    (float       x))            \
    FB_DECL_FWD(acoshf,      float,         (x),    (float       x))            \
    FB_DECL_FWD(asinf,       float,         (x),    (float       x))            \
    FB_DECL_FWD(asinhf,      float,         (x),    (float       x))            \
    FB_DECL_FWD(atanf,       float,         (x),    (float       x))            \
    FB_DECL_FWD(atanhf,      float,         (x),    (float       x))            \
    FB_DECL_FWD(cargf,       float,         (x),    (float       x))            \
    FB_DECL_FWD(cbrtf,       float,         (x),    (float       x))            \
    FB_DECL_FWD(ceilf,       float,         (x),    (float       x))            \
    FB_DECL_FWD(cosf,        float,         (x),    (float       x))            \
    FB_DECL_FWD(coshf,       float,         (x),    (float       x))            \
    FB_DECL_FWD(erfcf,       float,         (x),    (float       x))            \
    FB_DECL_FWD(erff,        float,         (x),    (float       x))            \
    FB_DECL_FWD(exp2f,       float,         (x),    (float       x))            \
    FB_DECL_FWD(expf,        float,         (x),    (float       x))            \
    FB_DECL_FWD(expm1f,      float,         (x),    (float       x))            \
    FB_DECL_FWD(fabsf,       float,         (x),    (float       x))            \
    FB_DECL_FWD(fabs,        double,        (x),    (double      x))            \
    FB_DECL_FWD(floorf,      float,         (x),    (float       x))            \
    FB_DECL_FWD(floor,       double,        (x),    (double      x))            \
    FB_DECL_FWD(ilogbf,      int,           (x),    (float       x))            \
    FB_DECL_FWD(lgammaf,     float,         (x),    (float       x))            \
    FB_DECL_FWD(llroundf,    long long,     (x),    (float       x))            \
    FB_DECL_FWD(log10f,      float,         (x),    (float       x))            \
    FB_DECL_FWD(log1pf,      float,         (x),    (float       x))            \
    FB_DECL_FWD(log2f,       float,         (x),    (float       x))            \
    FB_DECL_FWD(logbf,       float,         (x),    (float       x))            \
    FB_DECL_FWD(logf,        float,         (x),    (float       x))            \
    FB_DECL_FWD(lroundf,     long,          (x),    (float       x))            \
    FB_DECL_FWD(rintf,       float,         (x),    (float       x))            \
    FB_DECL_FWD(roundf,      float,         (x),    (float       x))            \
    FB_DECL_FWD(sinf,        float,         (x),    (float       x))            \
    FB_DECL_FWD(sinhf,       float,         (x),    (float       x))            \
    FB_DECL_FWD(sqrtf,       float,         (x),    (float       x))            \
    FB_DECL_FWD(tanf,        float,         (x),    (float       x))            \
    FB_DECL_FWD(tanhf,       float,         (x),    (float       x))            \
    FB_DECL_FWD(sqrt,        double,        (x),    (double      x))            \
    FB_DECL_FWD(ceil,        double,        (x),    (double      x))            \
    FB_DECL_FWD(exp,         double,        (x),    (double      x))            \
    FB_DECL_FWD(log,         double,        (x),    (double      x))            \
    FB_DECL_FWD(log10,       double,        (x),    (double      x))            \
    FB_DECL_FWD(sin,         double,        (x),    (double      x))            \
    FB_DECL_FWD(cos,         double,        (x),    (double      x))            \
    FB_DECL_FWD(atan,        double,        (x),    (double      x))            \
    FB_DECL_FWD(acos,        double,        (x),    (double      x))            \
    FB_DECL_FWD(asin,        double,        (x),    (double      x))            \
    FB_DECL_FWD(tan,         double,        (x),    (double      x))            \
    FB_DECL_FWD(lrint,       long int,      (x),    (double      x))            \
    FB_DECL_FWD(llrint,      long long int, (x),    (double      x))            \
    FB_DECL_FWD(lrintf,      long int,      (x),    (float       x))            \
    FB_DECL_FWD(__signbit,   double,        (x),    (double      x))            \
    FB_DECL_FWD(__finite,    double,        (x),    (double      x))            \
    FB_DECL_FWD(__finitef,   float,         (x),    (float       x))            \
    FB_DECL_FWD(isnan,       int,           (x),    (double      x))            \
    FB_DECL_FWD(ldiv,        ldiv_t,        (x, y), (long        x, long    y)) \
    FB_DECL_FWD(copysignf,   float,         (x, y), (float       x, float   y)) \
    FB_DECL_FWD(fmodf,       float,         (x, y), (float       x, float   y)) \
    FB_DECL_FWD(atan2f,      float,         (x, y), (float       x, float   y)) \
    FB_DECL_FWD(hypotf,      float,         (x, y), (float       x, float   y)) \
    FB_DECL_FWD(ldexpf,      float,         (x, y), (float       x, int     y)) \
    FB_DECL_FWD(frexpf,      float,         (x, y), (float       x, int    *y)) \
    FB_DECL_FWD(modff,       float,         (x, y), (float       x, float  *y)) \
    FB_DECL_FWD(powf,        float,         (x, y), (float       x, float   y)) \
    FB_DECL_FWD(remainderf,  float,         (x, y), (float       x, float   y)) \
    FB_DECL_FWD(scalbnf,     float,         (x, y), (float       x, int     y)) \
    FB_DECL_FWD(fmod,        double,        (x, y), (double      x, double  y)) \
    FB_DECL_FWD(modf,        double,        (x, y), (double      x, double *y)) \
    FB_DECL_FWD(atan2,       double,        (x, y), (double      x, double  y)) \
    FB_DECL_FWD(pow,         double,        (x, y), (double      x, double  y)) \
    FB_DECL_FWD(strtof,      float,         (x, y), (const char *x, char **y)) \
    FB_DECL_FWD(strtod,      double,        (x, y), (const char *x, char **y)) \
    FB_DECL_FWD(atof,        double,        (x),    (const char *x))

#endif /* __FLOAT_BRIDGE_H__ */