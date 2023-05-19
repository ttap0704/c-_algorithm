#include <bits/stdc++.h>
using namespace std;

int n, c, m1, m2, dp[100004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    scanf("%d %d.%d", &n, &m1, &m2);
    if (n == 0) break;
    int cost = m1 * 100 + m2;

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
      scanf("%d %d.%d", &c, &m1, &m2);
      int p = m1 * 100 + m2;

      for (int j = p; j <= cost; j++) {
        dp[j] = max(dp[j], dp[j - p] + c);
        cout << j << " : " << dp[j] << '\n';
      }
    }
    printf("%d\n", dp[cost]);
  }

  return 0;
}