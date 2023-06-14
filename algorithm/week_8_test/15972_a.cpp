#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PI;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, H, a[2002][2002], n, visited[2002][2002];
vector<PI> v;
vector<vector<PI>> v2;

void dfs (int y, int x, vector<PI> &b) {
  visited[y][x] = 1;
  b.push_back({y, x});

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= (N * 2) + 1 || nx < 0 || nx >= (M * 2) + 1) continue;
    if (visited[ny][nx] || a[ny][nx] == 0) continue;
    dfs(ny, nx, b);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // fill(&a[0][0], &a[0][0] + (2002 * 2002), -1);

  cin >> N >> M >> H;
  for (int i = 0; i < (N * 2) + 1; i += 2) {
    for (int j = 1; j < (M * 2) + 1; j += 2) {
      cin >> n;
      if (n == -1) a[i][j] = 0;
      else a[i][j] = n;
      
      if (i != 0) a[i - 1][j] = H;
    }
  }

  for (int i = 1; i < (N * 2) + 1; i += 2) {
    for (int j = 0; j < (M * 2) + 1; j += 2) {
      cin >> n;
      if (n == -1) a[i][j] = 0;
      else a[i][j] = n;
    }
  }

  for (int i = 0; i < (N * 2) + 1; i++) {
    for (int j = 0; j < (M * 2) + 1; j++) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }

  for (int i = 0; i < (N * 2) + 1; i++) {
    for (int j = 0; j < (M * 2) + 1; j++) {
      if (visited[i][j] || a[i][j] == H || a[i][j] == 0) continue;
      v.clear();
      dfs(i, j, v);
      v2.push_back(v);
    }
  }

  for (int i = 0; i < v2.size(); i++) {
    cout << i << " : ";
    for (PI j : v2[i]) {
      cout << j.first << ":" << j.second << ' ';
    }
    cout << '\n';
  }

  return 0;
}