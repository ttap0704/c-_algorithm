#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, dist[54][54], ret = -INF;
char c;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fill(&dist[0][0], &dist[0][0] + (54 * 54), INF);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> c;
      if (c == 'Y') dist[i][j] = 1, dist[j][i] = 1;
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
    int sum = 0;
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      if (dist[i][j] <= 2) sum++;
    }
    ret = max(ret, sum);
  }

  cout << ret << '\n';

  return 0;
}