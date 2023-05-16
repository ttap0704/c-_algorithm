#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, a[100004], ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];
  sort(a, a + N, greater<>());

  for (int i = 0; i < N; i++) {
    if (a[i] - i > 0) ret += a[i] - i;
  }

  cout << ret << '\n';

  return 0;
}