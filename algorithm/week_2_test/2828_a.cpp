// 2828 복습 필요!!!!

#include <bits/stdc++.h>
using namespace std;

int N, M, J, ret, l = 1, r;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> J;
  for (int i = 0; i < J; i++) {
    r = l + M - 1;
    int n;
    cin >> n;
    if (n >= l && n <= r) continue;
    else {
      if (n < l) {
        ret += (l - n);
        l = n;
      } else {
        l += (n - r);
        ret += (n - r);
      }
    }
  }

  cout << ret << "\n";

  return 0;
}