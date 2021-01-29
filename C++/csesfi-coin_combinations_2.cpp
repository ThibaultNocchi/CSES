// https://cses.fi/problemset/task/1635/
// Dynamic programming

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
  fill(results.begin(), results.end(), 0);

  sort(coins.begin(), coins.end(), greater<int>());

  const int M = 1E9 + 7;

  results[0] = 1;
  for (int i = 0; i < coins.size(); ++i) {
    for (int j = coins[i]; j <= sum; ++j) {
      results[j] += results[j - coins[i]];
      if (results[j] >= M)
        results[j] -= M;
    }
  }

  cout << results[sum] << endl;

  return 0;
}
