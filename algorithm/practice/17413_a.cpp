#include <bits/stdc++.h>
using namespace std;

string s, ret;
deque<char> dq;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  getline(cin, s);
  for (char c : s) {
    dq.push_back(c);

    if (c == ' ' && dq.front() == '<') continue;
    if (c == '>') {
      while(dq.size()) {
        ret += dq.front();
        dq.pop_front();
      }
    } else if (c == ' ') {
      dq.pop_back();
      while(dq.size()) {
        ret += dq.back();
        dq.pop_back();
      }
      ret += ' ';
    } else if (c == '<') {
      dq.pop_back();
      while(dq.size()) {
        ret += dq.back();
        dq.pop_back();
      }
      dq.push_back('<');
    }
  }

  while (dq.size()) {
    ret += dq.back();
    dq.pop_back();
  }

  cout << ret << '\n';

  return 0;
}