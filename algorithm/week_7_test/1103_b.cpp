#include <bits/stdc++.h>
#define MAX_NUM 50
using namespace std;

const int INF = 1e9;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, dp[MAX_NUM][MAX_NUM], a[MAX_NUM][MAX_NUM], visited[MAX_NUM][MAX_NUM];
char c;

bool check (int y, int x) {
  return (y < 0 || y >= N || x < 0 || x >= M);
}

int go (int y, int x) {
  if (!a[y][x] || check(y, x)) return 0;
  if (visited[y][x]) {
    cout << -1 << '\n';
    exit(0);
  }

  int &ret = dp[y][x];
  if (ret) return ret;
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++) {
    int ny = y + (dy[i] * a[y][x]);
    int nx = x + (dx[i] * a[y][x]);
    
    ret = max(ret, go(ny, nx) + 1);
  }
  visited[y][x] = 0;

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> c;
      if (c == 'H') a[i][j] = 0;
      else a[i][j] = (c - '0');
    }
  }
  
  cout << go(0, 0) << '\n';

  return 0;
}