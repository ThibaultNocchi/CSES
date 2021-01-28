// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2737
// Union find

#include "helper.hpp"
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// test line
// 2 5 3 100 -75 -25 -42 42 0 1 1 2 3 4 4 2 15 20 -10 -25 0 2 1 3
// POSSIBLE IMPOSSIBLE

int main(int argc, char const *argv[]) {

  int N;
  cin >> N;

  for (int N_ = 0; N_ < N; ++N_) {
    int n, m;
    cin >> n >> m;

    vector<int> debts(n, 0);
    vector<int> balance(n, 0);
    union_find uf(n);

    for (int i = 0; i < n; ++i)
      cin >> debts[i];

    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      uf.set_union(x, y);
    }

    for (int i = 0; i < n; ++i) {
      balance[uf.find_set(i)] += debts[i];
    }

    bool all_0 = true;
    for (int i = 0; i < n; ++i) {
      if (balance[i] != 0) {
        all_0 = false;
        break;
      }
    }

    cout << (all_0 ? "POSSIBLE" : "IMPOSSIBLE") << endl;
  }

  return 0;
}
