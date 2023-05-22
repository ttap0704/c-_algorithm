#include <bits/stdc++.h>
using namespace std;

int era[21];
double A, B, dp[20][20][20];

double go (int idx, int y, int x) {
  if (idx == 19) return !era[y] || !era[x] ? 1.0 : 0.0;
  
  double &ret = dp[idx][y][x];
  if (ret > -0.5) return ret;

  ret = 0.0;
  ret += go(idx + 1, y + 1, x) * A * (1 - B);
  ret += go(idx + 1, y, x + 1) * (1 - A) * B;
  ret += go(idx + 1, y + 1, x + 1) * A * B;
  ret += go(idx + 1, y, x) * (1 - A) * (1 - B);

  return ret;
}

void setEra () {
  era[0] = 1; era[1] = 1;
  for (int i = 2; i <= 20; i++) {
    if (era[i]) continue;
    for (int j = i * 2; j <= 20; j += i) {
      era[j] = 1;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B;

  A /= 100;
  B /= 100;

  memset(dp, -1, sizeof(dp));
  setEra();
  cout.precision(6);
  cout << fixed;
  cout << go(1, 0, 0) << '\n';

  return 0;
}