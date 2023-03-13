#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string s;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;

  string copy_s = s;
  reverse(s.begin(), s.end());
  if (s == copy_s) cout << 1;
  else cout << 0;
}