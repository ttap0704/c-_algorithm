#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N, M, w, x, y, xx, yy, n, a[1030][1030];
ll tree[1030][1030];

ll sum (int i, int j) {
  ll ret = 0;
  while (i > 0) {
    int x = j;
    while (x > 0) {
      ret += tree[i][x];
      x -= (x & -x);
    }
    i -= (i & -i);
  }

  return ret;
}

void update (int i, int j, ll val) {
  while (i <= N) {
    int x = j;
    while (x <= N) {
      tree[i][x] += val;
      x += (x & -x);
    }
    i += (i & -i);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> a[i][j];
      update(i, j, a[i][j]);
    }
  }

  for (int i = 0; i < M; i++) {
    cin >> w;
    if (w == 1) {
      cin >> y >> x >> yy >> xx;

      cout << sum(yy, xx) - sum(y - 1, xx) - sum(yy, x - 1) + sum(y - 1, x - 1) << '\n';
    } else {
      cin >> x >> y >> n;
      update(x, y, n - a[x][y]);
      a[x][y] = n;
    }
  }

  return 0;
}