#include <bits/stdc++.h>
using namespace std;

int a, b, ret1 = 0, ret2 = 0;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 3; i++) {
    cin >> a >> b;
    
    ret1 ^= a;
    ret2 ^= b;
  }

  cout << ret1 << ' ' << ret2 << '\n';

  return 0;
}