#include <bits/stdc++.h>
using namespace std;

int N, M, a[100004], ret, mx = -1e9;

bool check (int mid) {
  int tmp = mid, cnt = 1;
  for (int i = 0; i < N; i++) {
    if (tmp - a[i] < 0) {
      tmp = mid;
      cnt++;
    }
    tmp -= a[i];
  }

  // cout << "mid : " << mid << '\n';
  // cout << "sum : " << sum << '\n';

  return cnt <= M;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }

  int lo = mx, hi = 1000000004;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    bool check_mid = check(mid);
    if (check_mid) {
      hi = mid - 1;
      ret = mid;
    } else lo = mid + 1;
  }

  cout << ret << '\n';

  return 0;
}