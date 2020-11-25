#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  unsigned int n;
  cin >> n;

  vector<unsigned int> x(n, 0);
  vector<unsigned int> res(n, 1);
  for (unsigned int i = 0; i < n; ++i)
    cin >> x[i];

  for (int i = 1; i < n; ++i) {
    for (int j = i - 1; j >= 0; --j) {
      if (res[i] > res[j])
        continue;
      if (x[i] <= x[j])
        continue;
      res[i] = res[j] + 1;
    }
  }

  cout << *max_element(res.begin(), res.end()) << endl;

  return 0;
}
