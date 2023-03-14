#include <bits/stdc++.h>
using namespace std;

string s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  getline(cin, s, '\n');
  string ret;
  for (int i = 0; i < s.size(); i++) {
    int ascii;
    if (isupper(s[i])) {
      ascii = (s[i] + 13);
      if (ascii > 'Z') {
        ascii -= 26;
      }
      ret += ascii;
    } else if (islower(s[i])) {
      ascii = (s[i] + 13);
      if (ascii > 'z') {
        ascii -= 26;
      }
      ret += ascii;
    } else {
      ret += s[i];
    }
  }

  cout << ret << "\n";

  return 0;
}