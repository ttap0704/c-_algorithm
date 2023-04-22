#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9;
int N = 9, mx = INF, o = 0, num;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 1; i <= N; i++) {
    cin >> num;

    mx = max(mx, num);
    if (mx == num) {
      o = i;
    }
  }

  cout << mx << '\n';
  cout << o << '\n';

  return 0;
}