#include <bits/stdc++.h>
using namespace std;

int N, M, K, a[6][6], visited[6][6];
char c;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int dfs (int y, int x) {
  if (y == 0 && x == M - 1) {
    if (K == visited[y][x]) return 1;
    else return 0;
  }

  int ret = 0;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= N || nx < 0 || nx >= M || a[ny][nx] || visited[ny][nx]) continue;
    visited[ny][nx] = visited[y][x] + 1;
    ret += dfs(ny, nx);
    visited[ny][nx] = 0;
  }

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> c;

      if (c == '.') a[i][j] = 0;
      else if (c == 'T') a[i][j] = 1;
    }
  }

  visited[N - 1][0] = 1;
  int res = dfs(N - 1, 0);
  cout << res << "\n";
  return 0;
}