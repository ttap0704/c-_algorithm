#include <bits/stdc++.h>
using namespace std;
#define y1 noting

typedef pair<int, int> PI;
vector<int> check_x, check_y;
int N, x, y, x1, y1, x2, y2, _y[1000004], _x[1000004], ret;
PI a[100004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x >> y;
    y += 500000;
    x += 500000;
    a[i] = {x, y};
    check_x.push_back(x);
    check_y.push_back(y);
  }
  a[N] = a[0];
  
  for (int i = 0; i < N; i++) {
    tie(x1, y1) = a[i];
    tie(x2, y2) = a[i + 1];
    if (x1 != x2) {
      if (x1 > x2) swap(x1, x2);
      for (int j = x1 + 1; j <= x2; j++) _x[j]++;
    }

    if (y1 != y2) {
      if (y1 > y2) swap(y1, y2);
      for (int j = y1 + 1; j <= y2; j++) _y[j]++;
    }
  }

  for (int i : check_x) ret = max(ret, _x[i]);
  for (int i : check_y) ret = max(ret, _y[i]);

  cout << ret << '\n';

  return 0;
}