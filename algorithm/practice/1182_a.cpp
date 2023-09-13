#include <bits/stdc++.h>
using namespace std;

int N, S, a[24], cnt;

void check (int cur, int total) {
  if (cur == N) {
    if (total == S) cnt++;
    return;
  }

  check(cur + 1, total);
  check(cur + 1, total + a[cur]);
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> S;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  check(0, 0);
  if (S == 0) cnt--;

  cout << cnt << '\n';

  return 0;
}