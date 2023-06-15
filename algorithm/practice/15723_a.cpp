#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M, dist[30][30];
char n1, n2;
string s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fill(&dist[0][0], &dist[0][0] + (30 * 30), INF);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> n1 >> s >> n2;
    dist[n1 - 'a'][n2 - 'a'] = 1;
  }

  for (int k = 0; k < 27; k++) {
    for (int i = 0; i < 27; i++) {
      for (int j = 0; j < 27; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> n1 >> s >> n2;
    if (dist[n1 - 'a'][n2 - 'a'] != INF) cout << 'T' << '\n';
    else cout << 'F' << '\n';
  }

  return 0;
}