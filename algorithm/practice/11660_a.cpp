#include <bits/stdc++.h>
#define MAX_N 1025
using namespace std;

typedef long long ll;
ll N, M, a[MAX_N][MAX_N], dp[MAX_N][MAX_N];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      dp[i][j] = dp[i][j - 1] + a[i][j];
    }
  }

  while (M--) {
    ll y1, x1, y2, x2, ret = 0;
    cin >> y1 >> x1 >> y2 >> x2;

    for (int i = y1; i <= y2; i++) {
      ret += dp[i][x2] - dp[i][x1 - 1];
    }

    cout << ret << '\n';
  }


  // for (int i = 1; i <= N; i++) {
  //   for (int j = 1; j <= N; j++) {
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  return 0;
}