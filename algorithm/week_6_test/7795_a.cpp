#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll T, N, M, a[20004], b[20004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    ll ret = 0;
    cin >> N >> M;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));

    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < M; i++) cin >> b[i];
    
    sort(b, b + M);
    // for (int i = 0; i < M; i++) cout << b[i] << ' ';

    // cout << '\n';
    for (int i = 0; i < N; i++) {
      auto pos = lower_bound(b, b + M, a[i]);
      // cout << a[i] << " : " << (b - pos) * -1 << '\n';
      ret += (b - pos) * -1;
    }

    cout << ret << '\n';
  }

  return 0;
}