#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9;
int N, a[10004], dp[10004][3], ret = INF;

int go (int here, int cnt) {
  if (here == N) return 0;

  int &ret = dp[here][cnt];
  if (ret != INF) return ret;
  
  if (cnt != 2) ret = max(ret, go(here + 1, cnt + 1) + a[here]);
  ret = max(ret, go(here + 1, 0));

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];

  fill(&dp[0][0], &dp[10004][3], INF);
  ret = max(ret, go(0, 0));

  cout << ret << '\n';

  return 0;
}