#include <bits/stdc++.h>
using namespace std;

int N, M, K, a[16][16], dp[16][16];
pair<int, int> mid;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> K;
  
  int num = 1;
  dp[1][1] = 1;
  for (int i = 1; i <= N; i++) {
    bool flag = 0;
    for (int j = 1; j <= M; j++) {
      a[i][j] = num;

      if (i - 1 < N) dp[i][j] += dp[i - 1][j];
      if (j - 1 < M) dp[i][j] += dp[i][j - 1];

      if (num == K) {
        mid = {i, j};
        flag = 1;
        break;
      }
      num++;
    }
    if (flag) break;
  }

  int mid_val = dp[mid.first][mid.second];
  
  if (mid_val) {
    memset(dp, 0, sizeof(dp));
    dp[mid.first][mid.second] = 1;
    for (int i = mid.first; i <= N; i++) {
      for (int j = mid.second; j <= M; j++) {
        if (i - 1 < N) dp[i][j] += dp[i - 1][j];
        if (j - 1 < M) dp[i][j] += dp[i][j - 1];
      }
    }

    cout << (dp[N][M] * mid_val) << '\n';
  } else {cout << dp[N][M] << '\n';}

  return 0;
}