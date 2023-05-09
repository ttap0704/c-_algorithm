#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, M, a[300004], ret = 1e18;

bool check (ll mid) {
  ll num = 0;
  for (int i = 0; i < M; i++) {
    num += a[i] / mid;
    if (a[i] % mid) num++;
  }
  return N >= num;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll lo = 1, hi = 0, mid;
  cin >> N >> M;
  for (int i = 0; i < M; i++) cin >> a[i], hi = max(hi, a[i]);

  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (check(mid)) {
      ret = min(ret, mid);
      hi = mid - 1;
    } else lo = mid + 1;
  }

  cout << ret << '\n';

  return 0;
}