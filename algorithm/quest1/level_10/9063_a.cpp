#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, x, y, mnx = INF, mny = INF, mxx = -INF, mxy = -INF;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x >> y;

    mxx = max(x, mxx);
    mxy = max(y, mxy);
    mnx = min(x, mnx);
    mny = min(y, mny);
  }

  cout << (mxx - mnx) * (mxy - mny) << '\n';

  return 0;
}