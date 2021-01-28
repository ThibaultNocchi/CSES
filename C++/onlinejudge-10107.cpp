// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1048
// heap

#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

int main(int argc, char const *argv[]) {

  //   priority_queue<long> small{LONG_MIN}, large{LONG_MAX};
  priority_queue<long> small;
  priority_queue<long, vector<long>, greater<long>> large;

  small.push(LONG_MIN);
  large.push(LONG_MAX);

  long x;

  while (cin >> x) {
    if (x <= small.top()) {
      small.push(x);
      if (small.size() > large.size() + 1) {
        large.push(small.top());
        small.pop();
      }
    } else if (x >= large.top()) {
      large.push(x);
      if (large.size() > small.size() + 1) {
        small.push(large.top());
        large.pop();
      }
    } else {
      if (small.size() <= large.size()) {
        small.push(x);
      } else {
        large.push(x);
      }
    }

    if (small.size() == large.size()) {
      cout << (small.top() + large.top()) / 2 << endl;
    } else if (small.size() < large.size()) {
      cout << large.top() << endl;
    } else {
      cout << small.top() << endl;
    }
  }

  return 0;
}
