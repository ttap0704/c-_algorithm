#include <bits/stdc++.h>
using namespace std;

int N, dp[100004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    dp[i] = i;
    for (int j = 1; j * j <= i; j++) {
      dp[i] = min(dp[i], dp[i - (j * j)] + 1);
    }
  }

  cout << dp[N] << '\n';

  return 0;
}