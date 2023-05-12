#include <bits/stdc++.h>
using namespace std;

int N, M, K, n, a[304][304], tmpi, tmpj, y, x;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> n;
      a[i][j] = n;
    }
  }

  cin >> K;
  for (int k = 0; k < K; k++) {
    cin >> tmpi >> tmpj >> y >> x;
   
    int sum = 0;
    for (int i = tmpi; i <= y; i++) {
      for (int j = tmpj; j <= x; j++) {
        sum += a[i][j];
      }
    }

    cout << sum << '\n';
  }



  return 0;
}