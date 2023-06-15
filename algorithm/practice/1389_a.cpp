#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M, y, x, dist[104][104], mn = INF, ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fill(&dist[0][0], &dist[0][0] + (104 * 104), INF);
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> y >> x;
    dist[y][x] = 1;
    dist[x][y] = 1;
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    int sum = 0;
    for (int j = 1; j <= N; j++) {
      if (i == j) continue;
      sum += dist[i][j];
    }
    if (mn > sum) {
      mn = sum;
      ret = i;
    }
  }

  cout << ret << '\n';

  return 0;
}