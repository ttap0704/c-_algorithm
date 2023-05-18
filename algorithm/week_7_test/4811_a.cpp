#include <bits/stdc++.h>
#define MAX_N 31
using namespace std;

typedef long long ll;
int N;
ll dp[MAX_N][MAX_N];

ll go (int w, int h) {
  if (w == 0 && h == 0) return 1;
  if (dp[w][h]) return dp[w][h];

  ll &ret = dp[w][h];
  if (w > 0) ret += go(w - 1, h + 1);
  if (h > 0) ret += go(w, h - 1);

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    cin >> N;
    if (N == 0) break;
    
    memset(dp, 0, sizeof(dp));
    cout << go(N, 0) << '\n';
  }

  return 0;
}