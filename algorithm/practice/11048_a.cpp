#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9;
const int dy[] = {1, 0, 1};
const int dx[] = {0, 1, 1};
int N, M, a[1004][1004], dp[1004][1004];

int go (int y, int x) {
  if (y == N && x == M) {
    return a[N][M];
  }

  int &ret = dp[y][x];
  if (ret != INF) return ret;

  for (int i = 0; i < 3; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny > N || nx > M) continue;
    ret = max(ret, go(ny, nx) + a[y][x]);
  }

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> a[i][j];
    }
  }

  fill(&dp[0][0], &dp[1003][1004], INF);
  cout << go(1, 1) << '\n';

  return 0;
}