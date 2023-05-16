#include <bits/stdc++.h>
using namespace std;

int N, K;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  if ((K * (K + 1)) / 2 > N) {
    cout << -1 << '\n';
    return 0;
  } else {
    N -= K * (K + 1) / 2;

    if (N % K == 0) cout << (K - 1) << '\n';
    else  cout << K << '\n';
  }

  return 0;
}