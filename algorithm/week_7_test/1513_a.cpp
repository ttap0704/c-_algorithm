#include <bits/stdc++.h>
#define MAX_N 54
using namespace std;

const int mod = 1000007;
int N, M, C, a[MAX_N][MAX_N], r, c, dp[MAX_N][MAX_N][MAX_N][MAX_N];

int go (int y, int x, int cnt, int prev) {
  if (y > N || x > M) return 0;
  if (y == N && x == M) {
    if (cnt == 0 && a[y][x] == 0) return 1;
    if (cnt == 1 && a[y][x] > prev) return 1;
    
    return 0;
  }

  int &ret = dp[y][x][cnt][prev];
  if (ret != -1) return ret;
  ret = 0;

  if (a[y][x] == 0) {
    ret = (go(y + 1, x, cnt, prev) + go(y, x + 1, cnt, prev)) % mod;
  } else if (a[y][x] > prev) {
    ret = (go(y + 1, x, cnt - 1, a[y][x]) + go(y, x + 1, cnt - 1, a[y][x])) % mod;
  }

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> C;
  for (int i = 1; i <= C; i++) {
    cin >> r >> c;
    a[r][c] = i;
  }

  memset(dp, -1, sizeof(dp));
  for (int i = 0; i <= C; i++) {
    cout << go(1, 1, i, 0) << ' ';
  }  

  cout << '\n';

  return 0;
}