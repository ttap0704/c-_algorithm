#include <bits/stdc++.h>
#define MAX_N 200004
using namespace std;

int T, N, M, n, tree[MAX_N];
map<int, int> mp;

int sum (int s) {
  int i = s, ret = 0;

  while (i > 0) {
    ret += tree[i];
    i -= (i & -i);
  }

  return ret;
}

void update (int s, int val) {
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

  cin >> T;
  while (T--) {
    int update_idx = 100001;
    memset(tree, 0, sizeof(tree));
    mp.clear();

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
      update(i + update_idx, 1);
      mp[i] = i + update_idx;
    }

    while (M--) {
      cin >> n;

      int idx = mp[n];
      cout << sum(idx - 1) << ' ';

      update(idx, -1);
      update(--update_idx, 1);
      mp[n] = update_idx;
    }
    cout << '\n';
  }

  return 0;
}