#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M, a[10004], mx = -1e9, ret;

bool check (int mid) {
  ll num = 0;
  bool flag = 1;
  for (int i = 0; i < N; i++) {
    num += a[i] > mid ? mid : a[i];
    if (num > M) {
      flag = 0;
      break;
    }
  }

  return flag;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i], mx = max(mx, a[i]);
  cin >> M;

  ll s = 0, e = mx, mid;
  while (s <= e) {
    mid = (s + e) / (2 * 1LL);
    if (check(mid)) {
      ret = mid;
      s = mid + 1;
    } else {
      e = mid - 1;
    }
  }

  cout << ret << '\n';

  return 0;
}