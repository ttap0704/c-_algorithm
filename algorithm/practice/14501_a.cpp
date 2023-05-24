#include <bits/stdc++.h>
using namespace std;

int N, dp[16], t[16], p[16], mx;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> t[i] >> p[i];
  }

  for (int i = 0; i <= N; i++) {
    dp[i] = max(mx, dp[i]);
    if (t[i] + i <= N) {
      dp[t[i] + i] = max(p[i] + dp[i], dp[t[i] + i]);
    }
    mx = max(mx, dp[i]);
  }

  cout << mx << '\n';

  return 0;
}