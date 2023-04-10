#include <bits/stdc++.h>
using namespace std;

int N, M, origin[9][9], a[9][9], visited[9][9], cnt, mx = 0;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> v, bv;
vector<int> cnt_v;

void dfs (int y, int x) {
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
    if (a[ny][nx] == 1) continue;
    if (visited[ny][nx] == 1) continue;
    a[ny][nx] = 2;
    dfs(ny, nx);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> origin[i][j];
      if (origin[i][j] == 2) {
        bv.push_back({i, j});
      }
      if (origin[i][j] == 0) {
        v.push_back({i, j});
      }
    }
  }

  

  for (int k = 0; k < v.size(); k++) {
    for (int l = 0; l < k; l++) {
      for (int m = 0; m < l; m++) {
        memcpy(a, origin, sizeof(origin));
        a[v[k].first][v[k].second] = 1;
        a[v[l].first][v[l].second] = 1;
        a[v[m].first][v[m].second] = 1;
        cnt = 0;
        fill(&visited[0][0], &visited[N - 1][M], 0);

        for (int i = 0; i < bv.size(); i++) {
          dfs(bv[i].first, bv[i].second);
        }
        
        for (int i = 0; i < N; i++) {
          for (int j = 0; j < M; j++) {
            if (a[i][j] == 0) cnt++;
          }
        }
        mx = max(mx, cnt);
        a[v[m].first][v[m].second] = 0;
        a[v[l].first][v[l].second] = 0;
        a[v[k].first][v[k].second] = 0;
      }
    }
  }

  cout << mx << "\n";

  return 0;
}