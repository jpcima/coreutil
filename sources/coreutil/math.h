#pragma once

namespace coreutil {

//------------------------------------------------------------------------------
// math constants
//------------------------------------------------------------------------------

// This file provides math constants computed with 21 significant digits,
// which provides the maximum precision of IEEE quad floating-point numbers.

// The constants are defined more strictly than by usual C standards. The result
// type of a use expression is determined by its other operand, which must be a
// float. This enforces greater programming discipline wrt. implicit promotions.
//  eg. `2.f * K_PI` is float, `2. * K_PI` is double, `2 * K_PI` is invalid

#define K_E            ::coreutil::math_constant(2.71828182845904523536L)     // e
#define K_LOG2E        ::coreutil::math_constant(1.44269504088896340736L)     // log2(e)
#define K_LOG10E       ::coreutil::math_constant(0.434294481903251827651L)    // log10(e)
#define K_LN2          ::coreutil::math_constant(0.693147180559945309417L)    // log(2)
#define K_LN10         ::coreutil::math_constant(2.30258509299404568402L)     // log(10)
#define K_PI           ::coreutil::math_constant(3.14159265358979323846L)     // pi
#define K_2PI          ::coreutil::math_constant(6.28318530717958647693L)     // 2*pi
#define K_4PI          ::coreutil::math_constant(12.5663706143591729539L)     // 4*pi
#define K_PI_2         ::coreutil::math_constant(1.57079632679489661923L)     // pi/2
#define K_PI_4         ::coreutil::math_constant(0.785398163397448309616L)    // pi/4
#define K_1_PI         ::coreutil::math_constant(0.318309886183790671538L)    // 1/pi
#define K_2_PI         ::coreutil::math_constant(0.636619772367581343076L)    // 2/pi
#define K_4_PI         ::coreutil::math_constant(1.27323954473516268615L)     // 4/pi
#define K_1_SQRTPI     ::coreutil::math_constant(0.564189583547756286948L)    // 1/sqrt(pi)
#define K_2_SQRTPI     ::coreutil::math_constant(1.1283791670955125739L)      // 2/sqrt(pi)
#define K_SQRT2        ::coreutil::math_constant(1.4142135623730950488L)      // sqrt(2)
#define K_1_SQRT2      ::coreutil::math_constant(0.707106781186547524401L)    // 1/sqrt(2)

struct math_constant {
  const long double value;
  explicit constexpr math_constant(long double value);
  template <class T> constexpr /* explicit */ operator T() const;
};

}  // namespace coreutil

#include "math.tcc"
