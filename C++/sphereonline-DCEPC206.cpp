// https://www.spoj.com/problems/DCEPC206/
// fenwick tree

#include "helper.hpp"
#include <algorithm>

int main(int argc, char const *argv[]) {
  int T;
  cin >> T;

  for (int T_ = 0; T_ < T; ++T_) {
    int N;
    cin >> N;

    auto numbers = read_n_int(N);
    int max = *max_element(numbers.begin(), numbers.end());

    fenwick_tree ft(vector<int>(max + 1, 0));

    int sum = 0;

    for (const auto &el : numbers) {
      sum += ft.get_sum(0, el - 1);
      ft.increase(el, el);
    }

    cout << sum << endl;
  }

  return 0;
}
