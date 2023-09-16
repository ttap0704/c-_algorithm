#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PI;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, a[104][104], ret = 1, y, x, mx = -1e9;
queue<PI> q;
bool visited[104][104];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
      mx = max(mx, a[i][j]);
    }
  }

  for (int water = 1; water < mx; water++) {
    memset(visited, 0, sizeof(visited));
    int cnt = 0;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (visited[i][j] || a[i][j] <= water) continue;

        q.push({i, j});
        visited[i][j] = 1;
        while (q.size()) {
          tie(y, x) = q.front();
          q.pop();

          for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || a[ny][nx] <= water) continue;
            q.push({ny, nx});
            visited[ny][nx] = 1;
          }
        }

        cnt++;
      }
    }

    ret = max(ret, cnt);
  }

  cout << ret << '\n';
  
  return 0;
}