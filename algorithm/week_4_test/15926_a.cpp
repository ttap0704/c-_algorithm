#include <bits/stdc++.h>
using namespace std;

int N, mx = 0, a[200004];
string S;
stack<int> st;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cin >> S;

  int idx = 0;
  for (char c : S) {
    if (c == '(') {
      st.push(idx);
    } else if (st.size()) {
      a[idx] = 1;
      a[st.top()] = 1;
      st.pop();
    }
    idx++;
  }

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (a[i]) {
      cnt++;
      mx = max(mx, cnt);
    } else {
      cnt = 0;
    }
  }

  cout << mx << '\n';

  return 0;
}