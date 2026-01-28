#include "package/core/FFT.hpp"
#include <stdexcept>

namespace Package::Core {
ComplexVector FFT::Forward(const ComplexVector &input) {
  ComplexVector result = input;
  RecursiveCompute(result, false);
  return result;
}

ComplexVector FFT::Inverse(const ComplexVector &input) {
  ComplexVector result = input;
  RecursiveCompute(result, true);

  double n = static_cast<double>(result.size());
  for (auto &val : result) {
    val /= n;
  }
  return result;
}

void FFT::RecursiveCompute(ComplexVector &a, bool invert) {
  size_t n = a.size();
  if (n <= 1)
    return;

  if ((n & (n - 1)) != 0) {
    throw std::invalid_argument("Size must be a power of 2");
  }
}
} // namespace Package::Core