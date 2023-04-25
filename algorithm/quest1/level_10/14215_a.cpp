#include <bits/stdc++.h>
using namespace std;
int a[3];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a[0] >> a[1] >> a[2];

  sort(a, a + 3);

  while (true) {
    if (a[0] == a[1] && a[0] == a[2]) break;

    if (a[2] < a[0] + a[1]) {
      break;
    }

    a[2]--;
  }

  cout << a[0] + a[1] + a[2] << '\n';

  return 0;
}