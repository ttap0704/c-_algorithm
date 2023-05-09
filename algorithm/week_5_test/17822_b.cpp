#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, T, x, d, k, a[54][54], visited[54][54], ret;
bool flag = 1;

void _rotate (int y, int dir, int k) {
  vector<int> v;
  for (int i = 0; i < M; i++) v.push_back(a[y][i]);
  if (dir == 1) rotate(v.begin(), v.begin() + k, v.end());
  else rotate(v.begin(), v.begin() + M - k, v.end());
  for (int i = 0; i < M; i++) a[y][i] = v[i];
  return;
}

void dfs (int y, int x) {
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = (x + dx[i] + M) % M;

    if (ny < 0 || ny >= N) continue;
    if (visited[ny][nx]) continue;

    if (a[y][x] == a[ny][nx]) {
      visited[y][x] = visited[ny][nx] = 1;
      flag = 0;
      dfs(ny, nx);
    }
  }
}

bool findAdj () {
  flag = 1;
  memset(visited, 0, sizeof(visited));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (a[i][j] == 0 || visited[i][j]) continue;
      dfs(i, j);
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visited[i][j]) a[i][j] = 0;
    }
  }

  return flag;
}

void checkNumber (int y, int x) {
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = (x + dx[i] + M) % M; 

    if (ny < 0 || nx >= N || visited[ny][nx]) continue;
    if (a[y][x] == a[ny][nx]) {
      visited[y][x] = visited[ny][nx] = 1;
      checkNumber(ny, nx);
    }
  }
}

void setAverage () {
  int sum = 0, cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (a[i][j]) cnt++, sum += a[i][j];
    }
  }

  double avg = (double) sum / (double) cnt;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (a[i][j] == 0) continue;
      if ((double)a[i][j] > avg) a[i][j]--;
      else if ((double)a[i][j] < avg) a[i][j]++;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> T;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
    }
  }

  for (int t = 0; t < T; t++) {
    cin >> x >> d >> k;
    for (int i = x - 1; i < N; i += x) {
      _rotate(i, d, k);
    }
    if (findAdj()) setAverage();
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      ret += a[i][j];
    }
  }

  cout << ret << '\n';

  return 0;
}