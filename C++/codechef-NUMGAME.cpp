// https://www.codechef.com/problems/NUMGAME/

#include <iostream>

using std::cin;
using std::cout;

int main(int argc, char const *argv[]) {
  std::ios::sync_with_stdio(false);
  unsigned int t;
  unsigned int n;

  cin >> t;

  for (unsigned int i = 0; i < t; ++i) {
    cin >> n;
    if (n % 2 == 0)
      cout << "ALICE\n";
    else
      cout << "BOB\n";
  }
}
