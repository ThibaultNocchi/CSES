#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  std::string l;
  getline(std::cin, l);

  unsigned int occ = 1, max = 1;

  for (unsigned int i = 1; i < l.size(); ++i) {
    if (l[i] != l[i - 1]) {
      occ = 1;
      if (max >= l.size() - i)
        break;
    } else {
      ++occ;
      if (occ > max)
        max = occ;
    }
  }

  std::cout << max << std::endl;

  return 0;
}
