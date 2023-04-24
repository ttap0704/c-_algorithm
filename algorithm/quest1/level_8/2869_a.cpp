#include <bits/stdc++.h>
using namespace std;

int a, b, v, sum = 0, i = 1;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b >> v;

  // while (true) {
  //   sum += a;
  //   if (sum >= v) break;
  //   sum -= b;
  //   i++;
  // }

  // v / (a - b);

  // cout << i << '\n';
  cout << ((v / a) + 1) << '\n';

  return 0;
}