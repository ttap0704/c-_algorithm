#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9;
int N, S, M, a[54], dp[54][54000];

int go (int here, int sum) {
  if (sum < 0 || sum > M) return INF;
  if (here > N) return 0;

  int &ret = dp[here][sum];
  if (ret) return ret;

  ret = INF;
  ret = max(ret, go(here + 1, sum + a[here]) + a[here]);
  ret = max(ret, go(here + 1, sum - a[here]) - a[here]);

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> S >> M;
  a[0] = S;
  for (int i = 1; i <= N; i++) cin >> a[i];

  int mx = go(0, 0);
  if (mx < 0) cout << -1 << '\n';
  else cout << mx << '\n';

  return 0;
}