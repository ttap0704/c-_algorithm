#include <bits/stdc++.h>
using namespace std;

int N, L, R, a[54][54], b[54][54], visited[54][54], visited2[2504], cnt = 0;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<int> v[2504], v2;
vector<pair<int, int>> c;

bool checkCountry() {
  bool ret = false;
  int idx = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      v[idx].clear();
      idx++;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      visited[i][j] = 1;
      for (int k = 0; k < 4; k++) {
        int ny = i + dy[k];
        int nx = j + dx[k];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) continue;
        int num = abs(a[i][j] - a[ny][nx]);
        if (L <= num && num <= R) {
          if (!ret) ret = true;

          v[b[ny][nx]].push_back(b[i][j]);
          v[b[i][j]].push_back(b[ny][nx]);
        }
      }
    }
  }

  return ret;
}

void dfs(int start) {
  v2.push_back(start);
  visited2[start] = 1;

  for (int i : v[start]) {
    if(visited2[i]) continue;
    dfs(i);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> L >> R;

  int idx = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];

      b[i][j] = idx;
      c.push_back({i, j});
      idx++;
    }
  }

  while (true) {
    memset(visited, 0, sizeof(visited));
    memset(visited2, 0, sizeof(visited2));
    bool check = checkCountry();
    if (check) {
      cnt++;
      for (int i = 0; i < 54; i++) {
        for (int j = 0; j < v[i].size(); j++) {
          if (visited2[i]) continue;
          v2.clear();
          dfs(i);

          int sum = 0;
          for (int k : v2) {
            sum += a[c[k].first][c[k].second];
          }

          int avg = floor(sum / v2.size());
          for (int k : v2) {
            a[c[k].first][c[k].second] = avg;
          }
        }
      }
      // cout << "\n";
      // for (int i = 0; i < N; i++) {
      //   for (int j = 0; j < N; j++) {
      //     cout << a[i][j] << " ";
      //   }
      //   cout << "\n";
      // }
    } else {
      break;
    }
  }
  
  cout << cnt << "\n";
  
  return 0;
}