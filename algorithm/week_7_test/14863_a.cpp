#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = -1e9;
ll N, K, dp[104][100004];
pair<ll, ll> a[104], b[104];

ll go (ll here, ll ti) {
  if (here == N) return dp[here][ti];

  ll &ret = dp[here][ti];
  if (ret) return ret;
  ret = INF;
  if (ti + a[here].first <= K) ret = max(ret, go(here + 1, ti + a[here].first) + a[here].second);
  if (ti + b[here].first <= K) ret = max(ret, go(here + 1, ti + b[here].first) + b[here].second);

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
  }

  cout << go(0, 0) << '\n';

  return 0;
}