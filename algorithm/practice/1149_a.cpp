#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, a[1004][3], dp[1004][3], ret = INF;


int go (int here, int before) {
  if (here == N) return 0;  
  
  int &ret = dp[here][before];
  if (ret != INF) return ret;

  for (int i = 0; i < 3; i++) {
    if (before == i) continue;
    ret = min(ret, go(here + 1, i) + a[here][i]);
  }

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }

  for (int i = 0; i < 3; i++) {
    fill(&dp[0][0], &dp[1004][3], INF);
    ret = min(ret, go(0, i));
  }

  cout << ret << '\n';

  return 0;
}