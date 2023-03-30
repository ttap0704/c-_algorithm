#include <bits/stdc++.h>
using namespace std;

int N;
string s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;

    if (s[0] == ')' || s[s.size() - 1] == '(') {
      cout << "NO\n";
    } else {
      stack<char> st;
      for (char c : s) {
        if (st.size()) {
          if (st.top() == '(' && c == ')') {
            st.pop();
          } else {
            st.push(c);
          }
        } else {
          st.push(c);
        }
      }

      if (st.size()) cout << "NO\n";
      else cout << "YES\n";
    }
  }
  
  return 0;
}