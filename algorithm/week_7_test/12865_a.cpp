#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9;
int N, K, w, v, dp[100004];

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

  // for (int i = 0; i <= K; i++) {
  //   cout << i << " : " << dp[i] << '\n';
  // }

  return 0;
}