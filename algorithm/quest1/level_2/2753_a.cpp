#include <bits/stdc++.h>
using namespace std;

int A;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A;

  if ((A % 4 == 0 && A % 100 != 0) || A % 400 == 0) {
    cout << 1 << '\n';
  } else {
    cout << 0 << '\n';
  }
  
  return 0;
}