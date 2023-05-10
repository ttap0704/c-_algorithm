#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll Y, X, Z, ret = -1;

bool check (ll mid) {
  ll y = Y + mid, x = X + mid;
  if ((y * 100) / x > Z) {
    return true;
  } else {
    return false;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> X >> Y;
  Z = ((Y * 100) / X);
  ll lo = 1, hi = 1e12 + 4, mid;

  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (check(mid)) {
      hi = mid - 1;
      ret = mid;
    } else {
      lo = mid + 1;
    }
  }

  cout << ret << '\n';
  

  return 0;
}