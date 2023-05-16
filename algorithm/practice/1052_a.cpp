#include <bits/stdc++.h>
using namespace std;

int N, K, ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  while (true) {
    int tmp = N, cnt = 0;
    while (tmp > 0) {
      if (tmp % 2 != 0) cnt++;
      tmp /= 2;
    }

    if (K >= cnt) break;

    N++;
    ret++;
  }

  cout << __builtin_popcount(N) << '\n';
  cout << ret << '\n';

  return 0;
}