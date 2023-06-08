#include <bits/stdc++.h>
#define MAX_N 200004
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
int N, n, l, r;
ll ret = 1;
vector<ll> tree_sum(MAX_N, 0), tree_cnt(MAX_N, 0);

ll _sum (vector<ll> &tree, int s) {
  ll ret = 0;
  int i = s;
  while (i) {
    ret += tree[i];
    i -= (i & -i);
  }

  return ret;
}

ll sum (vector<ll> &tree, int s, int e) {
  if (s > e) return 0;
  return (_sum(tree, e) - _sum(tree, s - 1));
}

void update(vector<ll> &tree, int s, ll val) {
  int i = s;
  while (i <= MAX_N) {
    tree[i] += val;
    i += (i & -i);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> n;
    n++;

    if (i != 1) {
      ll left = (n * sum(tree_cnt, 1, n - 1)) - sum(tree_sum, 1, n - 1);
      ll right = sum(tree_sum, n + 1, MAX_N) - (n * sum(tree_cnt, n + 1, MAX_N));
      ret *= (left + right) % MOD;
      ret %= MOD;
    }

    update(tree_cnt, n, 1);
    update(tree_sum, n, n);
  }

  cout << ret << '\n';

  return 0;
}