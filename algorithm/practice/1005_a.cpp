#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9;
int T, N, K, W, ti, x, y, a[1004], dp[1004];
vector<int> adj[1004];

int go (int here) {
  if (adj[here].size() == 0) return a[here];

  int &ret = dp[here];
  if (ret != -1) return ret;

  for (int i : adj[here]) {
    ret = max(ret, go(i) + a[here]);
  }

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    memset(a, 0, sizeof(a));
    memset(dp, -1, sizeof(dp));
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
      adj[i].clear();
    }

    for (int i = 1; i <= K; i++) {
      cin >> x >> y;
      adj[y].push_back(x);
    }
    cin >> W;

    cout << go(W) << '\n';
  }
  
  return 0;
}