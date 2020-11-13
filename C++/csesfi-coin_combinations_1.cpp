// https://cses.fi/problemset/task/1635/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void combinations(const int &sum, const vector<int> &coins,
                  vector<vector<string>> &results, vector<bool> &calculated);

int main(int argc, char const *argv[]) {

  int sum, coins_number;
  vector<int> coins;

  cin >> coins_number >> sum;

  coins.resize(coins_number);
  for (int i = 0; i < coins_number; ++i) {
    cin >> coins[i];
  }

  vector<vector<string>> results;
  vector<bool> calculated;
  results.resize(sum + 1);
  calculated.resize(sum + 1);
  fill(calculated.begin(), calculated.end(), false);

  sort(coins.begin(), coins.end(), greater<int>());

  combinations(sum, coins, results, calculated);

  cout << results[sum].size() << endl;

  return 0;
}

void combinations(const int &sum, const vector<int> &coins,
                  vector<vector<string>> &results, vector<bool> &calculated) {
  if (calculated[sum])
    return;

  for (const auto &coin : coins) {
    if (sum < coin)
      continue;

    if (sum == coin) {
      results[sum].push_back(to_string(coin));
      continue;
    }

    combinations(sum - coin, coins, results, calculated);
    for (const auto &comb : results[sum - coin]) {
      results[sum].push_back(comb + "," + to_string(coin));
    }
  }

  calculated[sum] = true;
}
