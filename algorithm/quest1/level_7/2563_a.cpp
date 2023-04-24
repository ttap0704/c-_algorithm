#include <bits/stdc++.h>
using namespace std;

int a[104][104], N, y, x, cnt = 0;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int t = 0; t < N; t++) {
    cin >> y >> x;


    for (int i = y; i < y + 10; i++) {
      for (int j = x; j < x + 10; j++) {
        if (a[i][j] == 0) {
          a[i][j] = 1;
          cnt++;
        }
      }
    }
  }

  cout << cnt << '\n';

  return 0;
}