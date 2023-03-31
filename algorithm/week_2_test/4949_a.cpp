#include <bits/stdc++.h>
using namespace std;
string s;

bool checkChar(char c) {
  if ((65 <= c && 90 >= c) || (97 <= c && 122 >= c) || c == 32) return true;
  else return false;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    getline(cin, s);

    if (s == ".") break;

    if (s[s.size() - 1] != '.') {
      cout << "no\n";
      continue;
    } else {
      stack<char> st;
      s.erase(s.size() - 1, 1);
      for (char c : s) {
        if (c == '(' || c == ')' || c == '[' || c == ']') {
          if (st.size()) {
            if (c == ')' && st.top() == '(') {
              st.pop();
            } else if (c == ']' && st.top() == '[') {
              st.pop();
            } else {
              st.push(c);
            }
          } else {
            st.push(c);
          }
        } else {
          if (!checkChar(c)) {
            cout << "no\n";
            break;
          }
        }
      }

      if (st.size()) cout << "no\n";
      else cout << "yes\n";
    }
  }
  return 0;
}