#include <bits/stdc++.h>
using namespace std;

int N, K, r[10];
string s, ret = "";

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  cin >> s;

  deque<char> dq;
  for (char c : s) {
    while (dq.size() && K && dq.back() < c) {
      dq.pop_back();
      K--;
    }
    dq.push_back(c);
  }

  for (int i = 0; i < dq.size() - K; i++) {
    ret += dq[i];
  }

  cout << ret << '\n';

  return 0;
}