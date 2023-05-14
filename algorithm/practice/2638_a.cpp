#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, a[104][104], visited[104][104], ret;
queue<pair<int, int>> q;

int check () {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (a[i][j]) return false;
    }
  }
  return true;
}

void spreadAir (int y, int x) {
  visited[y][x] = 1;
  
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || a[ny][nx] != 0) continue;
    spreadAir(ny, nx);
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
      if (a[i][j]) q.push({i, j});
    }
  }

  while (true) {
    if (check()) break;
    memset(visited, 0, sizeof(visited));
    spreadAir(0, 0);

    vector<pair<int, int>> v;
    while (q.size()) {
      int y = q.front().first;
      int x = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (visited[ny][nx] == 1) {
          visited[y][x] += 2;
        }
      }

      if (visited[y][x] < 4) {
        v.push_back({y, x});
      } else {
        a[y][x] = 0;
      }
    }

    // cout << '\n';
    // for (int i = 0; i < N; i++) {
    //   for (int j = 0; j < M; j++) {
    //     cout << visited[i][j] << ' ';
    //   }
    //   cout << '\n';
    // }

    for (pair<int, int> p : v) q.push(p);

    ret++;
  }

  cout << ret << '\n';

  return 0;
}