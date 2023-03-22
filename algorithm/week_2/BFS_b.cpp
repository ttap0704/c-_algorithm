#include <bits/stdc++.h>
using namespace std;

int n, m, sy, sx, ey, ex;
int a[104][104], visited[104][104];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void bfs (int y, int x) {
  queue<pair<int ,int>> q;
  visited[y][x] = 1;
  q.push({y, x});

  while(q.size()) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (a[ny][nx] == 0) continue;
      if (visited[ny][nx]) continue;
      visited[ny][nx] = visited[y][x] + 1;

      q.push({ny, nx});
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  cin >> sy >> sx;
  cin >> ey >> ex;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  bfs(sy, sx);

  cout << visited[ey][ex] << "\n\n";

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << visited[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}