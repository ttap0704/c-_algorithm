#include <bits/stdc++.h>
using namespace std;

int T, N, a[1004], psum[1004];


int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    cin >> N;
    memset(a, 0, sizeof(a));
    memset(psum, 0, sizeof(psum));

    int mx = -1e9;

    for (int i = 1; i <= N; i++) {
      cin >> a[i];

      psum[i] = max(psum[i - 1] + a[i], a[i]);
      mx = max(mx, psum[i]);
    }

    cout << mx << '\n';
  }

  return 0;
}