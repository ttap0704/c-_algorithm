#include <bits/stdc++.h>
using namespace std;

int N, n, cnt = 1;
bool flag = 1;
vector<char> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  stack<int> st;

  cin >> N;
  while (N--) {
    cin >> n;
    
    if (!flag) continue;
    while (cnt <= n) {
      v.push_back('+');
      st.push(cnt);
      cnt++;
    }

    if (n == st.top()) {
      st.pop();
      v.push_back('-');
    } else {
      flag = 0;
    }
  }

  if (flag) {
    for (char c : v) cout << c << '\n';
  } else {
    cout << "NO" << '\n';
  }

  return 0;
}