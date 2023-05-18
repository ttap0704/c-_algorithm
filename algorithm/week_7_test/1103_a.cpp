#include <bits/stdc++.h>
#define MAX_NUM 50
using namespace std;

const int INF = -1e9;
const int INF2 = 1e9;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, dp[MAX_NUM][MAX_NUM][4], ret = 1;
char c, a[MAX_NUM][MAX_NUM];

void go (int y, int x, int dir) {
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    
    if (i % 2 == 0) {
      ny = y + (dy[i] * (a[y][x] - '0'));
    } else {
      nx = x + (dx[i] * (a[y][x] - '0'));
    }

    if (ny < 0 || ny >= N || nx < 0 || nx >= M || a[ny][nx] == 'H') continue;
    if (dp[ny][nx][i] != -1) {
      ret = INF2;
      break;
    }

    dp[ny][nx][i] = dp[y][x][dir] + 1;
    // cout << "cnt : " << dp[ny][nx][i] << '\n';
    // cout << ny << " : " << nx << '\n';
    go(ny, nx, i);
    ret = max(ret, dp[ny][nx][i]);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
    }
  }

  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = 1;
  go(0, 0, 0);

  if (ret == INF2) cout << -1 << '\n';
  else cout << ret << '\n';

  return 0;
}