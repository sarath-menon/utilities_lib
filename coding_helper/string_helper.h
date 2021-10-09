#pragma once

namespace string_helper {

// Convert character array to string
inline std::string convertToString(char *a, int size) {
  int i;
  std::string s = "";
  for (i = 0; i < size; i++) {
    s = s + a[i];
  }
  return s;
}
} // namespace string_helper