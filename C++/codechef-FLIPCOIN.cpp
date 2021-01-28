// https://www.codechef.com/problems/FLIPCOIN
// segment tree

#include "helper.hpp"

class segment_tree_headsup {
  struct node {
    int headsups = 0;
    int from = 0;
    int to = -1;
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
  segment_tree_headsup(const vector<int> &arr) {
    array = arr;
    int heap_size = 2 * (1 << ((int)log2(array.size()) + 1));
    heap.resize(heap_size);
    build(1, 0, array.size() - 1);
  }

  void flip(int from, int to) { flip(1, from, to); }

  void print_heap() {
    for (const auto &el : heap)
      print_node(el);
  }

  void print_node(const node &n) {
    cout << "[" << n.from << ", " << n.to << "] = " << n.headsups << endl;
  }

private:
  void build(int heap_index, int from, int to) {
    node &n = heap[heap_index];
    n.from = from;
    n.to = to;
    if (from == to) {
      n.headsups = array[from];
    } else {
      int middle = from + (to - from) / 2;
      build(left(heap_index), from, middle);
      build(right(heap_index), middle + 1, to);
      n.headsups =
          heap[left(heap_index)].headsups + heap[right(heap_index)].headsups;
    }
  }

  void flip(int heap_index, int from, int to) {
    node &n = heap[heap_index];
    if (contains(from, to, n.from, n.to) && n.from == n.to) {
      n.headsups = n.headsups == 1 ? 0 : 1;
      array[from] = n.headsups;
    } else if (intersects(from, to, n.from, n.to) ||
               contains(from, to, n.from, n.to)) {
      flip(left(heap_index), from, to);
      flip(right(heap_index), from, to);
      n.headsups =
          heap[left(heap_index)].headsups + heap[right(heap_index)].headsups;
    }
  }

public:
  int get_headsup(int from, int to) { return get_headsup(1, from, to); }

private:
  int get_headsup(int heap_index, int from, int to) {
    node &n = heap[heap_index];

    if (contains(from, to, n.from, n.to))
      return n.headsups;

    if (intersects(from, to, n.from, n.to)) {
      return get_headsup(left(heap_index), from, to) +
             get_headsup(right(heap_index), from, to);
    }
    return 0;
  }
};

int main(int argc, char const *argv[]) {
  int N, Q;
  cin >> N >> Q;

  // 0 = tails up
  // 1 = heads up
  vector<int> coins(N, 0);

  segment_tree_headsup st(coins);

  int x, a, b;

  while (Q--) {
    cin >> x >> a >> b;
    if (x == 0) {
      st.flip(a, b);
    } else {
      cout << st.get_headsup(a, b) << endl;
    }
  }

  return 0;
}
