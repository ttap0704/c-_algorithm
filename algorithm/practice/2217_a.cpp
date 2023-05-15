#include <bits/stdc++.h>
using namespace std;

int N, a[100004], ret = -1e9;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  sort(a, a + N);
  for (int i = 0; i < N; i++) {
    // cout << "ret : " << a[i] * (N - i) << '\n';
    ret = max(ret, a[i] * (N - i));
  }

  cout << ret << '\n';

  return 0;
}