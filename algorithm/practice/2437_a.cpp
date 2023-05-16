#include <bits/stdc++.h>
using namespace std;

int N, a[1004], ret = 1;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];

  sort(a, a + N);

  for (int i = 0; i < N; i++) {
    if (ret < a[i]) break;
    ret += a[i];
  }

  cout << ret << '\n';

  return 0;
}