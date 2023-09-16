#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PI;

const int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int T, N, visited[304][304], sy, sx, ey, ex, y, x;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    memset(visited, 0, sizeof(visited));

    cin >> N;
    cin >> sy >> sx;
    cin >> ey >> ex;

    queue<PI> q;
    q.push({sy, sx});
    visited[sy][sx] = 1;

    while (q.size()) {
      tie(y, x) = q.front();
      q.pop();

      if (y == ey && x == ex) {
        cout << visited[y][x] - 1 << '\n';
        break;
      }

      for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) continue;
        visited[ny][nx] = visited[y][x] + 1;
        q.push({ny, nx});
      }
    }
  }

  return 0;
}