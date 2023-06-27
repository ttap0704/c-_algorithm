#include <bits/stdc++.h>
using namespace std;

int N, n;
string s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  queue<int> q;
  cin >> N;
  while (N--) {
    cin >> s;
    
    if (s == "push") {cin >> n; q.push(n);}
    else if (s == "pop") {if (q.size()) {cout << q.front() << '\n'; q.pop();} else cout << -1 << '\n';}
    else if (s == "size") {cout << q.size() << '\n';}
    else if (s == "empty") {cout << (q.size() ? 0 : 1) << '\n';}
    else if (s == "front") {if (q.size()) {cout << q.front() << '\n';} else cout << -1 << '\n';}
    else if (s == "back") {if (q.size()) {cout << q.back() << '\n';} else cout << -1 << '\n';}
  }
  
  return 0;
}