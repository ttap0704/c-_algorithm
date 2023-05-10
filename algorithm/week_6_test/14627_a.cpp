#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll S, C, mx2 = -1e9, n, ret, a[1000004], sum;

bool check (ll mid) {
  ll cnt = 0;
  for (int i = 0; i < S; i++) cnt += a[i] / mid;
  return cnt >= C;

}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> S >> C;
  for (int i = 0; i < S; i++) cin >> a[i], sum += a[i];

  ll lo = 1, hi = 1e9;
  while (lo <= hi) {
    ll mid = (lo + hi) / 2;
    if (check(mid)) {
      lo = mid + 1;
      ret = mid;
    } else hi = mid - 1;
  }
  cout << sum - (ret * C) << '\n';

  return 0;
}