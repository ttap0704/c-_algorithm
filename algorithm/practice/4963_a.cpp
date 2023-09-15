#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int w, h, a[54][54], visited[54][54], cnt;

void dfs(int y, int x) {
  visited[y][x] = 1;

  for (int i = 0; i < 8; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    
    if (ny < 0 || ny >= h || nx < 0 || nx >= w || visited[ny][nx] || !a[ny][nx]) continue;
    dfs(ny, nx);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0) break;

    memset(a, 0, sizeof(a));
    memset(visited, 0, sizeof(visited));
    cnt = 0;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> a[i][j];
      }
    }

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (!a[i][j] || visited[i][j]) continue;
        dfs(i, j);
        cnt++;
      }
    }

    cout << cnt << '\n';
  }

  return 0;
}