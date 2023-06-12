#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9;
int N, K, a, b, T, dist[404][404];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fill(&dist[0][0], &dist[0][0] + (404 * 404), INF);

  cin >> N >> K;
  for (int i = 0; i < K; i++) {
    cin >> a >> b;
    dist[a][b] = 1;
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (i == j) continue;
        dist[i][j] = max(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  cin >> T;
  while (T--) {
    cin >> a >> b;

    if (dist[a][b] < 0 && dist[b][a] < 0) cout << 0 << '\n';
    else if (dist[a][b] > dist[b][a]) cout << -1 << '\n';
    else cout << 1 << '\n';
  }

  // for (int i = 1; i <= N; i++) {
  //   for (int j = 1; j <= N; j++) {
  //     if (i == j) continue;
  //     cout << i << " : " << j << " : " << dist[i][j] << '\n';
  //   }
  // }


  return 0;
}