#include <bits/stdc++.h>
using namespace std;

int N, a[304], dp[304];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];

  dp[0] = a[0];
  dp[1] = a[0] + a[1];
  dp[2] = max(a[0] + a[2], a[1] + a[2]);

  for (int i = 3; i < N; i++) {
    dp[i] = max(dp[i - 2] + a[i], dp[i - 3] + a[i - 1] + a[i]);
  }

  cout << dp[N - 1] << '\n';

  return 0;
}