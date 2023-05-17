#include <bits/stdc++.h>
using namespace std;

int N, K, a[10004], psum[10004], ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> a[i];
  sort(a, a + N);

  for (int i = 1; i < N; i++) {
    psum[i] = abs(a[i] - a[i - 1]);
  }
  sort(psum + 1, psum + N);
  for (int i = 1; i < N - K + 1; i++) {
    ret += psum[i];
  }
  
  cout << ret << '\n';

  return 0;
}