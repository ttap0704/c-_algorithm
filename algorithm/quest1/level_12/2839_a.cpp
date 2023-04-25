#include <bits/stdc++.h>
using namespace std;

int N, i = 1, i2 = 0, mn = 2000;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i <= 1000; i++) {
    for (int j = 0; j <= 1667; j++) {
      if ((5 * i) + (3 * j) == N) {
        mn = min(i + j, mn);
      }
    }
  }

  if (mn == 2000) {
    cout << -1 << '\n';
  } else {
    cout << mn << '\n';
  }

  return 0;
}