#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, visited[1004][1004], mn = INF;
char a[1004][1004];
pair<int, int> j_pair;
vector<pair<int, int>> mn_v, f_pair;

void bfs (int y, int x) {
  queue<pair<int, int>> q;
  q.push({y, x});
  visited[y][x] = 1;

  while (q.size()) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
        mn = min(mn, visited[y][x]);
        continue;
      }
      if (visited[ny][nx]) continue;
      if (a[ny][nx] != '.') continue;
      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
    }
  }
}

void bfs2 (int y, int x) {
  queue<pair<int, int>> q;
  q.push({y, x});
  visited[y][x] = 1;

  while (q.size()) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue;
      if (a[ny][nx] != '.' && a[ny][nx] != 'J') continue;
      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
    }
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

      if (a[i][j] == 'J') j_pair = {i, j};
      else if (a[i][j] == 'F') f_pair.push_back({i, j});
    }
  }

  bfs(j_pair.first, j_pair.second);
  // cout << mn << "\n";
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visited[i][j] == 0) continue;
      for (int k = 0; k < 4; k++) {
        int ny = i + dy[k];
        int nx = j + dx[k];
        if ((ny < 0 || ny >= N || nx < 0 || nx >= M) && visited[i][j] == mn) {
          mn_v.push_back({i, j});
        }
      }
    }
  }

  int flag = 0;
  if (f_pair.size() != 0) {
    for (pair<int, int> j : f_pair) {
      
      memset(visited, 0, sizeof(visited));
      bfs2(j.first, j.second);
      for (pair<int, int> i : mn_v) {
        // cout << i.first << " : " << i.second << "\n";
        if (visited[i.first][i.second] > mn) {
          flag++;
          break;
        }
      }
    }
  }
  
  // int fe_val = visited[je_pair.first][je_pair.second];

  // cout << j_min << "\n";
  // cout << fe_val << "\n";

  if (flag == f_pair.size() && mn != INF) {
    cout << mn << "\n";
  } else {
    cout << "IMPOSSIBLE" << "\n";
  }

  return 0;
}