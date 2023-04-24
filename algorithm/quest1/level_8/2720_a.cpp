#include <bits/stdc++.h>
using namespace std;

int T, num, a[4] = {25, 10, 5, 1};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> num;

    for (int d : a) {
      cout << num / d << ' ';
      num %= d;
    }
    cout << '\n';
  }

  return 0;
}