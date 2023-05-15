#include <bits/stdc++.h>
using namespace std;

int N, M, ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  if (N == 1) ret = 1;
  else if (N == 2) ret = min(4, (M - 1) / 2 + 1);
  else {
    if (M >= 7) ret = M - 2;
    else ret = min(4, M);
  }

  cout << ret << '\n';

  return 0;
}