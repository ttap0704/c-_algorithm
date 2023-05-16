#include <bits/stdc++.h>
using namespace std;

int N, ret, a[100004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];

  sort(a, a + N);
  for (int i = N - 1; i >= 0; i -= 3) {
    if (i >= 2) {
      ret += a[i];
      ret += a[i - 1];
    } else {
      int tmp = i;
      while (tmp >= 0) {
        ret += a[tmp];
        tmp--;
      }
    }
  }

  cout << ret << '\n';

  return 0;
}