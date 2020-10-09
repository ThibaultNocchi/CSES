#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {

  unsigned int n;
  std::cin >> n;

  std::string l;

  getline(std::cin, l);
  getline(std::cin, l);

  unsigned int number;
  std::stringstream ss(l);
  std::vector<unsigned int> v;
  v.clear();

  while (ss >> number)
    v.push_back(number);

  std::sort(v.begin(), v.end());

  unsigned int res = n;

  for (unsigned int i = 0; i < v.size(); ++i) {
    if (v[i] != i + 1) {
      res = i + 1;
      break;
    }
  }

  std::cout << res << std::endl;

  return 0;
}
