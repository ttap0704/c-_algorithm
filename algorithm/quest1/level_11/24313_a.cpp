#include <bits/stdc++.h>
using namespace std;

int a1, a0, c, n0;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a1 >> a0;
  cin >> c;
  cin >> n0;

  if (((a1 * n0) + a0) <= (c * n0) && (c - a1) >= 0) cout << 1 << '\n';
  else cout << 0 << '\n';

  return 0;
}