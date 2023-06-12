#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M, X, a, b, c, dist[1001][1001], ret = -INF;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fill(&dist[0][0], &dist[0][0] + (1001 * 1001), INF);

  cin >> N >> M >> X;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    dist[a][b] = c;
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  
  dist[X][X] = 0;

  for (int i = 1; i <= N; i++) {
    // cout << "min : " << (dist[i][X] + dist[X][i]) << '\n';
    ret = max(ret, dist[i][X] + dist[X][i]);
  }

  cout << ret << '\n';

  return 0;
}