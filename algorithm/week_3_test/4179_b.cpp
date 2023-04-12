#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, visited[1004][1004], visited2[1004][1004], mn = INF, ret = 0;
char a[1004][1004];
pair<int, int> j_pair;
vector<pair<int, int>> mn_v;

int main () {
  cin >> N >> M;
  queue<pair<int, int>> q;
  fill(&visited[0][0], &visited[1003][1004], INF);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];

      if (a[i][j] == 'J') j_pair = {i, j};
      else if (a[i][j] == 'F') {
        q.push({i, j});
        visited[i][j] = 1;
      };
    }
  }
  
  while(q.size()) {
    int y;
    int x;
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] != INF || a[ny][nx] == '#') continue;
      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
    }
  }

  q.push({j_pair.first, j_pair.second});
  visited2[j_pair.first][j_pair.second] = 1;
  while (q.size()) {
    int y;
    int x;
    tie(y, x) = q.front();
    q.pop();

    if ((y == 0 || x == 0 || y == N - 1 || x == M - 1) && visited2[y][x] < visited[y][x]) {
      ret = visited2[y][x];
      break;
    }

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited2[ny][nx] != 0 || a[ny][nx] != '.') continue;
      visited2[ny][nx] = visited2[y][x] + 1;
      q.push({ny, nx});
    }
  }

  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < M; j++) {
  //     cout << visited2[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  if (ret == 0) {
    cout << "IMPOSSIBLE" << "\n";
  } else {
    cout << ret << "\n";
  }
  
  return 0;
}