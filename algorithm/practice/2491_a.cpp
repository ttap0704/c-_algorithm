#include <bits/stdc++.h>
using namespace std;

int N, a[100004], ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];

  stack<int> st, st2;
  for (int i = 0; i < N; i++) {
    if (st.size() && st.top() > a[i]) {
      if (ret < st.size()) ret = st.size();
      stack<int> tmp;
      st = tmp;
    }
    if (st2.size() && st2.top() < a[i]) {
      if (ret < st2.size()) ret = st2.size();
      stack<int> tmp;
      st2 = tmp;
    }
        
    st.push(a[i]);
    st2.push(a[i]);
  }
  if (ret < st.size()) ret = st.size();
  if (ret < st2.size()) ret = st2.size();

  cout << ret << '\n';

  return 0;
}