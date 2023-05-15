#include <bits/stdc++.h>
using namespace std;

int N, ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  
  int tmp = ceil((double) N / (double) 5);
  if (N >= 5) {
    while (true) {
      int calc = (N - (tmp * 5));
      if (calc >= 0 && calc % 2 == 0) break;
      tmp--;
    }
    ret += tmp;
    N -= (5 * tmp);
  }
  
  
  ret += N / 2;
  N %= 2;

  if (N != 0) cout << -1 << '\n';
  else cout << ret << '\n';

  return 0;
}