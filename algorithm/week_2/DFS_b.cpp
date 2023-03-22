#include <bits/stdc++.h>
using namespace std;

int ret, a[104][104], visited[104][104], n, m;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs (int y, int x) {
  visited[y][x] = 1;
  
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
    if (visited[ny][nx] == 1) continue; 
    if (a[ny][nx] == 1) {
      dfs(ny, nx);
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 1 && visited[i][j] == 0) {
        dfs(i, j);
        ret++;
      }
    }
  }

  cout << ret << "\n";

  return 0;
}