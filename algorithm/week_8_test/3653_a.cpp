#include <bits/stdc++.h>
using namespace std;

int T, N, M, tree[200004], tmp;
map<int, int> mp;

int sum (int idx) {
  int ret = 0;
  while (idx > 0) {
    ret += tree[idx];
    idx -= (idx & -idx);
  }
  
  return ret;
}

void update (int i, int value) {
  while (i <= 200004) {
    tree[i] += value;
    i += (i & -i);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    cin >> N >> M;
    memset(tree, 0, sizeof(tree));
    mp.clear();

    int update_idx = 100001;
    for (int i = 1; i <= N; i++) {
      update(i + update_idx, 1);
      mp[i] = i + update_idx;
    }

    for (int i = 0; i < M; i++) {
      cin >> tmp;
      int idx = mp[tmp];

      cout << sum(idx - 1) << ' ';

      update(idx, -1);
      update(--update_idx, 1);
      mp[tmp] = update_idx;
    }
    cout << '\n';
  }

  return 0;
}