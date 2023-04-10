#include <bits/stdc++.h>
using namespace std;

int N, ret[1000004], a[1000004];
stack<int> st;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  fill(ret, ret + 1000004, -1);
  for (int i = 0; i < N; i++) {
    cin >> a[i];

    while (st.size() && a[st.top()] < a[i]) {
      ret[st.top()] = a[i];
      st.pop();
    }

    st.push(i);
  }

  for (int i = 0; i < N; i++) cout << ret[i] << " ";

  return 0;
}