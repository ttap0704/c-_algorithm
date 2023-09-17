#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PI;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, a[504][504], visited[504][504], y, x, ret = 0, mx = 0;
queue<PI> q;

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

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!a[i][j] || visited[i][j]) continue;

      q.push({i, j});
      visited[i][j] = 1;
      int cnt = 1;
      while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        mx = max(mx, visited[y][x]);

        for (int i = 0; i < 4; i++) {
          int ny = y + dy[i];
          int nx = x + dx[i];

          if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || !a[ny][nx]) continue;
          visited[ny][nx] = ++cnt;
          q.push({ny, nx});
        }
      }

      ret++;
    }
  }

  cout << ret << '\n';
  cout << mx << '\n';

  return 0;
}