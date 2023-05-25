#include <bits/stdc++.h>
using namespace std;

int N, a[1004], dp[1004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> a[i];

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i] = max(dp[i], dp[i - j] + a[j]);
    }
  }

  cout << dp[N] << '\n';

  return 0;
}