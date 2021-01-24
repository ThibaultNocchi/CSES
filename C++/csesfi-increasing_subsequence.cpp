// https://cses.fi/problemset/task/1145/
// Dynamic programming LIS

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  unsigned int n;
  cin >> n;

  vector<unsigned int> x(n, 0);
  for (unsigned int i = 0; i < n; ++i)
    cin >> x[i];

  vector<unsigned int> res{x[0]};

  for (unsigned int x_i = 1; x_i < x.size(); ++x_i) {
    if (x[x_i] > res.back()) {
      res.push_back(x[x_i]);
    } else {
      *lower_bound(res.begin(), res.end(), x[x_i]) = x[x_i];
    }
  }

  cout << res.size() << endl;

  return 0;
}
