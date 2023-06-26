#include <bits/stdc++.h>
using namespace std;

int N, n;
string s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  stack<int> st;
  cin >> N;
  while (N--) {
    cin >> s;
    if (s == "push") {cin >> n; st.push(n);}
    else if (s == "pop") {if (st.size()) {cout << st.top() << '\n'; st.pop();} else cout << -1 << '\n';}
    else if (s == "empty") {int is_empty = st.size() ? 0 : 1; cout << is_empty << '\n';}
    else if (s == "size") {cout << st.size() << '\n';}
    else if (s == "top") {int st_top = st.size() ? st.top() : -1; cout << st_top << '\n';}
  }

  return 0;
}