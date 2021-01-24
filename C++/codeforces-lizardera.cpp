// https://codeforces.com/problemset/problem/585/D
// meet in the middle

#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct reward {
  unsigned int l;
  unsigned int m;
  unsigned int w;
};

void increment_base_n(vector<unsigned int> &num, unsigned int base) {
  size_t i = 0;
  while (1) {
    if (num[i] == base - 1) {
      num[i] = 0;
      ++i;
      if (num.size() <= i)
        num.push_back(0);
    } else {
      ++num[i];
      break;
    }
  }
}

void print_reward(const reward &r) {
  cout << r.l << " " << r.m << " " << r.w << endl;
}

void combinations(vector<reward> &tab, unordered_map<string, reward> &results) {
  int comb_nbr = pow(3, tab.size());
  vector<unsigned int> bittable(tab.size(), 0);
  for (int i = 0; i < comb_nbr; ++i) {
    reward r{0, 0, 0};
    string str = "";
    for (int j = 0; j < tab.size(); ++j) {
      switch (bittable[j]) {
      case 0:
        r.m += tab[j].m;
        r.w += tab[j].w;
        str += "MW\n";
        break;
      case 1:
        r.l += tab[j].l;
        r.w += tab[j].w;
        str += "LW\n";
        break;
      case 2:
        r.l += tab[j].l;
        r.m += tab[j].m;
        str += "LM\n";
        break;
      }
    }
    results.emplace(str, r);
    increment_base_n(bittable, 3);
  }
}

int main(int argc, char const *argv[]) {

  int n;
  cin >> n;

  vector<reward> rewards(n);

  for (int i = 0; i < n; ++i)
    cin >> rewards[i].l >> rewards[i].m >> rewards[i].w;

  int middle = rewards.size() / 2;
  auto x = vector<reward>(rewards.begin(), rewards.begin() + middle);
  auto y = vector<reward>(rewards.begin() + middle, rewards.end());

  //   vector<reward> r1, r2;
  unordered_map<string, reward> r1, r2;

  combinations(x, r1);
  combinations(y, r2);

  reward tmp{0, 0, 0};
  string best_str = "";
  unsigned int best_sum = 0;

  for (const auto &el1 : r1) {
    for (const auto &el2 : r2) {
      tmp.l = el1.second.l + el2.second.l;
      tmp.m = el1.second.m + el2.second.m;
      if (tmp.l != tmp.m)
        continue;
      tmp.w = el1.second.w + el2.second.w;
      if (tmp.l != tmp.w)
        continue;
      if ((tmp.l * 3) >= best_sum) {
        best_str = el1.first + el2.first;
        best_sum = tmp.l * 3;
      }
    }
  }

  if (best_str != "")
    cout << best_str;
  else
    cout << "Impossible" << endl;

  return 0;
}
