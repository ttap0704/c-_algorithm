#include <bits/stdc++.h>
using namespace std;

int D, K, a[34], b[34];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> D >> K;
  a[1] = 1; a[2] = 0;
  b[1] = 0; b[2] = 1;
  for (int i = 3; i <= D; i++) {
    a[i] = a[i - 1] + a[i - 2];
    b[i] = b[i - 1] + b[i - 2];
  }

  for (int i = 1; i <= K; i++) {
    int tmp = K - (a[D] * i);
    if (tmp % b[D] == 0) {
      cout << i << '\n';
      cout << tmp / b[D] << '\n';
      return 0;
    }
  }

  return 0;
}