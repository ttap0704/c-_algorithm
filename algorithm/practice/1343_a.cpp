#include <bits/stdc++.h>
using namespace std;

string s, ret = "";

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> s;

  int cnt = 0;
  for (char c : s) {
    if (c == '.') {
      if (cnt > 0) {
        if (cnt % 2 != 0) {
          break;
        }

        for (int i = 0; i < cnt / 4; i++) {
          ret += "AAAA";
        }
        cnt %= 4;

        for (int i = 0; i < cnt / 2; i++) {
          ret += "BB";
        }
        cnt = 0;
      }
      ret += c;
    } else cnt++;
  }

  if (cnt % 2 != 0) {
    cout << -1 << '\n';
  } else {
    for (int i = 0; i < cnt / 4; i++) {
      ret += "AAAA";
    }
    cnt %= 4;

    for (int i = 0; i < cnt / 2; i++) {
      ret += "BB";
    }
    cnt = 0;
    cout << ret << '\n';
  }

  return 0;
}