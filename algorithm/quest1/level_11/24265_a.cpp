#include <bits/stdc++.h>
using namespace std;

long long n, cnt;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 1; i < n; i++) {
    cnt += i;
  }

  cout << cnt << '\n';
  cout << 2 << '\n';

  return 0;
}