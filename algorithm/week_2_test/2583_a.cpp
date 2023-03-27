#include <bits/stdc++.h>
using namespace std;

int Y, X, K, a[104][104], visited[104][104];
vector<int> ret;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs (int y, int x, int &r) {
  r++;
  visited[y][x] = 1;
  
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= Y || nx < 0 || nx >= X) continue;
    if (a[ny][nx] != 1) continue;
    if (visited[ny][nx] == 1) continue;
    dfs(ny, nx, r);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> Y >> X >> K;

  fill(&a[0][0], &a[104 - 1][104], 1);
  fill(&visited[0][0], &visited[104 - 1][104], 0);

  for (int i = 0; i < K; i++) {
    int x, y, nx, ny;
    cin >> x >> y >> nx >> ny;

    for (int j = y; j < ny; j++) {
      for (int k = x; k < nx; k++) {
        a[j][k] = 0;
      }
    }
  }

  for (int i = 0; i < Y; i++) {
    for (int j = 0; j < X; j++) {
      if (visited[i][j] == 0 && a[i][j] == 1) {
        int cnt = 0;
        dfs(i, j, cnt);
        ret.push_back(cnt);
      }
    }
  }

  sort(ret.begin(), ret.end());

  cout << ret.size() << "\n";
  for (int i : ret) cout << i << " ";
  
  return 0;
}