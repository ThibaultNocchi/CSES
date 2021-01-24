#include <bitset>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  std::ios::sync_with_stdio(false);
  unsigned int p, t;
  cin >> p >> t;

  //   unordered_map<bitset<100>, unordered_set<unsigned int>> res;
  vector<bitset<1000>> res_inv(p + 1, 0);

  //   //   res.emplace(0, unordered_set<unsigned int>());
  //   for (unsigned int i = 1; i <= p; ++i) {
  //     // res[0].insert(i);
  //     res_inv[i] = 0;
  //   }

  string line;
  stringstream ss;
  getline(cin, line);
  unsigned int a, b;
  while (getline(cin, line)) {
    ss.clear();
    ss.str(line);
    ss >> a >> b;

    // auto old_bits = res_inv[a];
    // auto new_bits(old_bits);
    // new_bits.set(b);
    // res_inv[a] = new_bits;
    res_inv[a].set(b);
  }

  unordered_set<unsigned long long> final_set;
  for (const auto &el : res_inv) {
    if (el != 0)
      final_set.insert(el.to_ullong());
  }

  cout << final_set.size() << endl;

  return 0;
}
