#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <unordered_map>
#include <vector>

using std::random_shuffle;
using std::sort;
using std::unordered_map;
using std::vector;

void combinations_sums(const vector<uint64_t> &vec,
                       unordered_map<uint64_t, uint64_t> &map_results,
                       uint64_t &x) {
  uint8_t vec_size = vec.size();
  uint64_t nbr_combinations = pow(2, vec_size);
  uint64_t sum;

  for (uint64_t i = 0; i < nbr_combinations; ++i) {
    sum = 0;
    for (uint8_t j = 0; j < vec_size; ++j) {
      if (i & (1 << j)) {
        sum += vec[j];
        if (sum > x)
          break;
      }
    }
    if (sum <= x)
      ++map_results[sum];
  }
}

int main(int argc, char const *argv[]) {

  std::ios_base::sync_with_stdio(false);

  uint8_t n;
  uint64_t x;

  scanf("%hhd %ld", &n, &x);

  vector<uint64_t> t(n);

  for (uint8_t i = 0; i < n; ++i) {
    scanf("%ld", &(t[i]));
  }

  random_shuffle(t.begin(), t.end());

  uint8_t middle = n / 2;
  vector<uint64_t> t1(t.begin(), t.begin() + middle);
  vector<uint64_t> t2(t.begin() + middle, t.end());

  unordered_map<uint64_t, uint64_t> t1_sums, t2_sums;

  combinations_sums(t1, t1_sums, x);
  combinations_sums(t2, t2_sums, x);

  uint64_t equal_combinations = 0;

  for (const auto &el : t1_sums) {
    equal_combinations += el.second * t2_sums[x - el.first];
  }

  printf("%ld\n", equal_combinations);

  return 0;
}
