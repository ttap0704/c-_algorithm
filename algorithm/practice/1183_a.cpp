#include <bits/stdc++.h>
using namespace std;

int N, a[54], b[54], s[54];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];

    s[i] = a[i] - b[i];
  }

  sort(s, s + N);

  if (N % 2 == 1) cout << 1 << '\n';
  else {
    cout << s[N / 2] - s[N / 2 - 1] + 1 << '\n';
  }

  return 0;
}