#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  unsigned int g_a1, g_b1, g_a2, g_b2;
  unsigned int e_a1, e_b1, e_a2, e_b2;

  cin >> g_a1 >> g_b1 >> g_a2 >> g_b2;
  cin >> e_a1 >> e_b1 >> e_a2 >> e_b2;

  unsigned int g = g_a1 + g_b1 + g_a2 + g_b2;
  unsigned int e = e_a1 + e_b1 + e_a2 + e_b2;

  if (g < e)
    cout << "Emma" << endl;
  else if (e < g)
    cout << "Gunnar" << endl;
  else
    cout << "Tie" << endl;

  return 0;
}
