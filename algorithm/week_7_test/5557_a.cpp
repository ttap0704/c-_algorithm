#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N, a[104], answer;
ll dp[104][1004];
vector<int> v[104];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N - 1; i++) cin >> a[i];
  cin >> answer;

  dp[0][a[0]] = 1;
  set<int> set[104];
  set[0].insert(a[0]);

  for (int i = 1; i < N - 1; i++) {
    for (int j : set[i - 1]) {
      if (j - a[i] >= 0) {
        dp[i][j - a[i]] += dp[i - 1][j];
        set[i].insert(j - a[i]);
      }
      
      if (j + a[i] <= 20) {
        dp[i][j + a[i]] += dp[i - 1][j];
        set[i].insert(j + a[i]);
      }
    }
  }

  cout << dp[N - 2][answer] << '\n';

  return 0;
}