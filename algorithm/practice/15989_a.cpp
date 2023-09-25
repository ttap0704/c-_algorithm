#include <bits/stdc++.h>
using namespace std;

int T, N, dp[10004][4];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  dp[1][1] = 1;
  dp[2][1] = 1;
  dp[2][2] = 1;
  dp[3][1] = 1;
  dp[3][2] = 1;
  dp[3][3] = 1;
  for (int i = 4; i <= 10000; i++) {
    dp[i][1] = dp[i - 1][1];
    dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
    dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
  }

  cin >> T;
  while (T--) {
    cin >> N;

    cout << dp[N][1] + dp[N][2] + dp[N][3] << '\n';
  }

  return 0;
}