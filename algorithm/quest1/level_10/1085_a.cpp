#include <bits/stdc++.h>
using namespace std;

int x, y, w, h, mn = 1001;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> x >> y >> w >> h;

  mn = min(mn, x);
  mn = min(mn, w - x);
  mn = min(mn, y);
  mn = min(mn, h - y);

  cout << mn << '\n';

  return 0;
}