// bool
// 0 : false
// 1 : true
// 0이 아닌 다른 int 값은 모두 true(1)

#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int a = -1;
  cout << bool(a) << "\n";

  a = 0;
  cout << bool(a) << "\n";

  a = 3;
  cout << bool(a) << "\n";

  return 0;
}