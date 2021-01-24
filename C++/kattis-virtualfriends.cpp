// https://open.kattis.com/problems/virtualfriends
// Union find

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class union_find {
  vector<int> id;
  vector<int> sz;

  unordered_map<string, int> names_map;
  vector<string> names_reverse;

  int count;

public:
  union_find() { count = 0; }

  void add_person(string name) {
    ++count;
    int new_id = id.size();
    id.push_back(new_id);
    sz.push_back(1);
    names_map.emplace(name, new_id);
    names_reverse.push_back(name);
  }

  int nb_components() { return count; }

  int size_set(int i) { return sz[find_set(i)]; }

  int size_set(string i) { return sz[find_set(names_map[i])]; }

  int find_set(int i) { return (id[i] == i) ? i : (id[i] = find_set(id[i])); }

  bool connected(int i, int j) { return find_set(i) == find_set(j); }

  void union_set(int p, int q) {
    int i = find_set(p);
    int j = find_set(q);
    if (i == j)
      return;
    if (sz[i] < sz[j]) {
      id[i] = j;
      sz[j] += sz[i];
    } else {
      id[j] = i;
      sz[i] += sz[j];
    }
    --count;
  }

  void union_set(string p, string q) {
    if (names_map.find(p) == names_map.end())
      add_person(p);
    if (names_map.find(q) == names_map.end())
      add_person(q);

    union_set(names_map[p], names_map[q]);
  }
};

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {

    union_find un;
    int f;
    cin >> f;

    for (int j = 0; j < f; ++j) {
      string p, q;
      cin >> p >> q;

      un.union_set(p, q);
      cout << un.size_set(p) << endl;
    }
  }
}
