#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char const *argv[]) {
  std::string line;
  getline(std::cin, line);

  std::stringstream ss(line);

  unsigned int n;
  ss >> n;

  unsigned int zeros = 0;
  unsigned int i = 5;
  while (i < 1000000000) {
    zeros += n / i;
    i *= 5;
  }

  std::cout << zeros << std::endl;

  return 0;
}
