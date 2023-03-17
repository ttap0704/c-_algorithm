// 10988 복습
#include <bits/stdc++.h>
using namespace std;

string s, copy_s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;
  
  copy_s = s;
  reverse(copy_s.begin(), copy_s.end());

  if (copy_s == s) cout << 1 << "\n";
  else cout << 0 << "\n";
  
  return 0;
}