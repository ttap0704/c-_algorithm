#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M, a, b, c, dist[104][104];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N;
  cin >> M;
  fill(&dist[0][0], &dist[103][104], INF);
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    --a; --b;

    dist[a][b] = dist[a][b] ? min(dist[a][b], c) : c;
  }

  
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) cout << 0 << ' ';
      else cout << (dist[i][j] == INF ? 0 : dist[i][j]) << ' ';
    }
    cout << '\n';
  }

  return 0;
}