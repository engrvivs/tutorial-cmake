#include <iostream>

#include "MathFunctions.h"

#if defined(HAVE_LOG) && defined(HAVE_EXP)
// simulate usage of platform-specific functions
#include <cmath>
#else
// include the generated table
#include "Table.h"
#endif

namespace mathfunctions {
namespace detail {
// a hack square root calculation using simple operations
double mysqrt(double x) {
  if (x <= 0) {
    return 0;
  }

#if defined(HAVE_LOG) && defined(HAVE_EXP)
  // the platform provides desired features
  double result = exp(log(x) * 0.5);
  std::cout << "Computing sqrt of " << x << " to be " << result
            << " using log and exp" << std::endl;
#else
  // use table to help find an initial value
  double result = x;
  if (x >= 1 && x < 10) {
    std::cout << "Use the table to help find an initial value " << std::endl;
    result = sqrtTable[static_cast<int>(x)];
  }

  for (int i = 0; i < 10; ++i) {
    if (result <= 0) {
      result = 0.1;
    }
    double delta = x - (result * result);
    result += 0.5 * delta / result;
    std::cout << "Computing sqrt of " << x << " to be " << result << std::endl;
  }
#endif

  return result;
}
} // namespace detail
} // namespace mathfunctions