// 다시 풀기

#include <bits/stdc++.h>
using namespace std;

int t, n;
string a, b;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  // t가 0이 아닐떄까지 돔
  while (t--) {
    map<string, int> _map;
    cin >> n;

    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      _map[b]++;
    }

    long long ret = 1;
    for (auto c: _map) {
      ret *= ((long long)c.second + 1);
    }
    ret--;
    cout << ret << "\n";
  }

  return 0;
}