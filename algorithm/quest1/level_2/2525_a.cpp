#include <bits/stdc++.h>
using namespace std;

int H, M, T, tmp;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> H >> M;
  cin >> T;

  tmp = ((H * 60) + M + T) % 1440;

  cout << (tmp / 60) << ' ' << (tmp % 60) << '\n';


  return 0;
}