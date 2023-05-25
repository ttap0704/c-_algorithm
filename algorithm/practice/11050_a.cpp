#include <bits/stdc++.h>
using namespace std;

int N, K, dp[11][11];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= min(K, i); j++) {
      if (i == j || j == 0) dp[i][j] = 1;
      else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    }
  }

  cout << dp[N][K] << '\n';

  return 0;
}