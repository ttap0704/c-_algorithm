#include <bits/stdc++.h>
using namespace std;

int N, W, ey, ex, dp[1004][1004], py[1004], px[1004];

int calc (int a, int b) {
  return abs(px[a] - px[b]) + abs(py[a] - py[b]);
}

int go (int a, int b) {
  if (a == W + 1 || b == W + 1) return 0;
  if (dp[a][b]) return dp[a][b];
  
  int next = max(a, b) + 1;
  return dp[a][b] = min(go(a, next) + calc(b, next), go(next, b) + calc(a, next));
}

void solve() {
  int a = 0, b = 1;
  for (int i = 2; i < W + 2; i++) {
    if (dp[i][b] + calc(a, i) < dp[a][i] + calc(b, i)) cout << 1 << '\n', a = i;
    else cout << 2 << '\n', b = i;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> W;
  px[0] = 1; py[0] = 1;
  px[1] = N; py[1] = N;

  for (int i = 2; i < W + 2; i++) {
    cin >> ey >> ex;
    py[i] = ey; px[i] = ex;
  }

  cout << go(0, 1) << '\n';
  solve();

  return 0;
}