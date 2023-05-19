#include <bits/stdc++.h>
using namespace std;

int N, dp[104];
pair<int, int> p[20];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> p[i].first;
  }
  for (int i = 0; i < N; i++) {
    cin >> p[i].second;
  }

  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < N; i++) {
    pair<int, int> tmp = p[i];

    for (int j = 100; j > tmp.first; j--) {
      dp[j] = max(dp[j], dp[j - tmp.first] + tmp.second);
    }
  }

  cout << dp[100] << '\n';

  return 0;
}