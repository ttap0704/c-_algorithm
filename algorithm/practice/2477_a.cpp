#include <bits/stdc++.h>
using namespace std;

int N, a, b, l[1004][1004];
vector<pair<int ,int>> v, v2;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int y = 502, x = 502, mnx = 1005, mxx = 0, mny = 1005, mxy = 0;
  cin >> N;
  for (int i = 0; i < 6; i++) {
    cin >> a >> b;

    if (a == 1) {
      x += b;
    } else if (a == 2) {
      x -= b;
    } else if (a == 3) {
      y += b;
    } else if (a == 4) {
      y -= b;
    }

    mnx = min(mnx, x);
    mxx = max(mxx, x);
    mny = min(mny, y);
    mxy = max(mxy, y);

    v.push_back({y, x});

    l[y][x] = 1;
  }

  int fy = mxy - mny;
  int fx = mxx - mnx;


  int mnx2 = 1005, mxx2 = 0, mny2 = 1005, mxy2 = 0;
  for (pair<int, int> p : v) {
    if ((p.first != mny && p.first != mxy) || (p.second != mnx && p.second != mxx)) {
      mny2 = min(mny2, p.first);
      mxy2 = max(mxy2, p.first);
      mnx2 = min(mnx2, p.second);
      mxx2 = max(mxx2, p.second);
    };
  }

  int fy2 = mxy2 - mny2;
  int fx2 = mxx2 - mnx2;

  cout << (((fy * fx) - (fy2 * fx2)) * N) << '\n';

  return 0;
}