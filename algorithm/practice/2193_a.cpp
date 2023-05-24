#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, dp[91];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  dp[1] = 1;
  dp[2] = 1;

  cin >> N;
  for (int i = 3; i <= N; i++) dp[i] = dp[i - 1] + dp[i - 2];

  cout << dp[N] << '\n';

  return 0;
}