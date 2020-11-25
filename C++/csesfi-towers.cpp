// https://cses.fi/problemset/result/1294373/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool lower(const unsigned int info, const unsigned int val) {
  return info <= val;
}

int main(int argc, char const *argv[]) {
  unsigned int n;
  cin >> n;

  vector<unsigned int> k(n, 0);
  for (unsigned int i = 0; i < n; ++i)
    cin >> k[i];

  vector<unsigned int> towers{k[0]};
  for (unsigned int i = 1; i < n; ++i) {
    auto it = lower_bound(towers.begin(), towers.end(), k[i], lower);
    if (it == towers.end()) {
      towers.push_back(k[i]);
      sort(towers.begin(), towers.end());
    } else
      *it = k[i];
  }

  cout << towers.size() << endl;

  return 0;
}
