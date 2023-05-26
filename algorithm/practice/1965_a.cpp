#include <bits/stdc++.h>
using namespace std;

int N, a[1004], dp[1004], ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];

  fill(dp, dp + 1004, 1);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      if (a[i] > a[j] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
      }

    }
    ret = max(ret, dp[i]);
  }

  cout << ret << '\n';

  return 0;
}