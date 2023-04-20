#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, visited[30], mx = 1;
char a[20][20];

void dfs (int y, int x) {
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[a[ny][nx] - 'A']) continue;
    visited[a[ny][nx] - 'A'] = visited[a[y][x] - 'A'] + 1;
    mx = max(mx, visited[a[ny][nx] - 'A']);
    dfs(ny, nx);
    visited[a[ny][nx] - 'A'] = 0;
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

  visited[a[0][0] - 'A'] = 1;
  dfs(0, 0);

  cout << mx << "\n";
  return 0;
}