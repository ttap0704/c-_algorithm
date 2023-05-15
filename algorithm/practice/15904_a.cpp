#include <bits/stdc++.h>
using namespace std;

string s, contents = "UCPC", ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int idx = 0;
  getline(cin, s);
  
  for (char c : s) {
    if (c == contents[idx]) {
      idx++;
    }
    if (idx >= 4) break;
  }

  if (idx >= 4) {
    cout << "I love UCPC" << '\n';
  } else {
    cout << "I hate UCPC" << '\n';
  }

  return 0;
}