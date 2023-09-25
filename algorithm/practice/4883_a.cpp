#include <bits/stdc++.h>
using namespace std;

int N, a[100004][3], dp[100004][3], cnt;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    cin >> N;
    if (N == 0) break;
    cnt++;

    memset(a, 0, sizeof(a));
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < N; i++) {
      cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][1] + a[0][2];

    for (int i = 1; i < N; i++) {
      dp[i][0] = 1e9;
      if (i != 1) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
      dp[i][0] = min(dp[i][0], dp[i - 1][1]);
      dp[i][0] += a[i][0];

      dp[i][1] = 1e9;
      if (i != 1) dp[i][1] = min(dp[i][1], dp[i - 1][0]);
      dp[i][1] = min(dp[i][1], dp[i - 1][1]);
      dp[i][1] = min(dp[i][1], dp[i - 1][2]);
      dp[i][1] = min(dp[i][1], dp[i][0]);
      dp[i][1] += a[i][1];

      dp[i][2] = 1e9;
      dp[i][2] = min(dp[i][2], dp[i - 1][1]);
      dp[i][2] = min(dp[i][2], dp[i - 1][2]);
      dp[i][2] = min(dp[i][2], dp[i][1]);
      dp[i][2] += a[i][2];
    }

    cout << cnt << ". " << dp[N - 1][1] << '\n';
  }

  return 0;
}