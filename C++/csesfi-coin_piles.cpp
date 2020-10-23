// https://cses.fi/problemset/task/1754

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;

int main(int argc, char const *argv[]) {
  std::ios::sync_with_stdio(false);
  unsigned int t;
  unsigned int a, b;

  cin >> t;

  for (unsigned int i = 0; i < t; ++i) {
    cin >> a >> b;
    if (a == 0 && b == 0)
      cout << "YES\n";
    else if ((a == 0 && b != 0) || (a != 0 && b == 0))
      cout << "NO\n";
    else if ((a < b && a * 2 < b) || (b < a && b * 2 < a))
      cout << "NO\n";
    else if ((a + b) % 3 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
