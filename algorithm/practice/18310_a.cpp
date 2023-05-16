#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, a[200004], ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];
  sort(a, a + N);

  ret = a[(N - 1) / 2];

  cout << ret << '\n';

  return 0;
}