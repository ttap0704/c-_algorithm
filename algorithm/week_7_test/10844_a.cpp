#include <bits/stdc++.h>
#define MODULER 1000000000
using namespace std;

typedef long long ll;
ll N, dp[104][11], ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 1; i <= 9; i++) dp[1][i] = 1;
  dp[1][0] = 0;

  for (int i = 2; i <= N; i++) {
    for (int j = 0; j <= 9; j++) {
      if (j == 0) dp[i][j] = dp[i - 1][j + 1] % MODULER;
      else if (j == 9) dp[i][j] = dp[i - 1][j - 1] % MODULER;
      else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MODULER;
    }
  }

  for (int i = 0; i < 10; i++) {
    ret += dp[N][i];
  }  

  cout << ret % MODULER << '\n';

  return 0;
}