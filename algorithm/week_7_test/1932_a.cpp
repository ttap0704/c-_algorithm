#include <bits/stdc++.h>
using namespace std;

int N, a[504][504], dp[504][504];

int go (int here, int before) {
  if (here == N) return 0;

  int &ret = dp[here][before];
  if (ret) return ret;

  ret = max(ret, go(here + 1, before) + a[here][before]);
  if (before + 1 < here + 1) ret = max(ret, go(here + 1, before + 1) + a[here][before + 1]);

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i + 1; j++) {
      cin >> a[i][j];
    }
  }

  cout << go(1, 0) + a[0][0] << '\n';
  
  return 0;
}