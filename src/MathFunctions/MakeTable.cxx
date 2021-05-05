// to generate an sqrt table of precomputed values to use in mysqrt function
#include <cmath>
#include <fstream>

int main(int argc, char *argv[]) {
  // ensure enough arguments
  if (argc < 1) {
    return 1;
  }

  std::ofstream fout(argv[1], std::ios_base::out);
  const bool fileOpen = fout.is_open();
  if (fileOpen) {
    fout << "double sqrtTable[] = {" << std::endl;
    for (int i = 0; i < 10; ++i) {
      fout << sqrt(static_cast<double>(i)) << "," << std::endl;
    }
    // close the table with a zero
    fout << "0};" << std::endl;
    fout.close();
  }

  // return 0, if wrote the file
  return fileOpen ? 0 : 1;
}