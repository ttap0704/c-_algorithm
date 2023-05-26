#include <bits/stdc++.h>
#define MODULER 1000000009
using namespace std;

long long T, N, dp[1000004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;

  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  for (int i = 4; i <= 1000000; i++) {
    for (int j = i - 3; j < i; j++) {
      dp[i] += (dp[j] % MODULER);
    }
    dp[i] %= MODULER;
  }

  while (T--) {
    cin >> N;
    cout << dp[N] << '\n';
  }

  return 0;
}