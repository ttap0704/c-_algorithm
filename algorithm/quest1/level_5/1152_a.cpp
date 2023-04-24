#include <bits/stdc++.h>
using namespace std;

string s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  getline(cin, s);
  int cnt = 0;
  bool check = false;
  for (char c : s) {
    if (c != ' ') {
      check = true;
    }
    
    if (c == ' ') {
      if (check) cnt++;
      check = false;
    }
  }

  if (check) cnt++;

  cout << cnt << '\n';

  return 0;
}