#include <bits/stdc++.h>
using namespace std;

int T, N;
int a[2][100004], dp[2][100004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    cin >> N;

    memset(a, 0, sizeof(a));
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < 2; i++) {
      for (int j = 1; j <= N; j++) {
        cin >> a[i][j];
      }
    }

    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[0][1] = a[0][1];
    dp[1][1] = a[1][1];
    for (int j = 2; j <= N; j++) {
      for (int i = 0; i < 2; i++) {
        dp[i][j] = max(dp[i ^ 1][j - 1] + a[i][j], max(dp[i][j - 2] + a[i][j], dp[i ^ 1][j - 2] + a[i][j]));
      }

      // for (int i = 0; i < 2; i++) {
      //   for (int k = 1; k <= N; k++) {
      //     cout << dp[i][k] << ' ';
      //   }
      //   cout << '\n';
      // }      
      // cout << '\n';
    }

    cout << max(dp[0][N], dp[1][N]) << '\n';
  }

  return 0;
}