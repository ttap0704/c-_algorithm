#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string s;
ll ret;
vector<pair<ll, ll>> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  stack<char> st;
  cin >> s;
  int idx = 0, last_idx = -1;
  for (char c : s) {
    if (st.size() && ((st.top() == '(' && c == ')') || (st.top() == '[' && c == ']'))) {
      st.pop();

        
      if (v.back().second > last_idx) {
        ret += v.back().first;
        last_idx = v.back().second;
      }
      if (st.size()) {
        v.pop_back();
      } else {
        v.clear();
        last_idx = -1;
      }
    } else {
      int num = c == '(' ? 2 : 3;
      if (v.size() == 0) {
        v.push_back({num, idx});
      } else {
        v.push_back({v.back().first * num, idx});
      }
      
      idx++;
      st.push(c);
    }
  }

  if (st.size()) {
    cout << 0 << '\n';
  } else {
    cout << ret << '\n';
  }  

  return 0;
}