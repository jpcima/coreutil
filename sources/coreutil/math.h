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

COREUTIL_DEFINE_MATH_CONSTANT(K_E, 2.7182818284590450908L);
COREUTIL_DEFINE_MATH_CONSTANT(K_LOG2E, 1.442695040888963387L);
COREUTIL_DEFINE_MATH_CONSTANT(K_LOG10E, 0.434294481903251816668L);
COREUTIL_DEFINE_MATH_CONSTANT(K_LN2, 0.693147180559945286227L);
COREUTIL_DEFINE_MATH_CONSTANT(K_LN10, 2.30258509299404590109L);
COREUTIL_DEFINE_MATH_CONSTANT(K_PI, 3.14159265358979323846L);
COREUTIL_DEFINE_MATH_CONSTANT(K_2PI, 6.283185307179586232L);
COREUTIL_DEFINE_MATH_CONSTANT(K_4PI, 12.566370614359172464L);
COREUTIL_DEFINE_MATH_CONSTANT(K_PI_2, 1.570796326794896558L);
COREUTIL_DEFINE_MATH_CONSTANT(K_PI_4, 0.785398163397448278999L);
COREUTIL_DEFINE_MATH_CONSTANT(K_1_PI, 0.318309886183790691216L);
COREUTIL_DEFINE_MATH_CONSTANT(K_2_PI, 0.636619772367581382433L);
COREUTIL_DEFINE_MATH_CONSTANT(K_4_PI, 1.27323954473516276487L);
COREUTIL_DEFINE_MATH_CONSTANT(K_1_SQRTPI, 0.56418958354775627928L);
COREUTIL_DEFINE_MATH_CONSTANT(K_2_SQRTPI, 1.12837916709551255856L);
COREUTIL_DEFINE_MATH_CONSTANT(K_SQRT2, 1.41421356237309514547L);
COREUTIL_DEFINE_MATH_CONSTANT(K_1_SQRT2, 0.707106781186547461715L);
