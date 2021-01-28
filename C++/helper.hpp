#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void print_vector(const vector<pair<int, int>> &vec) {
  for (const auto &el : vec)
    cout << el.first << " - " << el.second << endl;
}

template <typename T> void print_vector(const vector<T> &vec) {
  for (const auto &el : vec)
    cout << el << endl;
}

vector<int> read_n_int(int n) {
  vector<int> vec(n, 0);
  for (int i = 0; i < n; ++i)
    cin >> vec[i];
  return vec;
}

class union_find {
  vector<int> id;
  vector<int> sz;
  int count;

public:
  union_find(int N) : id(N, 0), sz(N, 1) {
    count = N;
    for (int i = 0; i < N; ++i)
      id[i] = i;
  }
  int get_count() { return count; }
  int get_size_set(int i) { return sz[find_set(i)]; }
  int find_set(int i) { return id[i] == i ? i : find_set(id[i]); }
  bool is_connected(int i, int j) { return find_set(i) == find_set(j); }
  void set_union(int i, int j) {
    int p = find_set(i);
    int q = find_set(j);
    if (p == q)
      return;
    if (sz[p] < sz[q]) {
      id[q] = p;
      sz[p] += sz[q];
    } else {
      id[p] = q;
      sz[q] += sz[p];
    }
  }
  void print() {
    cout << "ID: " << endl;
    for (int i = 0; i < id.size(); ++i) {
      cout << i << ": " << id[i] << endl;
    }
    cout << "Sizes: " << endl;
    for (int i = 0; i < sz.size(); ++i) {
      cout << i << ": " << sz[i] << endl;
    }
  }
};

class fenwick_tree {
  vector<int> tree;

public:
  fenwick_tree(const vector<int> &array) : tree(array.size(), 0) {
    for (unsigned int i = 0; i < tree.size(); ++i)
      increase(i, array[i]);
  }

  void increase(int i, int delta) {
    for (; i < (int)tree.size(); i |= i + 1)
      tree[i] += delta;
  }

  int get_sum(int left, int right) { return sum(right) - sum(left - 1); }

  int sum(int ind) {
    int sum = 0;
    while (ind >= 0) {
      sum += tree[ind];
      ind &= ind + 1;
      --ind;
    }
    return sum;
  }
};
