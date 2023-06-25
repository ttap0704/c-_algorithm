#include <bits/stdc++.h>
using namespace std;

int N, K, B, a[100004], n, mx;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fill(a, a + 100004, 1);

  cin >> N >> K >> B;
  for (int i = 0; i < B; i++) {
    cin >> n;
    a[n] = 0;
  }

  for (int i = 1; i <= N; i++) {
    a[i] += a[i - 1];
  }

  for (int i = K; i <= N; i++) {
    mx = max(mx, a[i] - a[i - K]);
  }

  cout << K - mx << '\n';

  return 0;
}