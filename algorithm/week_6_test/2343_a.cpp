#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, M, a[100004], sum = 0, ret = 1e18, mx = -1e18;

bool check (ll mid) {
  if (mx > mid) return false;
  ll cnt = 0, tmp = mid;
  for (int i = 0; i < N; i++) {
    if (mid - a[i] < 0) {
      cnt++;
      mid = tmp;
    }
    mid -= a[i];
  }
  if (mid != tmp) cnt++;

  return M >= cnt;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    sum += a[i];
    mx = max(mx, a[i]);
  }

  ll lo = 0, hi = sum, mid;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (check(mid)) {
      ret = min(mid, ret);
      hi = mid - 1;
    } else lo = mid + 1;
  }

  cout << ret << '\n';

  
  return 0;
}