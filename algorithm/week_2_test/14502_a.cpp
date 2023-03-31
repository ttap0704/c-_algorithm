#include <bits/stdc++.h>
using namespace std;

int N, M, origin[9][9], a[9][9], visited[9][9], cnt, mx = 0;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0 ,-1};
vector<pair<int, int>> v;
vector<int> cnt_v;

void dfs (int y, int x) {
  a[y][x] = 2;
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
    if (a[ny][nx] != 0) continue;
    if (visited[ny][nx] == 1) {
      cout << ny << " : " << nx << "\n";
      continue;
    }
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

      if (origin[i][j] == 0) {
        v.push_back({i, j});
      }
    }
  }

  

  for (int k = 0; k < v.size(); k++) {
    memcpy(a, origin, sizeof(origin));
    fill(&visited[0][0], &visited[N - 1][M], 0);
    a[v[k].first][v[k].second] = 1;

    for (int l = k + 1; l < v.size(); l++) {
      a[v[l].first][v[l].second] = 1;

      for (int m = l + 1; m < v.size(); m++) {
        a[v[m].first][v[m].second] = 1;

        cnt = 0;
        for (int i = 0; i < N; i++) {
          for (int j = 0; j < M; j++) {
            if (a[i][j] == 2 && visited[i][j] == 0) {
              dfs(i, j);
            }

            if (a[i][j] == 0) cnt++;
            cout << a[i][j] << " ";
          }
          cout << "\n";
        }
        cout << "\n\n";

        cnt_v.push_back(cnt);
        a[v[m].first][v[m].second] = 0;
      }
      a[v[l].first][v[l].second] = 0;
    }
    a[v[k].first][v[k].second] = 0;
  }

  for (int i : cnt_v) {
    mx = max(mx, i);
  }

  cout << mx << "\n";

  return 0;
}