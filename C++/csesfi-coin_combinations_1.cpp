// https://cses.fi/problemset/task/1635/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void combinations(const int &sum);

vector<int> coins;
vector<int> results;
const int M = 1e9 + 7;

int main(int argc, char const *argv[]) {

  int sum, coins_number;

  cin >> coins_number >> sum;

  coins.resize(coins_number);
  for (int i = 0; i < coins_number; ++i) {
    cin >> coins[i];
  }

  results.resize(sum + 1);
  fill(results.begin(), results.end(), -1);

  sort(coins.begin(), coins.end(), greater<int>());

  combinations(sum);
  cout << results[sum] << endl;

  return 0;
}

void combinations(const int &sum) {
  if (results[sum] != -1)
    return;

  results[sum] = 0;

  for (const auto &coin : coins) {
    if (sum < coin)
      continue;

    if (sum == coin) {
      ++results[sum];
      results[sum] %= M;
      continue;
    }

    combinations(sum - coin);
    results[sum] += results[sum - coin];
    results[sum] %= M;
  }
}
