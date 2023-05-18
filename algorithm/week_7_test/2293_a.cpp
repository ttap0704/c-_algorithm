#include <bits/stdc++.h>
using namespace std;

const int INF = 10004;
int N, K, n, dp[10004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  dp[0] = 1;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> n;
    for (int j = n; j <= K; j++) {
      dp[j] += dp[j - n];
    }
  }

  cout << dp[K] << '\n';

  return 0;
}