#include <bits/stdc++.h>
using namespace std;

int N, a[1004][3], dp[1004][3], ret = 1e9;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }

  dp[0][0] = a[0][0];
  dp[0][1] = a[0][1];
  dp[0][2] = a[0][2];

  for (int i = 1; i < N; i++) {
    dp[i][0] = min(a[i][0] + dp[i - 1][1], a[i][0] + dp[i - 1][2]);
    dp[i][1] = min(a[i][1] + dp[i - 1][0], a[i][1] + dp[i - 1][2]);
    dp[i][2] = min(a[i][2] + dp[i - 1][0], a[i][2] + dp[i - 1][1]);
  }

  for (int i = 0; i < 3; i++) {
    ret = min(ret, dp[N - 1][i]);
  }

  cout << ret << '\n';

  return 0;
}