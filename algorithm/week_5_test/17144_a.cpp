#include <bits/stdc++.h>
using namespace std;

int dy1[] = {0, -1, 0, 1};
int dx1[] = {1, 0, -1, 0};
int dy2[] = {0, 1, 0, -1};
int dx2[] = {1, 0, -1, 0};
int N, M, T, a[54][54], sum, temp[54][54];
vector<pair<int, int>> chung1, chung2;

void mise_go (int dy[], int dx[]) {
  memset(temp, 0, sizeof(temp));
  queue<pair<int, int>> q;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (a[i][j] > 0) q.push({i, j});
    }
  }

  int y, x;
  while (q.size()) {
    tie(y, x) = q.front();
    q.pop();

    int spread = a[y][x] / 5;
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= N || nx < 0 || nx >= M || a[ny][nx] == -1) continue;
      temp[ny][nx] += spread;
      a[y][x] -= spread;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      a[i][j] += temp[i][j];
    }
  }
}

vector<pair<int, int>> setChung (int sy, int sx, int dy[], int dx[]) {
  vector<pair<int, int>> v;
  int cnt = 0;

  int y = sy;
  int x = sx;
  while (true) {
    int ny = y + dy[cnt];
    int nx = x + dx[cnt];

    if (ny == sy && nx == sx) break;
    if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
      cnt++;
      ny = y + dy[cnt];
      nx = x + dx[cnt];
    }

    if (ny == sy && nx == sx) break;
    y = ny; x = nx;
    v.push_back({ny, nx});
  }

  return v;
}

void go(vector<pair<int, int>> &v){  
  for(int i = v.size() - 1; i > 0; i--){
      a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second];
  } 
  a[v[0].first][v[0].second] = 0; 
  return;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> T;
  bool flag = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];

      if (a[i][j] == -1) {
        if (flag) {
          chung1 = setChung(i, j, dy1, dx1);
          flag = 0;
        }
        else chung2 = setChung(i, j, dy2, dx2);
      }
    }
  }

  while (T--) {
    mise_go(dy1, dx1);
    go(chung1);
    go(chung2);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (a[i][j] > 0) sum += a[i][j];
    }
  }

  cout << sum << '\n';

  return 0;
}