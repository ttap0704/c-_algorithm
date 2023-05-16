#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1};
const int dx[] = {1, 1, 1};
int R, C, ret, visited[10004][504];
char a[10004][504];
bool flag = 0;

void dfs (int y, int x) {
  visited[y][x] = 1;
  if (x == C - 1) {
    ret++;
    flag = 1;
    return;
  }

  for (int i = 0; i < 3; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx] || a[ny][nx] != '.') continue;
    dfs(ny, nx);
    if (flag) return;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < R; i++) {
    flag = 0;
    dfs(i, 0);
  }
  // for (int i = 0; i < R; i++) {
  //   for (int j = 0; j < C; j++) {
  //     cout << visited[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  cout << ret << '\n';

  return 0;
}