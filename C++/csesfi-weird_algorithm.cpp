#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
  unsigned long long n;
  std::cin >> n;

  std::vector<unsigned long long> l({n});

  while (n != 1) {
    if (n % 2 == 0) // EVEN
      n /= 2;
    else // ODD
      n = n * 3 + 1;
    l.push_back(n);
  }

  for (const auto &v : l)
    std::cout << v << " ";
  std::cout << std::endl;

  return 0;
}
