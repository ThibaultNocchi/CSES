// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1072
// dynamic programming lis

#include "helper.hpp"
#include <algorithm>
#include <sstream>

struct elephant {
  int weight;
  int iq;
  int idx;
  bool operator<(const elephant &e) const { return weight < e.weight; }
  void print() const {
    cout << "ID: " << idx << " W: " << weight << " IQ: " << iq << endl;
  }
};

stringstream
    def("6008 1300 6000 2100 500 2000 1000 4000 1100 3000 6000 2000 8000 "
        "1400 6000 1200 2000 1900");

int main(int argc, char const *argv[]) {

  vector<elephant> elephants;

  int weight;
  int iq;
  int i = 0;

  // while (cin >> weight >> iq) {
  while (def >> weight >> iq) {
    elephants.push_back({weight, iq, ++i});
  }

  sort(elephants.begin(), elephants.end());

  vector<int> lds(elephants.size(), 1), prev(elephants.size(), -1);
  auto id_max = 0;

  for (int i = 1; i < elephants.size(); ++i) {
    auto &el = elephants[i];
    for (int j = 0; j < i; ++j) {
      auto &other = elephants[j];
      if (other.iq > el.iq && other.weight < el.weight) {
        lds[i] = lds[j] + 1;
        prev[i] = j;
        if (lds[i] > lds[id_max])
          id_max = i;
      }
    }
  }

  for (const auto &el : elephants) {
    el.print();
  }

  i = id_max;
  vector<int> results;
  while (i != -1) {
    results.push_back(elephants[i].idx);
    i = prev[i];
  }
  for (auto it = results.end() - 1; it >= results.begin(); --it) {
    cout << *it << endl;
  }

  return 0;
}

// 6008 1300 6000 2100 500 2000 1000 4000 1100 3000 6000 2000 8000 1400 6000
// 1200 2000 1900
