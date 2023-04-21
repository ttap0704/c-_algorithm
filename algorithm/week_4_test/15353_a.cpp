#include <bits/stdc++.h>
using namespace std;

string s1, s2, ret;
stack<int> st1, st2;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s1 >> s2;
  if (s1.size() > s2.size()) {
    for (int i = 0; i < s1.size() - s2.size(); i++) {
      st2.push(0);
    }
  } else if (s1.size() < s2.size()) {
    for (int i = 0; i < s2.size() - s1.size(); i++) {
      st1.push(0);
    }
  }

  for (char c : s1) {
    st1.push(c - '0');
  }

  for (char c : s2) {
    st2.push(c - '0');
  }

  int plus_num = 0;
  while (st1.size()) {
    int i1 = st1.top();
    int i2 = st2.top();
    st1.pop();
    st2.pop();

    int sum = (i1 + i2 + plus_num) % 10;
    plus_num = (i1 + i2 + plus_num) / 10;

    ret = to_string(sum) + ret;
  }
  if (plus_num != 0) {
    ret = to_string(plus_num) + ret;
  }

  cout << ret << '\n';

  return 0;
}