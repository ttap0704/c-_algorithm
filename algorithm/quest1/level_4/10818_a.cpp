#include <bits/stdc++.h>
using namespace std;

const int INF1 = 1e9;
const int INF2 = -1e9;
int N, num, mn = INF1, mx = INF2;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num;
    mn = min(mn, num);
    mx = max(mx, num);
  }

  cout << mn << ' ' << mx << '\n';

  return 0;
}