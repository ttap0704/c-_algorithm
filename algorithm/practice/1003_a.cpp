#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N, T;
pair<ll, ll> dp[41];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  dp[0] = {1, 0};
  dp[1] = {0, 1};

  for (int i = 2; i <= 40; i++) {
    dp[i] = {dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second};
  }

  cin >> T;
  while (T--) {
    cin >> N;

    cout << dp[N].first << ' ' << dp[N].second << '\n';
  }

  return 0;
}