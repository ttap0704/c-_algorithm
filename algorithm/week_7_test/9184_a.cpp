#include <bits/stdc++.h>
using namespace std;

int a, b, c, store[54][54][54];

int w (int a, int b, int c) {
  if (a <= 0 || b <= 0 || c <= 0) return 1;
  if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);

  int &ret = store[a][b][c];
  if (ret) return ret;

  if (a < b && b < c) {
    ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    return ret;
  } else {
    ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    return ret;
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    cin >> a >> b >> c;
    if (a == -1 && b == -1 && c == -1) break;

    cout << "w(" << a << ", " << b << ", " << c << ") = ";
    cout << w(a, b, c) << '\n';
  }
  

  return 0;
}