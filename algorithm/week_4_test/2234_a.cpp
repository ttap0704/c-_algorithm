#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
const int INF = -1e9;
int N, M, a[54][54], visited[54][54], visited2[54][54], mx = INF, mx2 = INF;
vector<int> v;

int dfs (int y, int x, int room_num) {
  int cnt = 1;
  for (int i = 0; i < 4; i++) {
    int ny = y, nx = x;

    if (i == 0) nx -= 1;
    else if (i == 1) ny -= 1;
    else if (i == 2) nx += 1;
    else if (i == 3) ny += 1;

    if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

    if ((a[y][x] & (1 << i)) == 0) {
      if (visited[ny][nx]) continue;

      visited[ny][nx] = room_num;
      cnt += dfs(ny, nx, room_num);
    }
  }

  return cnt;
}

void dfs2 (int y, int x, int room_num) {
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited2[ny][nx]) continue;
    if (visited[ny][nx] == room_num) {
      visited2[ny][nx] = 1;
      dfs2(ny, nx, room_num);
    } else if (visited[ny][nx] != room_num) {
      mx2 = max(mx2, v[room_num - 1] + v[visited[ny][nx] - 1]);
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> M >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
    }
  }

  int room_cnt = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visited[i][j]) continue;
      visited[i][j] = room_cnt;
      int room_size = dfs(i, j, room_cnt);

      mx = max(mx, room_size);
      v.push_back(room_size);

      room_cnt++;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visited2[i][j]) continue;
      visited2[i][j] = 1;
      dfs2(i, j, visited[i][j]);
    }
  }
  
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < M; j++) {
  //     cout << visited[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
    
  cout << room_cnt - 1 << '\n';
  cout << mx << '\n';
  cout << mx2 << '\n';

  return 0;
}