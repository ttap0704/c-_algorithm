#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, a[26][26], visited[26][26];
vector<int> ret;
char c;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> c;
      a[i][j] = (c - '0');
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (a[i][j] == 0 || visited[i][j]) continue;
      queue<pair<int, int>> q;
      q.push({i, j});
      visited[i][j] = 1;
      int cnt = 1;

      while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
          int ny = y + dy[d];
          int nx = x + dx[d];

          if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
          if (visited[ny][nx] || a[ny][nx] == 0) continue;

          visited[ny][nx] = 1;
          q.push({ny, nx});
          cnt++;
        }
      }
      
      ret.push_back(cnt);
    }
  }

  sort(ret.begin(), ret.end());
  cout << ret.size() << '\n';
  for (int i : ret) cout << i << '\n';

  return 0;
}