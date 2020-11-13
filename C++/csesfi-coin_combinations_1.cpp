// https://cses.fi/problemset/task/1635/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void combinations(const int &sum, const vector<int> &coins,
                  vector<int> &results);

int main(int argc, char const *argv[]) {

  int sum, coins_number;
  vector<int> coins;

  cin >> coins_number >> sum;

  coins.resize(coins_number);
  for (int i = 0; i < coins_number; ++i) {
    cin >> coins[i];
  }

  vector<int> results;
  results.resize(sum + 1);
  fill(results.begin(), results.end(), -1);

  sort(coins.begin(), coins.end(), greater<int>());

  combinations(sum, coins, results);
  cout << results[sum] << endl;

  return 0;
}

void combinations(const int &sum, const vector<int> &coins,
                  vector<int> &results) {
  if (results[sum] != -1)
    return;

  results[sum] = 0;

  for (const auto &coin : coins) {
    if (sum < coin)
      continue;

    if (sum == coin) {
      ++results[sum];
      continue;
    }

    combinations(sum - coin, coins, results);
    results[sum] += results[sum - coin];
  }
}
