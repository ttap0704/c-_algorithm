#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, _x1, _y1, _x2, _y2, cnt = 0, visited[304][304];
char a[304][304];
bool flag = 0;

void dfs (int y ,int x) {
  visited[y][x] = 1;
  if (flag) return;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 1 || ny > N || nx < 1 || nx > M || visited[ny][nx]) continue;
    if (a[ny][nx] == '1') {
      a[ny][nx] = '0';
      visited[ny][nx] = 1;
    } else if (a[ny][nx] == '0') {
      dfs(ny, nx);
    } else if (a[ny][nx] == '#') {
      flag = 1;
      break;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fill(&a[0][0], &a[303][304], 1);
  cin >> N >> M;
  cin >> _y1 >> _x1 >> _y2 >> _x2;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> a[i][j];
    }
  }

  while (!flag) {
    cnt++;
    memset(visited, 0, sizeof(visited));
    dfs(_y1, _x1);

    // cout << "\n";
    // for (int i = 1; i <= N; i++) {
    //   for (int j = 1; j <= M; j++) {
    //     cout << a[i][j] << " ";
    //   }
    //   cout << "\n";
    // }
  }

  cout << cnt << "\n";

  return 0;
}