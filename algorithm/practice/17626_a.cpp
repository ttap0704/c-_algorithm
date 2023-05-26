#include <bits/stdc++.h>
using namespace std;

int N, dp[50004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 1; i <= N; i++) dp[i] = i;
  
  for (int i = 2; i <= N; i++) {
    for (int j = 2; j <= i; j++) {
      if (j * j > N) break;
      
      if (i - (j * j) >= 0) {
        dp[i] = min(dp[i], dp[i - (j * j)] + 1);
      }
    }
  }

  cout << dp[N] << '\n';

  return 0;
}