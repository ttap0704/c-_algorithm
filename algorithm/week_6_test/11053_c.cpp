#include <bits/stdc++.h>
using namespace std;

int N, n, lis[1004], ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> n;

    auto pos = lower_bound(lis, lis + ret, n);
    if (*pos == 0) ret++;
    *pos = n;
  }

  cout << ret << '\n';

  return 0;
}