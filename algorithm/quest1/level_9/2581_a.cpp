#include <bits/stdc++.h>
using namespace std;

int a, b, sum = 0, mn = 0;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a;
  cin >> b;

  for (int i = a; i <= b; i++) {
    if (i == 1) continue;

    if (i == 2) {
      sum += 2;
      mn = 2;
    } else {
      if (i % 2 == 0) continue;

      int check_num = 2;
      bool flag = 1;

      while (check_num < i) {
        if (i % check_num == 0) {
          flag = 0;
          break;
        }

        if ((i / 2) < check_num) {
          break;
        }
        check_num++;
      }

      if (flag) {
        if (sum == 0) mn = i;
        sum += i;
      }
    }
  }
  if (sum == 0) {
    cout << -1 << '\n';
  } else {
    cout << sum << '\n';
    cout << mn << '\n';
  }

  return 0;
}