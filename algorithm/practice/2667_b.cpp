#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int N, a[26][26], visited[26][26];
vector<int> v;
string s;

int dfs (int y, int x) {
  int cnt = 1;
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || !a[ny][nx]) continue;
    cnt += dfs(ny, nx);
  }

  return cnt;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (int j = 0; j < N; j++) {
      a[i][j] = s[j] - '0';
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (visited[i][j] || !a[i][j]) continue;
      int cnt = dfs(i, j);
      v.push_back(cnt);
    }
  }

  sort(v.begin(), v.end());
  
  cout << v.size() << '\n';
  for (int i : v) cout << i << '\n';

  return 0;
}