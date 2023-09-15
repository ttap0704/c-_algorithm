#include <bits/stdc++.h>
using namespace std;

string s;
stack<char> stc;
stack<int> sti;
int cnt;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];

    if (stc.size() && stc.top() == '(' && c == ')') {
      stc.pop();
      
      if (sti.top() + 1 == i) {
        cnt += stc.size();
      } else {
        cnt++;
      }
      sti.pop();
    } else {
      sti.push(i);
      stc.push(c);
    }
  }

  cout << cnt << '\n';
  
  return 0;
}