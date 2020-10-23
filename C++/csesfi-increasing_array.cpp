// https://cses.fi/problemset/task/1094

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {

  std::string line;
  getline(std::cin, line);
  getline(std::cin, line);

  std::stringstream ss(line);

  unsigned long long int i, res = 0, previous;
  ss >> previous;
  while (ss >> i) {
    if (i < previous)
      res += previous - i;
    else
      previous = i;
  }

  std::cout << res << std::endl;

  return 0;
}
