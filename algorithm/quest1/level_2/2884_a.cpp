#include <bits/stdc++.h>
using namespace std;

int H, M, tmp;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> H >> M;

  tmp = (H * 60) + M - 45;
  if (tmp < 0) {
    tmp += (24 * 60);
  }

  cout << (tmp / 60) << ' ' << (tmp % 60) << '\n';

  return 0;
}