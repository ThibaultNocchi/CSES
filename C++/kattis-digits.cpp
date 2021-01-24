#include <cmath>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  unsigned int n;
  cin >> n;
  //   floor(log(n!)) + 1

  unsigned int res = 0;
  for (unsigned int i = 1; i <= n; ++i) {
    res += log(i);
  }
  res = floor(res);
  cout << res << endl;

  return 0;
}
