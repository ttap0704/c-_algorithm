#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, n, a[100004], dp[100004][5][5];

int addScore(int here, int there) {
  if (here == there) {
    return 1;
  } else if (here == 0) {
    return 2;
  } else if (here % 2 == there % 2) {
    return 4;
  } else {
    return 3;
  }
}

int go (int idx, int y, int x) {
  if (idx >= N) {
    return 0;
  }

  int &ret = dp[idx][y][x];
  if (ret) return ret;

  ret = INF;
  if (a[idx] != x) ret = min(ret, go(idx + 1, a[idx], x) + addScore(y, a[idx]));
  if (a[idx] != y) ret = min(ret, go(idx + 1, y, a[idx]) + addScore(x, a[idx]));

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  
  while (true) {
    cin >> n;
    if (n == 0) break;
    a[N] = n;
    N++;
  }

  cout << go(0, 0, 0) << '\n';

  return 0;
}