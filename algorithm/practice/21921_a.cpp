#include <bits/stdc++.h>
using namespace std;

int N, X, a[250004], psum[250004], ret, cnt;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> X;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];

    if (i < X) psum[i] = psum[i - 1] + a[i];
    else {
      psum[i] = psum[i - 1] - a[i - X] + a[i];
      if (ret == psum[i]) cnt++;
      else if (ret < psum[i]) {
        cnt = 1;
        ret = psum[i];
      }
    }
  }

  if (ret == 0) cout << "SAD" << '\n';
  else {
    cout << ret << '\n';
    cout << cnt << '\n';
  }

  return 0;
}