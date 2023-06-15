#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, n, dist[104][104];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fill(&dist[0][0], &dist[0][0] + (104 * 104), INF);
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> n;
      if (n == 1) dist[i][j] = n;
    }
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
      if (dist[i][j] != INF) cout << 1 << ' ';
      else cout << 0 << ' ';
    }
    cout << '\n';
  }

  return 0;
}