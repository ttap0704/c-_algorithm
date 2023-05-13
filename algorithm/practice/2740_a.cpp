#include <bits/stdc++.h>
using namespace std;

int N, M, K, a[104][104], b[104][104], ret[104][104];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
    }
  }

  cin >> M >> K;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < K; j++) {
      cin >> b[i][j];
    }
  }

  for (int i = 0; i < N; i++){
    for (int j = 0; j < K; j++) {
      for (int k = 0; k < M; k++) {
        ret[i][j] += a[i][k] * b[k][j];
      }
      cout << ret[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}