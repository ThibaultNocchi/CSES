#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <vector>

using std::sort;
using std::vector;

void combinations_sums(const vector<uint32_t> &vec,
                       vector<uint32_t> &vec_results, uint32_t &x) {
  uint8_t vec_size = vec.size();
  uint32_t nbr_combinations = pow(2, vec_size);
  uint32_t sum;

  for (uint32_t i = 0; i < nbr_combinations; ++i) {
    sum = 0;
    for (uint8_t j = 0; j < vec_size; ++j) {
      if (i & (1 << j)) {
        sum += vec[j];
        if (sum > x)
          break;
      }
    }
    if (sum <= x)
      vec_results.push_back(sum);
  }
}

int main(int argc, char const *argv[]) {

  std::ios_base::sync_with_stdio(false);

  uint8_t n;
  uint32_t x;
  uint32_t ti;

  vector<uint32_t> t;

  scanf("%hhd %d", &n, &x);

  for (uint8_t i = 0; i < n; ++i) {
    scanf("%d", &ti);
    t.push_back(ti);
  }

  uint8_t middle = n / 2;
  vector<uint32_t> t1(t.begin(), t.begin() + middle);
  vector<uint32_t> t2(t.begin() + middle, t.end());

  vector<uint32_t> t1_sums, t2_sums;

  combinations_sums(t1, t1_sums, x);
  combinations_sums(t2, t2_sums, x);

  vector<uint32_t> *small, *big;

  if (t1_sums.size() < t2_sums.size()) {
    small = &t1_sums;
    big = &t2_sums;
  } else {
    big = &t1_sums;
    small = &t2_sums;
  }

  sort(small->begin(), small->end());

  // for (const auto &el : *small) {
  //   printf("%d ", el);
  // }
  // printf("\n");

  uint64_t equal_combinations = 0;
  uint32_t both_sum;

  for (const auto &sum_t1 : *big) {
    for (const auto &sum_t2 : *small) {
      both_sum = sum_t1 + sum_t2;
      if (both_sum == x)
        ++equal_combinations;
      else if (both_sum > x)
        break;
    }
  }

  printf("%ld\n", equal_combinations);

  return 0;
}
