#include <bits/stdc++.h>
#define MAX_N 10004
using namespace std;

int N, a[MAX_N], dp[MAX_N];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> a[i];
  
  dp[1] = a[1], dp[2] = a[1] + a[2];
  for (int i = 3; i <= N; i++) {
    dp[i] = max(dp[i - 1], max(dp[i - 2] + a[i], dp[i - 3] + a[i] + a[i - 1]));
  }
  
  cout << dp[N] << '\n';

  return 0;
}