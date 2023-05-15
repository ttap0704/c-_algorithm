#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, ret, a[500004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> a[i];
  sort(a + 1, a + N + 1);
  for (int i = 1; i <= N; i++) {
    ret += abs(i - a[i]);
  }

  cout << ret << '\n';

  return 0;
}