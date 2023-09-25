#include <bits/stdc++.h>
using namespace std;

struct Road {
  int y, d;
};

int N, D, dp[10004], y, x, d, ret;
vector<Road> v[10004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> D;
  for (int i = 0; i < N; i++) {
    cin >> y >> x >> d;
    if (x - y > d) v[x].push_back({y, d});
  }

  for (int i = 0; i <= D; i++) {
    if (i != 0) dp[i] = dp[i - 1] + 1;
    if (v[i].size()) {
      for (Road road : v[i]) {
        dp[i] = min(dp[i], dp[road.y] + road.d);
      }
    }
  }

  cout << dp[D] << '\n';

  return 0;
}