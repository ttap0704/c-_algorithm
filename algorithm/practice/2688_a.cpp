#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T, N, dp[65][10], ret[65];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  for (int i = 1; i < 10; i++) dp[1][i] = 1;
  for (int i = 1; i <= 64; i++) dp[i][1] = 1;

  ret[1] = 10;
  for (int i = 2; i <= 64; i++) {
    for (int j = 1; j < 10; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      ret[i] += dp[i][j];
    }
  }

  cin >> T;
  while (T--) {
    cin >> N;

    ll answer = 0;
    for (int i = 1; i <= N; i++) {
      answer += ret[i];
    }

    cout << answer << '\n';
  }

  return 0;
}