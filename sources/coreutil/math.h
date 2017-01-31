#pragma once

//------------------------------------------------------------------------------
// math constants
//------------------------------------------------------------------------------

// This file provides math constants computed with 21 significant numbers,
// which provides the maximum precision of IEEE quad floating-point numbers.

// The constants are defined more strictly than by usual C standards. The result
// type of a use expression is determined by its other operand, which must be a
// float. This enforces greater programming discipline wrt. implicit promotions.
//  eg. `2.f * K_PI` is float, `2. * K_PI` is double, `2 * K_PI` is invalid

namespace coreutil {

struct math_constant {
  const long double value;
  explicit constexpr math_constant(long double value);
  template <class T> constexpr /* explicit */ operator T() const;
};

}  // namespace coreutil

#include "math.tcc"

#define COREUTIL_DEFINE_MATH_CONSTANT(id, value)                        \
  [[gnu::unused]] static constexpr ::coreutil::math_constant id(value);

COREUTIL_DEFINE_MATH_CONSTANT(K_E,          2.71828182845904523536L)      // e
COREUTIL_DEFINE_MATH_CONSTANT(K_LOG2E,      1.44269504088896340736L)      // log2(e)
COREUTIL_DEFINE_MATH_CONSTANT(K_LOG10E,     0.434294481903251827651L)     // log10(e)
COREUTIL_DEFINE_MATH_CONSTANT(K_LN2,        0.693147180559945309417L)     // log(2)
COREUTIL_DEFINE_MATH_CONSTANT(K_LN10,       2.30258509299404568402L)      // log(10)
COREUTIL_DEFINE_MATH_CONSTANT(K_PI,         3.14159265358979323846L)      // pi
COREUTIL_DEFINE_MATH_CONSTANT(K_2PI,        6.28318530717958647693L)      // 2*pi
COREUTIL_DEFINE_MATH_CONSTANT(K_4PI,        12.5663706143591729539L)      // 4*pi
COREUTIL_DEFINE_MATH_CONSTANT(K_PI_2,       1.57079632679489661923L)      // pi/2
COREUTIL_DEFINE_MATH_CONSTANT(K_PI_4,       0.785398163397448309616L)     // pi/4
COREUTIL_DEFINE_MATH_CONSTANT(K_1_PI,       0.318309886183790671538L)     // 1/pi
COREUTIL_DEFINE_MATH_CONSTANT(K_2_PI,       0.636619772367581343076L)     // 2/pi
COREUTIL_DEFINE_MATH_CONSTANT(K_4_PI,       1.27323954473516268615L)      // 4/pi
COREUTIL_DEFINE_MATH_CONSTANT(K_1_SQRTPI,   0.564189583547756286948L)     // 1/sqrt(pi)
COREUTIL_DEFINE_MATH_CONSTANT(K_2_SQRTPI,   1.1283791670955125739L)       // 2/sqrt(pi)
COREUTIL_DEFINE_MATH_CONSTANT(K_SQRT2,      1.4142135623730950488L)       // sqrt(2)
COREUTIL_DEFINE_MATH_CONSTANT(K_1_SQRT2,    0.707106781186547524401L)     // 1/sqrt(2)
