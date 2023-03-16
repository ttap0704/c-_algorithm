#include <bits/stdc++.h>
using namespace std;

int n, cnt;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for(int i = 0; i < n; i++) {
    stack<char> chars;

    string s;
    cin >> s;

    for (int j = 0; j < s.size(); j++) {
      if (chars.size() == 0)chars.push(s[j]);
      else {
        if (chars.top() == s[j]) {
          chars.pop();
        } else {
          chars.push(s[j]);
        }
      }
    }

    if (chars.size() == 0) cnt++;
  }

  cout << cnt << "\n";
  return 0;
}
