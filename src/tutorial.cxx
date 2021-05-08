// A simple program that computes the squre root of a number
// step 9: no longer use USE_MYMATH
#include <iostream>

#include "MathFunctions.h"
#include "TutorialConfig.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    // report version
    std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // convert input to double (not through atof)
  const double inputValue = std::stod(argv[1]);

  // calculate square root
  const double outputValue = mathfunctions::sqrt(inputValue);
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;

  return 0;
}
