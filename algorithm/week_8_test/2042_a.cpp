#include <bits/stdc++.h>
using namespace std;

int N, M, K;
long long a, b, c;

long long sum (vector<long long> &tree, int i) {
  long long ret = 0;
  while (i > 0) {
    ret += tree[i];
    i -= (i & -i);
  }

  return ret;
}

void update (vector<long long> &tree, int i, long long diff) {
  while (i < tree.size()) {
    tree[i] += diff;
    i += (i & -i);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  scanf("%d %d %d", &N, &M, &K);
  vector<long long> v(N + 1);
  vector<long long> tree(N + 1);

  for (int i = 1; i <= N; i++) {
    scanf("%lld", &v[i]);
    update(tree, i, v[i]);
  }

  M += K;
  while (M--) {
    scanf("%lld %lld %lld", &a, &b, &c);
    if (a == 1) {
      long long diff = c - v[b];
      v[b] = c;
      update(tree, b, diff);
    } else {
      long long val = sum(tree, c) - sum(tree, b - 1);
      printf("%lld\n", val);
    }
  }

  return 0;
}