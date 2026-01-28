#pragma once
#include <cmath>
#include <complex>
#include <numbers>
#include <vector>

namespace Package::Core {
using Complex = std::complex<double>;
using ComplexVector = std::vector<Complex>;

class FFT {
public:
  static ComplexVector Forward(const ComplexVector &input);
  static ComplexVector Inverse(const ComplexVector &input);

private:
  static void RecursiveCompute(ComplexVector &a, bool invert);
};
} // namespace Package::Core