#include <bits/stdc++.h>
using namespace std;

int cnt[2];
string s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;
  char cur = '2';
  for (char c : s) {
    if (cur != c && c != '2') {
      cnt[c - '0']++;
      cur = c;
    }
  }

  cout << min(cnt[0], cnt[1]) << '\n';

  return 0;
}