#include <bits/stdc++.h>
using namespace std;

int N, M, K, a[6][6], visited[6][6], idx = 0, cnt = 0;
char s;
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
    if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || a[ny][nx] == 2) continue;
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
      cin >> s;
      if (s == '.') a[i][j] = 0;
      else a[i][j] = 2;
    }
  }
  visited[N - 1][0] = 1;
  cout << dfs(N - 1, 0) << "\n";

  return 0;
}