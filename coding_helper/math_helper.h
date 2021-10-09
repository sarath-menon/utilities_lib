#pragma once
#include <cmath>

namespace math_helper {

// Constrains input value to a range
inline constexpr static float limit(float val, const float max,
                                    const float min) {
  if (val > max)
    val = max;
  else if (val < min)
    val = min;
  return val;
}

} // namespace math_helper