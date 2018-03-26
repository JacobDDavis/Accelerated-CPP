#include <cmath>
#include <iomanip>
#include <iostream>

int get_width(int n) {
  int ret = std::log10(n) + 1;
  return ret;
}

int main() {
  double max_width = 1000.0;

  for (double i = 1; i <= max_width; ++i) {
    std::cout << std::setw(get_width(max_width)) << i << std::setw(get_width(max_width * max_width) + 1) << i*i << std::endl;
  }
  return 0;
}
