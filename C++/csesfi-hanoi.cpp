// https://cses.fi/problemset/task/2165

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int from, int to, int inter, vector<string> &str) {
  if (n != 0) {
    hanoi(n - 1, from, inter, to, str);
    stringstream oss;
    oss << from << " " << to;
    str.push_back(oss.str());
    hanoi(n - 1, inter, to, from, str);
  }
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<string> str;
  hanoi(n, 1, 3, 2, str);
  cout << str.size() << endl;
  for (const auto &el : str) {
    cout << el << endl;
  }
  return 0;
}
