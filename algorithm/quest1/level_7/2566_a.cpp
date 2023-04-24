#include <bits/stdc++.h>
using namespace std;

int a[9][9], mx = 0;
pair<int, int> p;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> a[i][j];

      mx = max(mx, a[i][j]);
      if (mx == a[i][j]) {
        p = {i + 1, j + 1};
      }
    }
  }

  cout << mx << '\n';
  cout << p.first << ' ' << p.second << '\n';
  return 0;
}