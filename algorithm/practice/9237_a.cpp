#include <bits/stdc++.h>
using namespace std;

int N, a[100004], mx = 0;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];
  sort(a, a + N);
  for (int i = 0; i < N; i++) {
    a[i] += (N - i);
    mx = max(mx, a[i]);
  }

  cout << mx + 1 << '\n';

  return 0;
}