#include <bits/stdc++.h>
using namespace std;

string s, b;
stack<char> st;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s >> b;
  for (char c : s){
    st.push(c);

    if (st.size() >= b.size() && st.top() == b.back()) {
      string s2 = "";

      for (char c2 : b) {
        s2 += st.top();
        st.pop();
      }

      reverse(s2.begin(), s2.end());

      if (s2 != b) {
        for (char c2 : s2) {
          st.push(c2);
        }
      }
    }
  }


  if (st.size()) {
    string ret = "";
    while (st.size()) {
      ret += st.top();
      st.pop();
    } 

    reverse(ret.begin(), ret.end());

    cout << ret << '\n';
  } else {
    cout << "FRULA" << '\n';
  }

  return 0;
}