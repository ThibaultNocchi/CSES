// https://cses.fi/problemset/task/1649/
// Segment tree

#include <algorithm>
#include <iostream>
#include <vector>

struct node {
  unsigned int left;
  unsigned int right;
  unsigned int min;
};

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void print_node(const node &n) {
  cout << "[" << n.left << "," << n.right << "],min=" << n.min << endl;
}

unsigned int calculate_middle(const unsigned int min, const unsigned int max) {
  return min + ((max - min) / 2);
}

void build_tree(const unsigned int min, const unsigned int max,
                unsigned int idx, vector<node> &tree,
                const vector<unsigned int> &x) {
  tree[idx].left = min;
  tree[idx].right = max;
  if (min == max) {
    tree[idx].min = x[min];
  } else {
    unsigned int middle = calculate_middle(min, max);
    build_tree(min, middle, idx * 2, tree, x);
    build_tree(middle + 1, max, (idx * 2) + 1, tree, x);
    tree[idx].min = std::min(tree[idx * 2].min, tree[idx * 2 + 1].min);
  }
}

unsigned int query_min(const unsigned int min, const unsigned max,
                       unsigned int idx, const vector<node> &tree) {
  if (tree[idx].left >= min && tree[idx].right <= max) {
    return tree[idx].min;
  } else if (tree[idx].right < min || tree[idx].left > max) {
    return UINT32_MAX;
  } else {
    return std::min(query_min(min, max, idx * 2, tree),
                    query_min(min, max, (idx * 2) + 1, tree));
  }
}

void set_min(const unsigned position, const unsigned int value,
             unsigned int idx, vector<node> &tree) {
  if (position == tree[idx].left && position == tree[idx].right) {
    tree[idx].min = value;
  } else if (position >= tree[idx].left && position <= tree[idx].right) {
    set_min(position, value, idx * 2, tree);
    set_min(position, value, (idx * 2) + 1, tree);
    tree[idx].min = std::min(tree[idx * 2].min, tree[(idx * 2) + 1].min);
  }
}

int main(int argc, char const *argv[]) {

  unsigned int n, q;
  cin >> n >> q;

  vector<unsigned int> x(n + 1, 0);
  for (unsigned int i = 1; i <= n; ++i) {
    cin >> x[i];
  }

  vector<node> tree(n * 4, node());
  build_tree(1, x.size() - 1, 1, tree, x);

  unsigned int type, first, second;

  for (unsigned int i = 0; i < q; ++i) {
    cin >> type >> first >> second;
    if (type == 1) {
      set_min(first, second, 1, tree);
    } else {
      cout << query_min(first, second, 1, tree) << endl;
    }
  }

  return 0;
}
