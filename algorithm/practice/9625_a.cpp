#include <bits/stdc++.h>
using namespace std;

int K;
pair<int, int> dp[46];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> K;

  dp[0] = {1, 0};
  dp[1] = {0, 1};
  for (int i = 2; i <= K; i++) {
    dp[i].first = dp[i - 1].first + dp[i - 2].first;
    dp[i].second = dp[i - 1].second + dp[i - 2].second;
  }

  cout << dp[K].first << ' ' << dp[K].second << '\n';

  return 0;
}