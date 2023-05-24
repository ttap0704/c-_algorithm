#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll T, N, M, dp[31][31];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 1; i <= 30; i++) dp[1][i] = i;

  for (int i = 2; i <= 30; i++) {
    dp[i][i] = 1;
    for (int j = i + 1; j <= 30; j++) {
      dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
    }
  }

  cin >> T;
  while (T--) {
    cin >> N >> M;
    cout << dp[N][M] << '\n';
  }

  return 0;
}