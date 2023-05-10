#include <bits/stdc++.h>
using namespace std;

int N;
double a[10004], b, ret = -1;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(3);
  cout << fixed;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  b = a[0];
  for (int i = 1; i < N; i++) {
    if (b * a[i] < a[i]) {
      b = a[i];
    } else {
      b *= a[i];
    }
    ret = max(ret, b);
  }

  cout << ret + 0.00001 << '\n';

  return 0;
}