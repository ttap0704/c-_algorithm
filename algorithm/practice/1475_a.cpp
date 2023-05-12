#include <bits/stdc++.h>
using namespace std;

int a[10], mx = -1e9;
string s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin.tie(NULL);

  cin >> s;
  for (char c : s) {
    int n = (c - '0');
    if (n == 9 && a[6] < a[9]) {
      n = 6;
    } else if (n == 6 && a[9] < a[6]) {
      n = 9;
    }

    a[n]++;
    mx = max(a[n], mx);
  }

  cout << mx << '\n';

  return 0;
}