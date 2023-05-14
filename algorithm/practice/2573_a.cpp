#include <bits/stdc++.h>
using namespace std;

struct Bing {
  int y, x, m;
};

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, a[304][304], visited[304][304], ret = 0;
queue<pair<int, int>> q;

void dfs (int y, int x) {
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || a[ny][nx] == 0) continue;
    dfs(ny, nx);
  }
}

int check () {
  int cnt = 0;
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visited[i][j] || a[i][j] == 0) continue;
      dfs(i, j);
      cnt++;
    }
  }

  // cout << '\n';
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < M; j++) {
  //     cout << a[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  // cout << "cnt : " << cnt << '\n';
  return cnt;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
      if (a[i][j]) q.push({i, j});
    }
  }

  while (true) {
    int comp = check();
    if (comp > 1) break;
    else if (comp == 0) {
      ret = 0;
      break;
    }

    queue<Bing> q2;
    int y, x;
    while (q.size()) {
      tie(y, x) = q.front();
      q.pop();
      
      int cnt = 0;
      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (a[ny][nx] == 0) cnt++;
      }
      q2.push({y, x, cnt});
    }

    while (q2.size()) {
      Bing tmp = q2.front();
      q2.pop();

      a[tmp.y][tmp.x] -= tmp.m;
      if (a[tmp.y][tmp.x] <= 0) a[tmp.y][tmp.x] = 0;
      else q.push({tmp.y, tmp.x});
    }

    ret++;
  }

  cout << ret << '\n';

  return 0;
}