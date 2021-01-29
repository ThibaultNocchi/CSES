// Write the function
// void print_subsets(const string& set)
// which prints all the subsets of the string set.
// Your function must be non-recursive.
// We suppose that set.size() <= 30
// Ex: prints_subsets("abc") => { } { a } { b } { a b } { c } { a c } { b c } {
// a b c }

#include "helper.hpp"
#include <iostream>
#include <string>
using namespace std;

void prints_subsets(const string &set) {
  int combinations = 1 << set.size();
  for (int i = 0; i < combinations; ++i) {
    cout << "{ ";
    for (int j = 0; j < set.size(); ++j) {
      if (is_bit_set(i, j))
        cout << set[j] << " ";
    }
    cout << "}" << endl;
  }
}

int main(int argc, char const *argv[]) {
  prints_subsets("abc");
  return 0;
}
