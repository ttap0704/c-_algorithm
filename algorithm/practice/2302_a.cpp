#include <bits/stdc++.h>
using namespace std;

int N, M, n, a[41], fibo[41], ret = 1;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < M; i++) cin >> n, a[n] = 1;

  fibo[0] = 1;
  fibo[1] = 1;
  for (int i = 2; i <= 40; i++) fibo[i] = fibo[i - 1] + fibo[i - 2];

  int num = 0;
  for (int i = 1; i <= N; i++) {
    if (a[i]) {
      ret *= fibo[num];
      num = 0;
    } else {
      num++;
    }
  }
  ret *= fibo[num];

  cout << ret << '\n';

  return 0;
}