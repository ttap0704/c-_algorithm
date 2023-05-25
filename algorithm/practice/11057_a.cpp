#include <bits/stdc++.h>
using namespace std;

int N, dp[1004][10];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i <= 9; i++) {
    dp[1][i] = 1;
  }

  for (int i = 2; i <= N; i++) {
    dp[i][0] = 1;
    for (int j = 1; j <= 9; j++) {
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
    }
  }

  
  int ret = 0;
  for (int i = 0; i <= 9; i++) ret += dp[N][i];
  cout << ret % 10007 << '\n';

  return 0;
}