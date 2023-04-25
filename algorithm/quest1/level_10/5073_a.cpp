#include <bits/stdc++.h>
using namespace std;

int a[3], mx = -1;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    cin >> a[0] >> a[1] >> a[2];
    if (a[0] == 0 && a[1] == 0 && a[2] == 0) break;

    sort(a, a + 3);

    if (a[2] >= a[0] + a[1]) {
      cout << "Invalid" << '\n';
    } else if (a[0] != a[1] && a[0] != a[2] && a[1] != a[2]) {
      cout << "Scalene" << '\n';
    } else {
      if (a[0] == a[1] && a[0] == a[2]) {
        cout << "Equilateral" << '\n';
      } else {
        cout << "Isosceles" << '\n';
      }
    }
  }

  return 0;
}