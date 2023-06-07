#include <bits/stdc++.h>
using namespace std;

int N, K, w, v, dp[100004], ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> w >> v;
    
    for (int j = K; j >= w; j--) {
      dp[j] = max(dp[j], dp[j - w] + v);
    }
  }

  cout << dp[K] << '\n';

  return 0;
}