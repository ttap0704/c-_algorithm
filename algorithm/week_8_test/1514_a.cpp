#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, a[104], dp[104];
string n1, n2;

int go (int here, int before, int b[104]) {
  if (here == N) {
    return 0;
  }

  int &ret = dp[here];
  if (ret != INF) return ret;

  if (a[here] + before == 0) ret = min(ret, go(here + 1, before, b));
  else {
    int minus = -1;
    if (a[here] + before < 0) {
      minus = 1;
    }

    int tmp = abs(a[here] + before);

    int c[104];
    memcpy(c, b, sizeof(c));
  }

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cin >> n1 >> n2;
  
  for (int i = 0; i < N; i++) {
    a[i] = n1[i] - n2[i];
  }

  fill(dp, dp + 104, INF);
  for (int i = 0; i < N; i++) cout << a[i] << ' ';
  cout << '\n';

  return 0;
}