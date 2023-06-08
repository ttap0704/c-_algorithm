#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N, M, K;
ll n[1000004], a, b, c;

ll sum (vector<ll> &tree, int i) {
  ll ret = 0;
  while (i > 0) {
    ret += tree[i];
    i -= (i & -i);
  }

  return ret;
}

void update(vector<ll> &tree, int i, ll val) {
  while (i <= N) {
    tree[i] += val;
    i += (i & -i);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> K;
  vector<ll> tree(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> n[i];
    update(tree, i, n[i]);
  }

  M += K;
  while (M--) {
    cin >> a >> b >> c;
    // for (int i = 1; i <= N; i++) {
    //   cout << tree[i] << ' ';
    // }
    // cout << '\n';
    if (a == 1) {
      update(tree, b, c - n[b]);
      n[b] = c;
    } else {
      cout << sum(tree, c) - sum(tree, b - 1) << '\n';
    }
  }

  return 0;
}