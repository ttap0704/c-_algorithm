#include <bits/stdc++.h>
using namespace std;

string s;
char c1, c2;
int M;
stack<char> l, r;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;
  cin >> M;
  for (char c : s) {
    l.push(c);
  }

  while (M--) {
    cin >> c1;
    if (c1 == 'P') {
      cin >> c2;
      l.push(c2);
    } else {
      if (c1 == 'L' && l.size()) {
        r.push(l.top());
        l.pop();
      } else if (c1 == 'D' && r.size())  {
        l.push(r.top());
        r.pop();
      } else if (c1 == 'B' && l.size()) {
        l.pop();
      }
    }
  }

  while (l.size()) {
    r.push(l.top());
    l.pop();
  }

  while (r.size()) {
    cout << r.top();
    r.pop();
  }
  cout << '\n';

  return 0;
}