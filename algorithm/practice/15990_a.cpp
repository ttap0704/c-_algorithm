#include <bits/stdc++.h>
#define MODULER 1000000009
using namespace std;

typedef long long ll;
ll T, N, dp[100004][4];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;

  dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 0;
  dp[2][1] = 0; dp[2][2] = 1; dp[2][3] = 0;
  dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;

  for (int i = 4; i <= 100000; i++) {
    dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MODULER;
    dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MODULER;
    dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MODULER;
  }

  while (T--) {
    cin >> N;

    ll ret = 0;
    for (int i = 1; i <= 3; i++) ret = (ret + dp[N][i]) % MODULER;

    cout << (ret % MODULER) << '\n';
  }

  return 0;
}