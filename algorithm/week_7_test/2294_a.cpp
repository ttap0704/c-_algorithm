#include <bits/stdc++.h>
using namespace std;

const int INF = 10004;
int N, K, dp[10004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  fill(dp, dp + 10004, INF);
  dp[0] = 0;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> n;

    for (int j = n; j <= K; j++) {
      dp[j] = min(dp[j], dp[j - n] + 1);
    }
  }
  
  if (dp[K] == INF) {
    cout << -1 << '\n';
  } else {
    cout << dp[K] << '\n';
  }

  return 0;
}