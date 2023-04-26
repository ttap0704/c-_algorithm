#include <bits/stdc++.h>
using namespace std;

int N, num, X, a[100004], cnt = 0;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  cin >> X;

  sort(a, a + N);

  int l = 0, r = N - 1;
  while (l < r) {
    if (a[l] + a[r] == X) {r--; cnt++;}
    else if (a[l] + a[r] > X) r--;
    else if (a[l] + a[r] < X) l++;
  }

  cout << cnt << '\n';

  return 0;
}