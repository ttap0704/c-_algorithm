#include <bits/stdc++.h>
#define MAX_N 1004
using namespace std;

int N, n, a[MAX_N], dp[MAX_N], r_dp[MAX_N], ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];

  for (int i = 0; i < N; i++) {
    dp[i] = 1;
    for (int j = 0; j <= i; j++) {
      if (a[i] > a[j] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
    }
  }

  for (int i = N - 1; i >= 0; i--) {
    r_dp[i] = 1;
    for (int j = N - 1; j >= i; j--) {
      if (a[i] > a[j] && r_dp[i] < r_dp[j] + 1) r_dp[i] = r_dp[j] + 1;
    }
  }

  for (int i = 0; i < N; i++) ret = max(dp[i] + r_dp[i] - 1, ret);

  cout << ret << '\n';

  return 0;
}