#pragma once
#include "../simd.h"
#if defined(__i386__) || defined(__x86_64__)
# include <x86intrin.h>
#endif

namespace coreutil {

#if (defined(__i386__) || defined(__x86_64__)) && defined(__SSE__)
template <>
inline v4sf simd_loadu(const v4sf *p) {
  return _mm_loadu_ps(reinterpret_cast<const float *>(p));
}
template <>
inline v2sd simd_loadu(const v2sd *p) {
  return _mm_loadu_pd(reinterpret_cast<const double *>(p));
}
#endif

#if (defined(__i386__) || defined(__x86_64__)) && defined(__AVX__)
template <>
inline v8sf simd_loadu(const v8sf *p) {
  return _mm256_loadu_ps(reinterpret_cast<const float *>(p));
}
template <>
inline v4sd simd_loadu(const v4sd *p) {
  return _mm256_loadu_pd(reinterpret_cast<const double *>(p));
}
#endif

}  // namespace coreutil
