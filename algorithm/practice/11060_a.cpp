#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, a[1004], dp[1004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> a[i];

  fill(dp, dp + 1004, INF);
  dp[1] = 0;

  for (int i = 1; i <= N; i++) {
    if (dp[i] == INF || a[i] == 0) continue;

    for (int j = i + 1; j <= min(i + a[i], N); j++) {
      dp[j] = min(dp[j], dp[i] + 1);
    }
  }

  // for (int i = 1; i <= N; i++) cout << dp[i] << ' ';
  if (dp[N] == INF) cout << -1 << '\n';
  else cout << dp[N] << '\n';

  return 0;
}