#include <bits/stdc++.h>
using namespace std;

int N, M, a[101][101], visited[101][101], cnt = 0, c_cnt = 0;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> v;
vector<int> cnt_v;

void dfs (int y, int x) {
  visited[y][x] = 1;
  if (a[y][x] == 1) {
    v.push_back({y, x});
    return;
  };
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
    if (visited[ny][nx]) continue;
    
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
      cin >> a[i][j];
    }
  }
  
  while (true) {
    c_cnt = 0;
    v.clear();
    fill(&visited[0][0], &visited[N - 1][M], 0);
    dfs(0, 0);
    for (pair<int, int> i : v) {
      a[i.first][i.second] = 0;
    }

    if (v.size() == 0) {
      if (cnt == 0) {
        cout << 0 << "\n";
        cout << 0 << "\n";
      } else {
        int last_cnt = cnt_v.back();
        cout << cnt << "\n";
        cout << last_cnt << "\n";
      }
      break;
    } else {
      cnt++;
      cnt_v.push_back(v.size());
    }
  }

  
  return 0;
}