#include <cmath>
#include <iostream>
#include <limits>
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

bool is_bit_set(int S, int j) { return S & (1 << j); }
void set_bit(int &S, int j) { S |= (1 << j); }
void unset_bit(int &S, int j) { S &= ~(1 << j); }
void toggle_bit(int &S, int j) { S ^= 1 << j; }
void set_n_bits(int &S, int n) { S = (1 << n) - 1; }
bool is_power_2(int S) { return (S & (S - 1)) == 0; }
int least_on_significant_bit(int S) { return S & (-S); }
void turn_off_last_set_bit(int &S) { S &= (S - 1); }
void turn_on_last_unset_bit(int &S) { S |= (S + 1); }

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

class segment_tree {
  struct node {
    int sum = 0;
    int min = INT32_MAX;
    int from = 0;
    int to = -1;
    bool pending = false;
    int pending_val;
    int size() const { return to - from + 1; }
  };
  vector<node> heap;
  vector<int> array;

  inline int left(int p) { return p << 1; }
  inline int right(int p) { return (p << 1) + 1; }
  inline bool contains(int from1, int to1, int from2, int to2) {
    return from1 <= from2 && to2 <= to1;
  }
  inline bool intersects(int from1, int to1, int from2, int to2) {
    return (from1 <= from2 && from2 <= to1) || (from2 <= from1 && from1 <= to2);
  }

public:
  segment_tree(const vector<int> &arr) {
    array = arr;
    int heap_size = 2 * (1 << ((int)log2(array.size()) + 1));
    heap.resize(heap_size);
    build(1, 0, array.size() - 1);
  }

  void update(int from, int to, int value) { update(1, from, to, value); }

private:
  void build(int heap_index, int from, int to) {
    node &n = heap[heap_index];
    n.from = from;
    n.to = to;
    if (from == to) {
      n.sum = array[from];
      n.min = array[from];
    } else {
      int middle = from + (to - from) / 2;
      build(left(heap_index), from, middle);
      build(right(heap_index), middle + 1, to);
      n.sum = heap[left(heap_index)].sum + heap[right(heap_index)].sum;
      n.min = min(heap[left(heap_index)].min, heap[right(heap_index)].min);
    }
  }

  void update(int heap_index, int from, int to, int value) {
    node &n = heap[heap_index];
    if (contains(from, to, n.from, n.to))
      change(n, value);
    else if (intersects(from, to, n.from, n.to)) {
      propagate(heap_index);
      update(left(heap_index), from, to, value);
      update(right(heap_index), from, to, value);
      n.sum = heap[left(heap_index)].sum + heap[right(heap_index)].sum;
      n.min = min(heap[left(heap_index)].min, heap[right(heap_index)].min);
    }
  }

  void propagate(int heap_index) {
    node &n = heap[heap_index];
    if (n.pending) {
      change(heap[left(heap_index)], n.pending_val);
      change(heap[right(heap_index)], n.pending_val);
      n.pending = false;
    }
  }

  void change(node &n, int value) {
    n.pending = true;
    n.pending_val = value;
    n.sum = n.size() * value;
    n.min = value;
    array[n.from] = value;
  }

public:
  int get_sum(int from, int to) { return get_sum(1, from, to); }

private:
  int get_sum(int heap_index, int from, int to) {
    node &n = heap[heap_index];
    if (n.pending && contains(n.from, n.to, from, to))
      return (to - from + 1) * n.pending_val;

    if (contains(from, to, n.from, n.to))
      return n.sum;

    if (intersects(from, to, n.from, n.to)) {
      propagate(heap_index);
      return get_sum(left(heap_index), from, to) +
             get_sum(right(heap_index), from, to);
    }
    return 0;
  }

public:
  int get_min(int from, int to) { return get_min(1, from, to); }

private:
  int get_min(int heap_index, int from, int to) {
    node &n = heap[heap_index];
    if (n.pending && contains(n.from, n.to, from, to))
      return n.pending_val;

    if (contains(from, to, n.from, n.to))
      return n.min;

    if (intersects(from, to, n.from, n.to)) {
      propagate(heap_index);
      return min(get_min(left(heap_index), from, to),
                 get_min(right(heap_index), from, to));
    }
    return INT32_MAX;
  }
};
