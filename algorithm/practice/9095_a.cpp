#include <bits/stdc++.h>
using namespace std;

int T, N, dp[12];


int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  for (int i = 4; i <= 11; i++) dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];

  while (T--) {
    cin >> N;

    cout << dp[N] << '\n';
  }

  return 0;
}