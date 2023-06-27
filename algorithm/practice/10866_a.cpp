#include <bits/stdc++.h>
using namespace std;

int N, n;
string s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  deque<int> dq;
  cin >> N;
  while (N--) {
    cin >> s;

    if (s == "push_back") {
      cin >> n;
      dq.push_back(n);
    } else if (s == "push_front") {
      cin >> n;
      dq.push_front(n);
    } else if (s == "pop_front") {
      if (dq.size()) {
        cout << dq.front() << '\n';
        dq.pop_front();
      } else cout << -1 << '\n';
    } else if (s == "pop_back") {
      if (dq.size()) {
        cout << dq.back() << '\n';
        dq.pop_back();
      } else cout << -1 << '\n';
    } else if (s == "size") {
      cout << dq.size() << '\n';
    } else if (s == "empty") {
      cout << dq.empty() << '\n';
    } else if (s == "front") {
      if (dq.size()) {
        cout << dq.front() << '\n';
      } else cout << -1 << '\n';
    } else if (s == "back") {
      if (dq.size()) {
        cout << dq.back() << '\n';
      } else cout << -1 << '\n';
    }
  }

  return 0;
}